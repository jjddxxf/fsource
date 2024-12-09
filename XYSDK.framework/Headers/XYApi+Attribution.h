//
//  XYApi+Attribution.h
//  XYSDK
//
//  Created by 曾伟 on 2024/4/18.
//  Copyright © 2024 tuyoo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XYSDK/XYSDK.h>

NS_ASSUME_NONNULL_BEGIN


@interface XYApi (Attribution)

/**
 *  @brief 为 Firebase 设置额外的参数。
 *
 *  @param firebaseParameters 要设置的 Firebase 参数。
 */
+ (void)setAdditionalDataForFirebase:(NSDictionary *)firebaseParameters;

/**
 *  @brief 为 Appsflyer 设置额外的参数。
 *
 *  @param appsFlyerParameters 要设置的 Appsflyer 参数。
 */
+ (void)setAdditionalDataForAppfflyer:(NSDictionary *)appsFlyerParameters;

/**
 *  @brief 使用 Appsflyer 跟踪事件。
 *
 *  @param event 事件名称。
 *  @param params 事件参数。
 */
+ (void)trackEventWithEventNameByAppsFlyer:(NSString *)event withParameters:(NSDictionary *)params;

/**
 *  @brief 使用 Firebase 跟踪事件。
 *
 *  @param event 事件名称。
 *  @param params 事件参数。
 */
+ (void)trackEventWithEventNameByFirebase:(NSString *)event withParameters:(NSDictionary *)params;

/**
 *  @brief 获取 Appsflyer 设备 ID。
 *
 *  @return Appsflyer 设备 ID。
 */
+ (NSString *)getAppsFlyerDeviceId;

+ (void)XYTrackingWaitATTTimeoutInterval:(NSInteger) timeoutInterval;

/**
 *  @brief 初始化第三方 SDK。
 */
+ (void)initThird;


@end

NS_ASSUME_NONNULL_END
