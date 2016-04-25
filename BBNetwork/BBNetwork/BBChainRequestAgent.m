//
//  BBChainRequestAgent.m
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import "BBChainRequestAgent.h"


@interface BBChainRequestAgent()

@property (strong, nonatomic) NSMutableArray *requestArray;

@end

@implementation BBChainRequestAgent

+ (BBChainRequestAgent *)sharedInstance {
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

- (void)addChainRequest:(BBChainRequest *)request {
    @synchronized(self) {
        [_requestArray addObject:request];
    }
}

- (void)removeChainRequest:(BBChainRequest *)request {
    @synchronized(self) {
        [_requestArray removeObject:request];
    }
}


@end
