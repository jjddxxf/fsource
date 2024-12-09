//
//  TYUUID.h
//  GMFramework
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define KTYUDeviceFirstRegist @"ty_sdk_c_device_register"

@interface TYUUID : NSObject
// 获取或创建 md5-UUID
+ (NSString *)createOrGetUUID;
// 是否越狱
+ (BOOL)xy_isJailBreak;
// mac地址
+ (NSString *)xy_macAddress;
// 是否已加载deviceid，如果已经加载，直接返回
+ (NSString *)xy_hasDeviceId;
// 清除deviceid
+ (BOOL)xy_clearDeviceId;
// 设备id
+ (NSString *)xy_deviceId;
// 设备UUID
+ (NSString *)xy_uuid;
// 设备名字
+ (NSString *)deviceName;
// 设备Machine
+ (NSString *)xy_phoneMachine;
// 设备Model
+ (NSString *)xy_phoneModel;
// 设备启动时间
+ (NSString *)bootTimeInSec;
// 设备内存容量
+ (NSString *)memory;
// 设备硬盘容量
+ (NSString *)disk;
// cpu类型
+ (NSString *)cpuType;
// cpu核数
+ (NSString *)cpuCores;
// 系统名字
+ (NSString *)xy_osName;
// 系统版本
+ (NSString *)xy_osVersion;
// 系统更新时间
+(NSString *)sysFileTime;
// 国家
+ (NSString *)countryCode;
// 语言
+ (NSString *)language;
// 时区
+ (NSString *)timeZone;
// 运营商名字
+ (NSString *)xy_carrierName;
// 运营商代码
+ (NSNumber *)xy_carrierNumber;
// caid mntid
+ (NSString *)mntid;
// 设备初始化时间
+ (NSString *)fileInitTime;
// 传递给CAID的设备名字
+ (NSString *)deviceNameForCAID;

+ (UIViewController *)currentRootViewController;

+ (UIViewController *)currentTopViewController;

+ (NSString *)getIDFANotRequest;
+ (BOOL)trackingRefuseed;
+ (BOOL)trackingEnabled;
@end
