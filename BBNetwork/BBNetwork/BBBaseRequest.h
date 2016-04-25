//
//  BBBaseRequest.h
//  BBNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>

#define UnavailableMacro(msg) __attribute__((unavailable(msg)))

typedef NS_ENUM(NSInteger , BBRequestMethod) {
    BBRequestMethodGet = 0,
    BBRequestMethodPost,
    BBRequestMethodHead,
    BBRequestMethodPut,
    BBRequestMethodDelete,
    BBRequestMethodPatch
};

typedef NS_ENUM(NSInteger , BBRequestSerializerType) {
    BBRequestSerializerTypeHTTP = 0,
    BBRequestSerializerTypeJSON,
    BBRequestSerializerTypeMsgPack
};


/// error code kBBNetworkErrorCode

/**
 *  未知错误
 */
extern NSInteger const kBBNetworkErrorCodeUnknown;
/**
 *  网络异常
 */
extern NSInteger const kBBNetworkErrorCodeHTTP;
/**
 *  接口错误
 */
extern NSInteger const kBBNetworkErrorCodeAPI;

extern NSString *const kBBNetworkErrorDomain;

typedef void (^AFConstructingBlock)(id<AFMultipartFormData> formData);

@class BBBaseRequest;

typedef void(^BBRequestCompletionBlock)(__kindof BBBaseRequest *request);

@protocol BBRequestDelegate <NSObject>

@optional

- (void)requestFinished:(BBBaseRequest *)request;
- (void)requestFailed:(BBBaseRequest *)request;
- (void)clearRequest;

@end

@protocol BBRequestAccessory <NSObject>

@optional

- (void)requestWillStart:(id)request;
- (void)requestWillStop:(id)request;
- (void)requestDidStop:(id)request;

@end

@interface BBBaseRequest : NSObject

/// Tag
@property (nonatomic) NSInteger tag;

/// User info
@property (nonatomic, strong) NSDictionary *userInfo;

@property (nonatomic, strong) NSURLSessionDataTask *sessionDataTask;

@property (nonatomic, strong) id responseObject;

@property (nonatomic, strong) NSError *error;

/// request delegate object
@property (nonatomic, weak) id<BBRequestDelegate> delegate;

@property (nonatomic, strong, readonly) NSHTTPURLResponse *response;

@property (nonatomic, strong, readonly) NSDictionary *responseHeaders;

@property (nonatomic, readonly) NSInteger responseStatusCode;

@property (nonatomic, copy) BBRequestCompletionBlock successCompletionBlock;

@property (nonatomic, copy) BBRequestCompletionBlock failureCompletionBlock;

@property (nonatomic, strong) NSMutableArray *requestAccessories;

/// append self to request queue
- (void)start;

/// remove self from request queue
- (void)stop;

- (BOOL)isExecuting;

/// block回调
- (void)startWithCompletionBlockWithSuccess:(BBRequestCompletionBlock)success
                                    failure:(BBRequestCompletionBlock)failure;

- (void)setCompletionBlockWithSuccess:(BBRequestCompletionBlock)success
                              failure:(BBRequestCompletionBlock)failure;

/// 把block置nil来打破循环引用
- (void)clearCompletionBlock;

/// Request Accessory，可以hook Request的start和stop
- (void)addAccessory:(id<BBRequestAccessory>)accessory;

/// 以下方法由子类继承来覆盖默认值

/**
 *  请求成功的回调
 */
- (void)requestCompleteFilter;

/**
 *  请求失败的回调
 */
- (void)requestFailedFilter;

/**
 *  请求的URL
 *
 *  @return requestUrl
 */
- (NSString *)requestUrl;
/**
 *  请求的CDNURL
 *
 *  @return cdnUrl
 */
- (NSString *)cdnUrl;

/**
 *  请求的BaseURL
 *
 *  @return baseUrl
 */
- (NSString *)baseUrl;

/**
 *  请求的连接超时时间，默认为60秒
 *
 *  @return NSTimeInterval
 */
- (NSTimeInterval)requestTimeoutInterval;

/**
 *  请求的参数列表
 *
 *  @return requestArgument
 */
- (id)requestArgument;

/**
 *  用于在cache结果，计算cache文件名时，忽略掉一些指定的参数
 *
 *  @param argument
 *
 *  @return
 */
- (id)cacheFileNameFilterForRequestArgument:(id)argument;

/**
 *  Http请求的方法
 *
 *  @return @See BBRequestMethod
 */
- (BBRequestMethod)requestMethod;

/**
 *  请求的SerializerType
 *
 *  @return @See BBRequestSerializerType
 */
- (BBRequestSerializerType)requestSerializerType;

/**
 *  请求的Server用户名和密码
 *
 *  @return
 */
- (NSArray *)requestAuthorizationHeaderFieldArray;

/**
 *  在HTTP报头添加的自定义参数
 *
 *  @return NSDictionary
 */
- (NSDictionary *)requestHeaderFieldValueDictionary;

/**
 *  是否使用CDN的host地址
 *
 *  @return
 */
- (BOOL)useCDN;

/**
 *  用于检查JSON是否合法的对象
 *
 *  @return NSDictionary
 */
- (id)jsonValidator;

/**
 *  用于检查Status Code是否正常的方法
 *
 *  @return
 */
- (BOOL)statusCodeValidator;

/**
 *  当POST的内容带有文件等富文本时使用
 *
 *  @return @See AFConstructingBlock
 */
- (AFConstructingBlock)constructingBodyBlock;

/**
 *  当需要断点续传时，指定续传的地址
 *
 *  @return
 */
- (NSString *)resumableDownloadPath;


@end
