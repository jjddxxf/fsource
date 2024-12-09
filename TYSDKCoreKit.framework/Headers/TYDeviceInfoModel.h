//  TYDeviceInfoModel.h
//  TYSDKCoreKit
//
//  Created by hui on 2021/3/24.
//  Copyright © 2021 周翔宇. All rights reserved.
//

#import <Foundation/Foundation.h>

#define k_macParamUseNiCai 1
NS_ASSUME_NONNULL_BEGIN

@interface TYDeviceInfoModel : NSObject

@property (nonatomic, copy) NSString *idfa;
@property (nonatomic, copy) NSString *packageName;
@property (nonatomic, copy) NSString *appVersion;
@property (nonatomic, copy) NSString *UUID;
@property (nonatomic, copy) NSString *macAddress;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, assign) NSNumber *carrier; //运营商
@property (nonatomic, assign) BOOL isJailBreak;   //是否越狱
@property (nonatomic, copy) NSString *idfv;

/// 获取设备信息相关参数
- (NSDictionary *)getDeviceParameters;

@end

NS_ASSUME_NONNULL_END
