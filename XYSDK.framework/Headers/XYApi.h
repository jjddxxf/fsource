//
//  XYApi.h
//  XYSDK
//
//  Created by 刘磊 on 2018/7/26.
//  Copyright © 2018年 刘磊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TYSDKCoreKit/XYApiShares.h>
#import <GASDK/GASDK.h>
//@class CLUIConfigure;


@interface XYApi : NSObject

#pragma mark XYSDK 初始化
/**
 XYSDK 初始化(新版API) 在生命周期的方法中 创建XYSDKInitConfig
 + (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
 */
+ (void)initWithConfig:(XYSDKInitConfig *)config;


/// 设置地址
/// @param serverUrlStr 地址字符串
+ (void)resetServerUrlString:(NSString *)serverUrlStr;

#pragma mark - 生命周期模块
+ (void)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;


+ (BOOL)application:(UIApplication *)application
      handleOpenURL:(NSURL *)url;

+ (BOOL)application:(UIApplication *)app
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

+ (void)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

+ (BOOL)application:(UIApplication *)application
continueUserActivity:(NSUserActivity *)userActivity
 restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> *))restorationHandler;

+ (void)applicationWillTerminate:(UIApplication *)application;

/**
 检查微信是否已安装
 
 @return 微信已安装返回YES，未安装返回NO。
 */
+ (BOOL)isWXAppInstalled;


#pragma mark - 用户登录相关
/**
 登录

 @param req 登录请求的结构
 @param completion 登录结果回调函数
 */
+ (void)XYLoginWith:(XYLoginReq *)req completionHandler:(XYRespBlock)completion;


/**
 获取验证码

 @param mobile 手机号
 @param type 验证码类型
 @param completion 结果回调函数
 */
+ (void)XYSendPhoneCode:(NSString *)mobile type:(XYGetCodeType)type completionHandler:(XYRespBlock)completion;

/**
 获取验证码

 @param email 邮箱
 @param completion 结果回调函数
 */
+ (void)XYSendEmailCodeForType:(XYGetEmailCodeType)type email:(NSString *)email completionHandler:(XYRespBlock)completion;

/**
 修改重置密码

 @param mobile 手机号
 @param newPassword 新密码
 @param code 验证码
 @param completion 结果回调函数
 */
+ (void)XYResetPasswordWithMobile:(NSString *)mobile newPasswrod:(NSString *)newPassword code:(NSString *)code completionHandler:(XYRespBlock)completion;

/**
 修改重置密码

 @param email 邮箱
 @param newPassword 新密码
 @param code 验证码
 @param completion 结果回调函数
 */
+ (void)XYResetPasswordWithEmail:(NSString *)email newPasswrod:(NSString *)newPassword code:(NSString *)code completionHandler:(XYRespBlock)completion;

/**
 游客绑定

 @param bindReq 绑定请求类
 @param completion 结果回调函数
 */
+ (void)XYBindByBindReq:(XYBindReq *)bindReq isUnbindGuest:(NSString *)isunbindguest completionHandler:(XYRespBlock)completion;

/**
 更新用户信息

 @param user 用户实例
 @param completion 结果回调函数
 */
+ (void)XYUpdateUserInfo:(XYUpdateUser *)user completionHandler:(XYRespBlock)completion;

/**
 设置当前登录用户头像

 @param completion 结果回调函数
 */
+ (void)XYSetUserAvatar:(XYRespBlock)completion;

/**
 获取当前登录用户信息

 @return 用户信息
 */
+ (NSDictionary *)XYGetCurrentUserDict;

/**
 注销操作: 清除登录方式.清除三方验证信息.更新用户信息,更新本地数据
 */
+ (void)XYLogout;
+ (void)XYLogoutWithCompletion:(XYRespBlock)completion;
+ (void)XYLogoutChannelWithType:(XYLoginType) type;

/**
 查询三方账号是否存在我们自己的账号
 
 @param snsType 查询类型
 */
+ (void)CheckUserExist:(XYBindType )snsType completion:(XYRespBlock)completion;

/**
监听Apple授权状态 ,此方法只有在游戏进行中如果有终止apple id使用app的操作时，才会回调给用户。正常登录注销不会回调。回调此函数后，项目组进行自己的逻辑处理，注销或者重新拉起登录。

@param completion 回调. 0已授权 1授权终止 2未找到授权状态
*/
+ (void)XYObserverAuth:(XYRespBlock)completion;

/**
 通过Token登录

 @param token token
 @param completion 返回结果回调
 */
+ (void)XYLoginByToken:(NSString *)token completionHandler:(XYRespBlock)completion;

/**
 游客账号是否存在

@param completion 返回结果回调
*/
+ (void)XYHasGeneratedGuest:(XYRespBlock)completion;

/**
 查询当前登录账号是否已绑定邮箱
 
 @param completion 返回结果回调
 */
+ (void)XYHasBindEmail:(XYRespBlock)completion;

