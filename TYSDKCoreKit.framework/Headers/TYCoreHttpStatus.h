//
//  TYCoreHttpStatus.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYReachability.h"

typedef NS_ENUM(NSUInteger,TYCoreHttpType){
    TYCoreHttpType_NotReachable = 1,
    TYCoreHttpType_wifi,
    TYCoreHttpTyoe_wwan,
};

#define kTYCNetStatusChangedNotification @"kTYCNetStatusChangedNotification"

@interface TYCoreHttpStatus : NSObject

/** 当前网络状态 */
+ (TYCoreHttpType)httpType;

/** 有网 */
+ (BOOL)isReachable;
+ (BOOL)isAppleReachable;

/** 当前是否处于wifi */
+ (BOOL)isWifiEnable;

+ (NSString *)getCurrentNetworkType;

@end
