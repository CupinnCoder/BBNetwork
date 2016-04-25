//
//  BBBatchRequestAgent.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBBatchRequest.h"

@interface BBBatchRequestAgent : NSObject

+ (BBBatchRequestAgent *)sharedInstance;

- (void)addBatchRequest:(BBBatchRequest *)request;

- (void)removeBatchRequest:(BBBatchRequest *)request;

@end