/**
通过token获取手机号绑定的用户列表
@param token token
@param completion 返回结果回调
*/
+(void)XYGetBindUserList:(NSString *)token completionHandler:(XYRespBlock)completion;

#pragma mark - 分享
/**
 分享
 如果 imageData 不为空则只分享图片，如果 imageData 为空且 webpageUrl 不为空则分享链接
 
 @param shareReq 分享信息
 @param completion 分享结果回调
 */
+ (void)XYShareWithReq:(XYShareReq *)shareReq completionHandler:(XYRespBlock)completion;

#pragma mark - 新版分享

/// 发起分享
/// @param shareContent 分享内容种类见XYApiShare
/// @param complateBlock 回调结果
+ (void)XYShareWithContents:(XYShareBaseContent *)shareContent complateHandle:(XYRespBlock)complateBlock;

#pragma mark - 抖音归因设置用户信息
/// 归因  登录后 设置用户信息需要在渠道初始化至少2秒后再执行 若不够2秒，会挂起到任务池进行等待 当初始化后2秒检测任务池此时回调存在延后情况
/// @param userId 用户ID 必传
/// @param extraJson 可不传 传空串即可 @""
/// @param indieToken 暂不支持 传空串即可 @""
/// @param loginToken 登录成功后 返回的token 必传
/// @param completion 回调
+ (void)DYGYResetUserInfoWith:(NSString *)userId
                    extraJson:(NSString *)extraJson
                   indieToken:(NSString *)indieToken
                   loginToken:(NSString *)loginToken
            completionHandler:(XYRespBlock)completion;

/**
 {
     "data" : {
         "bind_channel_type" : 1, // 归因用户 1 不明确, 2 直播联运归因  3 自然量
     },
     "code":0,
     "message":"success"
 }
 */
/// 获取归因结果 获取用户归因结果
/// @param userid 用户ID 必传
/// @param appid 项目APPID 必传
/// @param completion 获取结果
+ (void)DYGYGetUserInfoWith:(NSString *)userid
                      appid:(NSString *)appid
          completionHandler:(XYRespBlock)completion;


#pragma mark - 支付相关

/**
 购买钻石，在购买钻石时内部会先加载商品信息

 @param product 商品实例
 @param completion 支付结果回调
 */
+ (void)XYCharge:(XYProduct *)product completionHandler:(XYRespBlock)completion;

/**
 消耗钻石

 @param product 商品实例
 @param completion 支付结果回调
 */
+ (void)XYConsume:(XYProduct *)product completionHandler:(XYRespBlock)completion;

/**
获取商品的本地价格

@param completion 结果回调函数
*/
+(void)XYGetLocalProductPriceWithCompletion:(XYRespBlock)completion;


#pragma mark - 跳转 App Store
/**
 跳转到 App Store

 @param appId  iTunes Connect 中App对应的Apple ID
 */
+ (void)XYGotoAppStoreWithAppId:(NSInteger)appId;


#pragma mark - 获取SDK版本号
/**
 获取 SDK 版本号
 
 @return SDK 版本号
 */
+ (NSString *)getApiVersion;


/// 设置idfa
/// @param idfa 标识符
+ (void)XYSetIDFA:(NSString *)idfa;

#pragma mark - 打点
+ (void)trackNormalEventWith:(NSMutableDictionary *)object type:(GAEventType)type event:(NSString *)event;

+ (void)trackAbnormalEventWith:(NSMutableDictionary *)object type:(GAEventType)type event:(NSString *)event;

#pragma mark - 获取指纹
+ (void)getYiDunDeviceInfo:(void(^)(TYBaseResp * resp))complate;

#pragma mark - 行为验证码
+ (void)getYiDunCaptcha:(void(^)(TYBaseResp * resp))complate;

+ (void)getYiDunCaptcha:(NSDictionary *)info andComplate:(void (^)(TYBaseResp * resp))complate;

#pragma mark - 人脸识别
+ (void)getYiDunLiveDetect:(NSDictionary *)info andComplate:(void (^)(TYBaseResp * resp))complate;

#pragma mark - URL跳转
/// 通过系统接口跳转到3方页面（要求：@available(iOS 10.0, *)）
///  - 如果app安装的情况下，跳转到对应app
///  - 如果app未安装，跳转到web页面
/// @param urlString url字符串
+ (void)jumpSpecialUrl:(NSString *)urlString;


#pragma mark - 获取微信昵称和头像
+ (void)getWXAuthInfo:(NSString *)userId completionHandler:(XYRespBlock)completion;
+ (void)requestWXAuthorize:(NSString *)userId completionHandler:(XYRespBlock)completion;


#pragma mark - 角色信息设置
+ (void)setGameUserInfo:(NSString *)RoleId serverId:(NSString *)ServerId completion:(XYRespBlock)completion;

#pragma mark - 获取facebook 好友列表
+ (void)getFBFriendList:(XYRespBlock)completion;
@end
