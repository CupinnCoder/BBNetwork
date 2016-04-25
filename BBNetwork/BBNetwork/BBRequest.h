//
//  BBRequest.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BBRequestProtocol.h"
@interface BBRequest : BBBaseRequest<BBRequestProtocol>

@property (nonatomic) BOOL ignoreCache;

/**
 *  返回当前缓存的对象
 */
- (id)cacheResponseObject;

/**
 *  是否当前的数据从缓存获得
 *
 *  @return BOOL
 */
- (BOOL)isDataFromCache;

/**
 *  返回是否当前缓存需要更新
 *
 *  @return BOOL
 */
- (BOOL)isCacheVersionExpired;

/**
 *  强制更新缓存
 */
- (void)startWithoutCache;

/**
 *  手动将其他请求的responseObject写入该请求的缓存
 *
 *  @param responseObject
 */
- (void)saveResponseObjectToCacheFile:(id)responseObject;

/// For subclass to overwrite

- (NSInteger)cacheTimeInSeconds;
- (long long)cacheVersion;
- (id)cacheSensitiveData;

@end
