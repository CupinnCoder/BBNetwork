//
//  BBBatchRequest.m
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import "BBBatchRequest.h"
#import "BBNetworkPrivate.h"
#import "BBBatchRequestAgent.h"

@interface BBBatchRequest() <BBRequestDelegate>

@property (nonatomic) NSInteger finishedCount;

@end


@implementation BBBatchRequest

- (id)initWithRequestArray:(NSArray *)requestArray {
    self = [super init];
    if (self) {
        _requestArray = [requestArray copy];
        _finishedCount = 0;
        for (BBRequest * req in _requestArray) {
            if (![req isKindOfClass:[BBRequest class]]) {
                BBNLog(@"Error, request item must be BBRequest instance.");
                return nil;
            }
        }
    }
    return self;
}

- (void)start {
    if (_finishedCount > 0) {
        BBNLog(@"Error! Batch request has already started.");
        return;
    }
    [[BBBatchRequestAgent sharedInstance] addBatchRequest:self];
    [self toggleAccessoriesWillStartCallBack];
    for (BBRequest * req in _requestArray) {
        req.delegate = self;
        [req start];
    }
}

- (void)stop {
    [self toggleAccessoriesWillStopCallBack];
    _delegate = nil;
    [self clearRequest];
    [self toggleAccessoriesDidStopCallBack];
    [[BBBatchRequestAgent sharedInstance] removeBatchRequest:self];
}

- (void)startWithCompletionBlockWithSuccess:(void (^)(BBBatchRequest *batchRequest))success
                                    failure:(void (^)(BBBatchRequest *batchRequest))failure {
    [self setCompletionBlockWithSuccess:success failure:failure];
    [self start];
}

- (void)setCompletionBlockWithSuccess:(void (^)(BBBatchRequest *batchRequest))success
                              failure:(void (^)(BBBatchRequest *batchRequest))failure {
    self.successCompletionBlock = success;
    self.failureCompletionBlock = failure;
}

- (void)clearCompletionBlock {
    // nil out to break the retain cycle.
    self.successCompletionBlock = nil;
    self.failureCompletionBlock = nil;
}

- (BOOL)isDataFromCache {
    BOOL result = YES;
    for (BBRequest *request in _requestArray) {
        if (!request.isDataFromCache) {
            result = NO;
        }
    }
    return result;
}


- (void)dealloc {
    [self clearRequest];
}

#pragma mark - Network Request Delegate

- (void)requestFinished:(BBRequest *)request {
    _finishedCount++;
    if (_finishedCount == _requestArray.count) {
        [self toggleAccessoriesWillStopCallBack];
        if ([_delegate respondsToSelector:@selector(batchRequestFinished:)]) {
            [_delegate batchRequestFinished:self];
        }
        if (_successCompletionBlock) {
            _successCompletionBlock(self);
        }
        [self clearCompletionBlock];
        [self toggleAccessoriesDidStopCallBack];
        [[BBBatchRequestAgent sharedInstance] removeBatchRequest:self];
    }
}

- (void)requestFailed:(BBRequest *)request {
    [self toggleAccessoriesWillStopCallBack];
    // Stop
    for (BBRequest *req in _requestArray) {
        [req stop];
    }
    // Callback
    if ([_delegate respondsToSelector:@selector(batchRequestFailed:)]) {
        [_delegate batchRequestFailed:self];
    }
    if (_failureCompletionBlock) {
        _failureCompletionBlock(self);
    }
    // Clear
    [self clearCompletionBlock];
    
    [self toggleAccessoriesDidStopCallBack];
    [[BBBatchRequestAgent sharedInstance] removeBatchRequest:self];
}

- (void)clearRequest {
    for (BBRequest * req in _requestArray) {
        [req stop];
    }
    [self clearCompletionBlock];
}

#pragma mark - Request Accessoies

- (void)addAccessory:(id<BBRequestAccessory>)accessory {
    if (!self.requestAccessories) {
        self.requestAccessories = [NSMutableArray array];
    }
    [self.requestAccessories addObject:accessory];
}

@end
