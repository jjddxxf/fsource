//
//  TYHttpHandle.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYNetworking.h"
#import "TYGetUA.h"
#import "TYEncrypt.h"

NS_ASSUME_NONNULL_BEGIN

static TYHTTPSessionManager *_httpManager;

@interface TYHttpHandle : NSObject



#pragma mark ---旧版网络框架
//缺点： 不同SDK使用corekit的网络库时， URL为同一份变量， 不能满足不同SDK不同baseURL的需求

+ (TYHTTPSessionManager *)resetServerUrl:(NSString *)url;


+ (NSString *)baseUrl;

+ (NSURLSessionDataTask *)md5RequestWithUrl:(NSString *)url
                              parameters:(id)parameters
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

+ (NSURLSessionDataTask *)requestWithUrl:(NSString *)url
                              parameters:(id)parameters
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

+ (NSURLSessionDataTask *)requestWithUrl:(NSString *)url
                              parameters:(id)parameters
                      responseSerializer:(TYHTTPResponseSerializer *)responseSerializer
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                 failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

+ (NSURLSessionDataTask *)normalRequestWithUrl:(NSString *)url
            parameters:(id)parameters
               success:(void (^)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                       failure:(void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

+ (NSURLSessionDataTask *)normalRequestWithUrl:(NSString *)url
                              parameters:(id)parameters
                      responseSerializer:(TYHTTPResponseSerializer *)responseSerializer
                                 success:(void (^_Nullable)(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject))success
                                       failure:(void (^_Nullable)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error))failure;

NS_ASSUME_NONNULL_END
@end
