//
//  BBChainRequestAgent.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBChainRequest.h"

@interface BBChainRequestAgent : NSObject

+ (BBChainRequestAgent *)sharedInstance;

- (void)addChainRequest:(BBChainRequest *)request;

- (void)removeChainRequest:(BBChainRequest *)request;

@end

