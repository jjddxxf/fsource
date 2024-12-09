//
//  XYResp.h
//  XYSDK
//
//  Created by 刘磊 on 2018/7/26.
//  Copyright © 2018年 刘磊. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, TYCoreErrCode) {
    TYCoreSuccess               = 0,        /**< 登录/分享成功 */
    TYCoreErrCodeCommon         = -1,       /**< 普通错误类型/支付失败 */
    TYCoreErrCodeUserCancel     = -2,       /**< 用户点击取消并返回 */
    TYCoreErrCodeSentFail       = -3,       /**< 发送失败/参数异常 */
    TYCoreErrCodeAuthDeny       = -4,       /**< 授权/签名失败 */
    TYCoreErrCodeUnsupport      = -5,       /**< 登录方式不支持 */
    TYCoreErrCodeNetwork        = -6,       /**< 网络异常 */
    TYCoreErrCodeHadBind        = -7,       /**< 已绑定过 */
    TYCoreErrTokenExpire        = -8,       /**< token已过期 */
};

typedef NS_ENUM(NSUInteger, TYWXGetType) {
    TYWXGetLoginInfo            = 0,      //   微信登录数据
    TYWXGetUserInfo             = 1,      //   微信获取用户数据
    TYWXGetAuthorize            = 2,      //   微信获取授权
};

/** 微信分享的目标场景 */
typedef NS_ENUM(NSUInteger, TYShareScene) {
    TYShareSceneSession  = 0,        /**< 好友 */
    TYShareSceneTimeline = 1,        /**< 朋友圈 */
    TYShareSceneFavorite = 2,        /**< 收藏 */
};


@interface TYBaseResp : NSObject

/** 错误码 */
@property (nonatomic, readwrite, assign) NSInteger errCode;
/** 错误提示字符串 */
@property (nonatomic, readwrite, copy) NSString *errStr;
/** 响应数据 */
@property (nonatomic, readwrite, retain) id respObj;


+ (instancetype)responseWithCode:(NSInteger)code errStr:(NSString *)str;
+ (instancetype)responseWithCode:(NSInteger)code errStr:(NSString *)str objc:(id)objc;

/** 成功回调 errCode = 0 */
+ (instancetype)successRespWithStr:(NSString *)errStr;
+ (instancetype)successRespWithStr:(NSString *)errStr obj:(id)respObj;
/** 默认错误类型 errorCode = -1 */
+ (instancetype)commonError:(NSString *)errStr;
/** 发送失败 网络或数据异常 errCode = -3 */
+ (instancetype)sendError:(NSString *)errStr;
/** 网络异常 */
+ (instancetype)networkError;
/** 封禁错误类型 errorCode = -9 */
/** 网络异常 */
+ (instancetype)forbiddenError:(NSString *)errStr;
/** 参数检查->异常 */
+ (instancetype)checkParamError;
+ (instancetype)checkParamErrorWithMsg:(NSString *)errStr;

+ (instancetype)payNetError:(NSError *)error;

@end

typedef void(^TYBaseRespBlock)(TYBaseResp * _Nonnull resp);
