//
//  TYHttpManager.h
//  TYSDKCoreKit
//
//  Created by 史良 on 2021/6/15.
//  Copyright © 2021 周翔宇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYNetworking.h"
#import "TYGetUA.h"
#import "TYEncrypt.h"

NS_ASSUME_NONNULL_BEGIN

/** 请求类型 */
typedef NS_ENUM(NSUInteger, TYRequestType) {
    Get  = 0,        /**< Get */
    Post = 1,        /**< Post */
};

@interface TYHttpManager : NSObject

#pragma mark - 更新网络框架

//每个网络工具对象可以持有不同的URL地址
@property (nonatomic, copy) NSString * serverUrlStr;
@property (nonatomic, strong) TYHTTPSessionManager * httpManager;


/// 创建一个新的网络handle
+ (TYHttpManager *)createHandleWithUrl:(NSString *)serverUrl;

- (NSURLSessionDataTask *)md5RequestWithUrl:(NSString *)url
                              parameters:(id)parameters
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

- (NSURLSessionDataTask *)requestWithUrl:(NSString *)url
                              parameters:(id)parameters
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

- (NSURLSessionDataTask *)requestWithUrl:(NSString *)url
                              parameters:(id)parameters
                      responseSerializer:(TYHTTPResponseSerializer *)responseSerializer
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

- (NSURLSessionDataTask *)normalRequestWithUrl:(NSString *)url
            parameters:(id)parameters
               success:(void (^)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                       failure:(void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

- (NSURLSessionDataTask *)normalRequestWithUrl:(NSString *)url
                              parameters:(id)parameters
                      responseSerializer:(TYHTTPResponseSerializer *)responseSerializer
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                       failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;




- (NSURLSessionDataTask *)getInfoWithUrl:(NSString *)url
                              parameters:(id)parameters
                                 success:(void (^)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                    failure:(void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

/// 网络请求
/// @param type 请求类型
/// @param headers 请求头参数
/// @param parameters 请求体类型
- (NSURLSessionDataTask *)requestWithUrl:(NSString *)url
                                    type:(TYRequestType)type
                                 headers:(id)headers
                              parameters:(id)parameters
                      responseSerializer:(TYHTTPResponseSerializer *)responseSerializer
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

@end

NS_ASSUME_NONNULL_END
