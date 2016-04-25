//
//  BBBatchRequest.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBRequest.h"

@class BBBatchRequest;
@protocol BBBatchRequestDelegate <NSObject>

@optional

- (void)batchRequestFinished:(BBBatchRequest *)batchRequest;

- (void)batchRequestFailed:(BBBatchRequest *)batchRequest;

@end

@interface BBBatchRequest : NSObject

@property (strong, nonatomic, readonly) NSArray *requestArray;

@property (weak, nonatomic) id<BBBatchRequestDelegate> delegate;

@property (nonatomic, copy) void (^successCompletionBlock)(BBBatchRequest *);

@property (nonatomic, copy) void (^failureCompletionBlock)(BBBatchRequest *);

@property (nonatomic) NSInteger tag;

@property (nonatomic, strong) NSMutableArray *requestAccessories;

- (id)initWithRequestArray:(NSArray *)requestArray;

- (void)start;

- (void)stop;

/// block回调
- (void)startWithCompletionBlockWithSuccess:(void (^)(BBBatchRequest *batchRequest))success
                                    failure:(void (^)(BBBatchRequest *batchRequest))failure;

- (void)setCompletionBlockWithSuccess:(void (^)(BBBatchRequest *batchRequest))success
                              failure:(void (^)(BBBatchRequest *batchRequest))failure;

/**
 *  把block置nil来打破循环引用
 */
- (void)clearCompletionBlock;

/**
 *  Request Accessory，可以hook Request的start和stop
 *
 *  @param accessory
 */
- (void)addAccessory:(id<BBRequestAccessory>)accessory;

/**
 *  是否当前的数据从缓存获得
 *
 *  @return
 */
- (BOOL)isDataFromCache;

@end
