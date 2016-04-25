//
//  BBChainRequest.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBBaseRequest.h"

@class BBChainRequest;
@protocol BBChainRequestDelegate <NSObject>

@optional

- (void)chainRequestFinished:(BBChainRequest *)chainRequest;

- (void)chainRequestFailed:(BBChainRequest *)chainRequest failedBaseRequest:(BBBaseRequest*)request;

@end

typedef void (^ChainCallback)(BBChainRequest *chainRequest, BBBaseRequest *baseRequest);

@interface BBChainRequest : NSObject


@property (weak, nonatomic) id<BBChainRequestDelegate> delegate;

@property (nonatomic, strong) NSMutableArray *requestAccessories;

/// start chain request
- (void)start;

/// stop chain request
- (void)stop;

- (void)addRequest:(BBBaseRequest *)request callback:(ChainCallback)callback;

- (NSArray *)requestArray;

/// Request Accessory，可以hook Request的start和stop
- (void)addAccessory:(id<BBRequestAccessory>)accessory;
@end

