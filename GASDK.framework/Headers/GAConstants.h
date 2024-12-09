//
//  GAConstants.h
//  GA
//
//  Created by on 2018/8/9.

#import <Foundation/Foundation.h>


#pragma mark - typedef

/**
 * @abstract
 * Debug 模式，用于检验数据导入是否正确。
 *
 * Debug模式有三种选项:
 *   GALoggerDebugOff - 关闭 DEBUG 模式
 *   GALoggerDebugAndTrack - 打开 DEBUG 模式，并将数据导入到 BILog 中
 */
typedef NS_ENUM(NSInteger, GADebugMode) {
    GALoggerDebugOff,
    GALoggerDebugAndTrack,
};

typedef NS_ENUM(NSInteger, GAEventType) {
    GA_TRACK = 1,  //默认类型
    GA_CION = 2,   //金流相关事件
    GA_PAY = 3,    //支付相关事件
    GA_GAME = 4,   //游戏行为
    GA_LOGIN = 5,  //登录注册相关事件
    GA_PUSH = 6,   //推送相关事件
    GA_ADBOX = 7,  //adbox相关事件
    GA_PREFORMANCE = 8, //性能上报相关事件
    GA_SDK = 9,    //SDK相关事件
    GA_ABTest = 10, //abtest相关事件
    GA_PROFILE = 11, //设置用户特征
};

typedef NS_ENUM(NSInteger, GAProfileEvent) {
    GA_PROFILE_SET = 1,
    GA_PROFILE_SET_ONCE =2,
    GA_PROFILE_INCREMENT =3,
    GA_PROFILE_DELETE =4,
    GA_PROFILE_UNSET =5,
};


typedef NS_ENUM(NSInteger, GAServerUrl) {
    GA_INTERNAL = 1,  //国内的
    GA_INTERNATIONAL = 2,   //国外的
};
