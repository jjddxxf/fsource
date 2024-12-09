//  TYUtilsHandel.h
//  UtilsHandle
//
//  Created by hui on 2021/2/20.
//  Copyright © 2021 周翔宇. All rights reserved.
//

#ifndef TYUtilsHandel_h
#define TYUtilsHandel_h

#import <TYSDKCoreKit/TYHttpHandle.h>
#import <TYSDKCoreKit/TYUUID.h>
#import <TYSDKCoreKit/TYKeychain.h>
#import <TYSDKCoreKit/TYBaseResp.h>
#import <TYSDKCoreKit/TYUtils.h>
#import <TYSDKCoreKit/TYCoreHttpStatus.h>
#import <TYSDKCoreKit/TYUpLoadImage.h>
#import <TYSDKCoreKit/UIImage+TYProject.h>
#import <TYSDKCoreKit/NSString+TYProject.h>
#import <TYSDKCoreKit/NSObject+TYModelToDict.h>
#import <TYSDKCoreKit/TYLogHelper.h>

// 用于定义所以渠道和SDK可能需要用到的事件
#define XYSDKLoginSuccessWithUserInfo @"XYSDKLoginSuccessWithUserInfo"
#define XYSDKRegisteSuccessWithUserInfo @"XYSDKRegisteSuccessWithUserInfo"
#define XYSDKLoginProcessCompleted @"LoginProcessCompleted"
#define NotifyAttributionDataReporting @"NotifyAttributionDataReporting"
#define EmailFetchedSuccessfully @"EmailFetchedSuccessfully" // 用于上报email

#endif /* TYUtilsHandel_h */
