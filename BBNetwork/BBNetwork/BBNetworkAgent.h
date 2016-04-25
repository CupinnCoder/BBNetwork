//
//  BBNetworkAgent.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBBaseRequest.h"

@interface BBNetworkAgent : NSObject

+ (BBNetworkAgent *)sharedInstance;

- (void)addRequest:(BBBaseRequest *)request;

- (void)cancelRequest:(BBBaseRequest *)request;

- (void)cancelAllRequests;

/**
 *  根据request和networkConfig构建url
 *
 *  @param request
 *
 *  @return
 */
- (NSString *)buildRequestUrl:(BBBaseRequest *)request;

@end
