//
//  BBNetworkConfig.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBBaseRequest.h"

@protocol BBUrlFilterProtocol <NSObject>
- (NSString *)filterUrl:(NSString *)originUrl withRequest:(BBBaseRequest *)request;
@end

@protocol BBCacheDirPathFilterProtocol <NSObject>
- (NSString *)filterCacheDirPath:(NSString *)originPath withRequest:(BBBaseRequest *)request;
@end

@interface BBNetworkConfig : NSObject

+ (BBNetworkConfig *)sharedInstance;

@property (strong, nonatomic) NSString *baseUrl;
@property (strong, nonatomic) NSString *cdnUrl;
@property (strong, nonatomic) NSDictionary *requestHeaderFieldValueDictionary;
@property (strong, nonatomic, readonly) NSArray *urlFilters;
@property (strong, nonatomic, readonly) NSArray *cacheDirPathFilters;
@property (strong, nonatomic) AFSecurityPolicy *securityPolicy;

- (void)addUrlFilter:(id<BBUrlFilterProtocol>)filter;
- (void)addCacheDirPathFilter:(id <BBCacheDirPathFilterProtocol>)filter;

@end
