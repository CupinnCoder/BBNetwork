//
//  BBBatchRequestAgent.m
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import "BBBatchRequestAgent.h"

@interface BBBatchRequestAgent()

@property (strong, nonatomic) NSMutableArray *requestArray;

@end

@implementation BBBatchRequestAgent

+ (BBBatchRequestAgent *)sharedInstance {
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}


- (id)init {
    self = [super init];
    if (self) {
        _requestArray = [NSMutableArray array];
    }
    return self;
}

- (void)addBatchRequest:(BBBatchRequest *)request {
    @synchronized(self) {
        [_requestArray addObject:request];
    }
}

- (void)removeBatchRequest:(BBBatchRequest *)request {
    @synchronized(self) {
        [_requestArray removeObject:request];
    }
}


@end

