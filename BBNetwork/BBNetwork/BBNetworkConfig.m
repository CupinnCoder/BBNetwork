//
//  BBNetworkConfig.m
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import "BBNetworkConfig.h"


@implementation BBNetworkConfig {
    NSMutableArray *_urlFilters;
    NSMutableArray *_cacheDirPathFilters;
}

+ (BBNetworkConfig *)sharedInstance {
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
        _urlFilters = [NSMutableArray array];
        _cacheDirPathFilters = [NSMutableArray array];
        _securityPolicy = [AFSecurityPolicy defaultPolicy];
    }
    return self;
}

- (void)addUrlFilter:(id<BBUrlFilterProtocol>)filter {
    [_urlFilters addObject:filter];
}

- (void)addCacheDirPathFilter:(id<BBCacheDirPathFilterProtocol>)filter {
    [_cacheDirPathFilters addObject:filter];
}

- (NSArray *)urlFilters {
    return [_urlFilters copy];
}

- (NSArray *)cacheDirPathFilters {
    return [_cacheDirPathFilters copy];
}

@end