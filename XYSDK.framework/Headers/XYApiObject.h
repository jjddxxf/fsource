//
//  XYApiObject.h
//  XYSDK
//
//  Created by 刘磊 on 2018/7/26.
//  Copyright © 2018年 刘磊. All rights reserved.
//

#import <TYSDKCoreKit/TYBaseResp.h>

/** 返回事件类型 */
typedef NS_ENUM(NSInteger, XYErrCode) {
    // --------登录返回事件---------
    XYSuccess               = 0,        /**< 登录/分享成功 */
    XYErrCodeCommon         = -1,       /**< 普通错误类型/支付失败 */
    XYErrCodeUserCancel     = -2,       /**< 用户点击取消并返回 */
    XYErrCodeSentFail       = -3,       /**< 发送失败/参数异常 */
    XYErrCodeAuthDeny       = -4,       /**< 授权/签名失败 */
    XYErrCodeUnsupport      = -5,       /**< 登录方式不支持 */
    XYErrCodeNetwork        = -6,       /**< 网络异常 */
    XYErrCodeHadBind        = -7,       /**< 已绑定过 */
    XYErrTokenExpire        = -8,       /**< token已过期 */
    XYErrForbiddenFail      = -9,       /**< 用户被封禁 */
    XYErrVerifyCodeError    = -10,      /**< 验证码无效 */
    XYErrRepeatRequest      = -11,      /**< 登录请求中... */

    // --------支付返回事件---------
    XYLOAD_PRODUCT_FAILED   = -100,     /**< 未加载商品列表 */
    XYPRODUCTID_NULL        = -101,     /**< 内购商品加载不到 加载失败 */
    XYPAYOBJ_NULL           = -104,     /**< 要购买的商品信息为空 */
    XYPRODUCT_CNT_ZERO      = -105,     /**< 苹果后台未配置该商品 */
    XYPayUnknown            = -107,     /**< 支付完成但结果未知 */
    XYCURRENCY_ERROR        = -108,     /**< 要购买的商品信息币种不合规 */
    XYPayTimeout            = -110,     /**< 支付动作超时 */
    XYPaing                = -120,      /**< 支付处理中... */
    XYSupplement            = -121,     /**< 开始补单 */
    XYProductRelateError              = -122,     /**< 映射关系获取异常 */
    XYSKProductInfoError              = -123,     /**< 渠道商品详情缺失 */
    XYSKServiceTypeError              = -124,     /**<  服务暂不支持订阅购买 */

    // --------登录返回---------
    LOGIN_UN_REALNAME_VERIFIED = 30003,          /**< 未实名认证，十五日内在线时长超过 1 小时 */
    UNDERAGE_FORBID_LOGIN = 30004,               /**< 未成年禁止在22-8点游戏*/
    ONLINE_TIME_LIMITED = 30005,                 /**< 超过在线时间限制*/
    // --------下单返回事件---------
    CHARGE_UN_REALNAME_VERIFIED = 30300,         /**< 未实名认证，不允许支付(实名认证拦截)*/
    UNDER_8_CHARGE_LIMITED = 30301,              /**< 小于 8 岁不允许充值(实名认证拦截)*/
    CHARGE_LIMIT_BOUT = 30302,                   /**< 充值金额超过单笔充值限额(实名认证拦截)*/
    CHARGE_LIMIT_MONTH = 30303,                  /**< 充值金额超过当月充值限额(实名认证拦截)*/
    
    NOT_EXSIT_GUEST = 6002000,                    /** 游客账号不存在*/
    YIDUNCAPTCHA_NOT_EXSIT = 5000000,            /** 易盾行为验证码渠道不存在*/
    YIDUNZHIWEN_NOT_EXSIT = 7000000,             /** 易盾指纹渠道不存在*/
    YIDUNLIVEDETECT_NOT_EXSIT = 7001004,         /** 易盾人脸识别渠道不存在*/
};

/** 登录方式 */
typedef NS_ENUM(NSInteger, XYLoginType) {
    XYLoginWithGuest                = 0,    /**< 游客登录 */
    XYLoginWithPhonePwd             = 1,    /**< 手机号密码登录 */
    XYLoginWithPhoneCode            = 2,    /**< 手机号验证码登录 */
    XYLoginWithFB                   = 3,    /**< Facebook登录 */
    XYLoginWithWX                   = 4,    /**< 微信登录 */
    XYLoginWithApple                = 5,    /**< Apple登录 */
    XYLoginWithGoogle               = 6,    /**< google登录*/
    XYLoginWithYiDun                = 8,    /**< 易盾渠道*/
    XYLoginWithEmail                = 9,    /**< 邮箱登录 */
    XYLoginWithVnQuickLogin         = 10,   /**< 越南快速登录 */
    XYLoginWithVnUserNameLogin      = 11,   /**< 越南账号密码登录 */
    XYLoginWithEmailPwd             = 12,   /**< 邮箱密码登录 */
    XYLoginWithYiDunV2              = 13,   /**< 易盾渠道V2*/
    XYLoginWithTwitter              = 14,   /**< twitter登录*/
    XYLoginWithLine                 = 15,   /**< Line登录*/
};

typedef NS_ENUM(NSInteger, XYUserNameType) {
    XYUserNameForDefault           = 1,    /**< 用户名类型 */
    XYUserNameForMobile            = 2,    /**< 手机号类型 */
    XYUserNameForEmail             = 3,    /**< 邮箱类型 */
};

/** 验证码获取类型 */
typedef NS_ENUM(NSInteger, XYGetCodeType) {
    XYGetCodeTypeRegister              = 0,     /**< 注册 */
    XYGetCodeTypeChangePassword        = 1,     /**< 修改密码 */
    XYGetCodeTypeLogin                 = 2,     /**< 登录 */
    XYGetCodeTypeBindPhoneNumber       = 3,     /**< 绑定 */
};

typedef NS_ENUM(NSInteger, XYGetEmailCodeType) {
    XYGetEmailCodeForLogin      = 1,     /**< 登录/注册  */
    XYGetEmailCodeForBind       = 2,     /**< 绑定 */
    XYGetEmailCodeForResetPwd   = 3,     /**< 修改密码 */
};

/** 微信分享的目标场景 */
typedef NS_ENUM(NSUInteger, XYShareScene) {
    XYShareSceneSession  = 0,        /**< 好友 */
    XYShareSceneTimeline = 1,        /**< 朋友圈 */
    XYShareSceneFavorite = 2,        /**< 收藏 */
    XYShareSceneMiniProgramRelease  = 3,        /**< 小程序-正式版 */
    XYShareSceneMiniProgramTest     = 4,        /**< 小程序-测试版*/
    XYShareSceneMiniProgramPreview  = 5,        /**< 小程序-体验版 */
};

/** 购买商品类型 */
typedef NS_ENUM(NSUInteger, XYProductType) {
    XYCharge            = 0,            /**< 购买钻石 */
    XYConsume           = 1,            /**< 消费钻石,钻石不足则充值 */
    XYOnlyConsume       = 2,            /**< 不消耗已有钻石,现买现消费 三方调用类型 */
};

/** 渠道商品类型 */
typedef NS_ENUM(NSUInteger, SKProductType) {
    XYNormal        = 0,        /**< 消耗型商品 */
    XYSub           = 1,        /**< 订阅商品 */
};

/** 更新用户信息平台来源 */
typedef NS_ENUM(NSUInteger, XYUpdatePlatform) {
    XYNomal             = 0,            /**< 默认来源 */
    XYWechat            = 1,            /**< 根据微信信息更新 */
};

/** 绑定类型 */
typedef NS_ENUM(NSUInteger, XYBindType) {
    XYBindMobile        = 0,        /**< 绑定手机号 */
    XYBindFB            = 1,        /**< 绑定Facebook */
    XYBindWX            = 2,        /**< 绑定微信 */
    XYBindApple         = 3,        /**< 绑定apple */
    XYBindGoodle        = 4,        /**< 绑定Google */
    XYBindEmail         = 6,        /**< 绑定邮箱 */
    XYBindTwitter       = 7,        /**< 绑定twitter */
    XYBindLine          = 8         /**< 绑定Line */
};

/** apple 授权状态 */
typedef NS_ENUM(NSUInteger, XYAppleAuthStatus) {
    XYAuthorized            = 0,            /**< 已授权*/
    XYRevoked               = 1,            /**< 授权终止 */
    XYNotFound              = 2,            /**< 未找到授权状态 */
};

/** 三方信息登录方式 */
typedef NS_ENUM(NSUInteger, XYSNSInfoType) {
    XYSNSNomal             = 0,            /**< 默认来源:tuyoo  */
    XYSNSWechat            = 1,            /**< 根据微信信息    */
    XYSNSAccount           = 2,            /**< 根据手机号等信查询判断    */
    XYSNSFacebook          = 3,            /**< 根据Facebook信息登录 */
};

/** 查看账号是否绑定 */
typedef NS_ENUM(NSUInteger, XYSNSIsExist) {
    XYSNSExist             = 0,            /**< 绑定过了  */
    XYSNSNotExist          = 1,            /**< 未绑定    */
};

typedef NS_ENUM(NSUInteger, XYReportDeviceInfoPolicy) {
    /**旧版归因 首次安装上报*/
    XYReportDeviceInfoOnFirstOpen = 1,
    /**新版归因 每次启动上报 默认此种策略*/
    XYReportDeviceInfoOnLaunch
};

/** 语言类型 */
typedef NS_ENUM(NSUInteger, XYLanguageCode) {
    XYLanguageCode_zh_CN = 1,      /** 中文简体*/
    XYLanguageCode_zh_TW,      /** 中文繁体*/
    XYLanguageCode_en_US,      /** 英语*/
    XYLanguageCode_ja_JP,      /** 日语*/
    XYLanguageCode_ko_KR,      /** 韩语(朝鲜语)*/
    XYLanguageCode_vi_VN,      /** 越南语*/
    XYLanguageCode_tl_PH,      /** 菲律宾语*/
    XYLanguageCode_ar,         /** 阿拉伯语*/
    XYLanguageCode_nl_NL,      /** 荷兰语*/
    XYLanguageCode_fr_FR,     /** 法语*/
    XYLanguageCode_de_DE,      /** 德语*/
    XYLanguageCode_it_IT,      /** 意大利语*/
    XYLanguageCode_pt_PT,      /** 葡萄牙语*/
    XYLanguageCode_es_ES,      /** 西班牙语*/
    XYLanguageCode_bn_BD,      /** 孟加拉语*/
    XYLanguageCode_hr_HR,      /** 克罗地亚语*/
    XYLanguageCode_cs_CZ,      /** 捷克语*/
    XYLanguageCode_da_DK,      /** 丹麦语*/
    XYLanguageCode_el_GR,      /** 希腊语*/
    XYLanguageCode_hi_IN,      /** 印度语*/
    XYLanguageCode_hu_HU,      /** 匈牙利语*/
    XYLanguageCode_in_ID,      /** 印度尼西亚语*/
    XYLanguageCode_ms_MY,      /** 马来语*/
    XYLanguageCode_fa_IR,      /** 波斯语*/
    XYLanguageCode_pl_PL,      /** 波兰语*/
    XYLanguageCode_ro_RO,      /** 罗马尼亚语*/
    XYLanguageCode_ru_RU,      /** 俄罗斯语*/
    XYLanguageCode_sr_RS,      /** 塞尔维亚语*/
    XYLanguageCode_sv_SE,      /** 瑞典语*/
    XYLanguageCode_th_TH,      /** 泰语*/
    XYLanguageCode_tr_TR,      /** 土耳其语*/
    XYLanguageCode_fi_FI,      /** 芬兰语*/
    XYLanguageCode_af_ZA,      /** 南非语*/
    XYLanguageCode_km_KH,      /** 柬埔寨语*/
};
#pragma mark - 登录请求类
@interface XYLanguageType : NSObject
@end

#pragma mark - 登录请求类
@interface XYLoginReq : NSObject

/** 初始化登录方式 */
+ (instancetype)initWithLoginType:(XYLoginType)type;


/// 设置Facebook请求权限
/// @param authorityList 权限列表 如果不设置 SDK会默认添加 public_profile 权限；
- (void)configFBRequestAuthority:(NSArray *)authorityList;

/**
 手机号密码登录初始化

 @param mobile 手机号
 @param password 密码
 @return 手机号登录请求实例
 */
+ (instancetype)initWithMobile:(NSString *)mobile password:(NSString *)password;

/**
 手机号验证码登录初始化

 @param mobile 手机号
 @param code 验证码
 @return 手机号登录请求实例
 */
+ (instancetype)initWithMobile:(NSString *)mobile code:(NSString *)code;

/**
 邮箱验证码登录初始化

 @param email 邮箱
 @param code 验证码
 @return 邮箱登录请求实例
 */
+ (instancetype)initWithEmail:(NSString *)email code:(NSString *)code;

/**
 邮箱密码登录初始化

 @param email 邮箱
 @param password 密码
 @return 邮箱登录请求实例
 */
+ (instancetype)initWithEmail:(NSString *)email password:(NSString *)password;

/**
 （VN专用）用户名密码登录初始化 — 同手机号/Uid登录不互通
 @param userNameType 用户名类型（默认为XYUserNameForDefault）
 @param username 用户名
 @param password 密码
 @return （VN专用）用户名密码登录请求实例
 */
+ (instancetype)initWithUserNameType:(XYUserNameType)userNameType username:(NSString *)username password:(NSString *)password;
/**
 （VN专用）用户名密码登录初始化 — 同手机号/Uid登录不互通
 @param userNameType 用户名类型
 @param mobile 手机号类型的用户名
 @param areaCode 手机号区号
 @param password 密码
 @return （VN专用）用户名密码登录请求实例
 */
+ (instancetype)initWithUserNameType:(XYUserNameType)userNameType areacode:(NSInteger)areaCode mobile:(NSString *)mobile  password:(NSString *)password;

- (XYLoginType)getLoginType;
/**
 （内部方法，外部请勿调用）
 @param trackId 请求的trackId
 */
- (void)configTrackId:(NSString *)trackId;
- (NSString *)getTrackId;

/**
 （内部方法，外部请勿调用）
 */
- (void)configRequestExtraData:(NSDictionary *)extraData;
- (NSDictionary *)getExtraData;

@end

#pragma mark - 绑定请求类
@interface XYBindReq : NSObject

/**
 绑定
 
 @param platform 绑定类型
 @param userId 用户id
 @return 绑定请求实例
 */
+ (instancetype)initBindWithPlatform:(XYBindType)platform UserId:(NSUInteger)userId;

/**
 绑定手机

 @param userId 用户id
 @param mobile 手机号
 @param code 验证码
 @return 绑定请求实例
 */
+ (instancetype)initBindMobileWithUserId:(NSUInteger)userId mobile:(NSString *)mobile code:(NSString *)code;

/**
 绑定邮箱

 @param userId 用户id
 @param email 邮箱
 @param code 验证码
 @return 绑定请求实例
 */
+ (instancetype)initBindEmailWithUserId:(NSUInteger)userId token:(NSString *)token email:(NSString *)email code:(NSString *)code;

/**
 （内部方法，外部请勿调用）
 @param trackId 请求的trackId
 */
- (void)configTrackId:(NSString *)trackId;
- (NSString *)getTrackId;

/**
 （内部方法，外部请勿调用）
 */
- (void)configRequestExtraData:(NSDictionary *)extraData;
- (NSDictionary *)getExtraData;

@end

#pragma mark - 支付商品类
@interface XYProduct : NSObject

/** 三方消费订单ID,透传给三方 通知三方服务发货时使用 可选 */
@property (nonatomic, copy) NSString *productOrderId;

/** appid  用于商品查找  如果不传，会使用XYApi的初始化appid作为接口上传参数*/
@property (nonatomic, copy) NSString *appId;

/** productType  渠道商品类型  如果不传，默认消耗性型商品*/
@property (nonatomic, assign) SKProductType SKProductType;

/**
 生成购买商品实例 iOS v2内购商品对象创建方法

 @param productType 购买商品类型
 @return 商品实例
 */
+ (instancetype)createShoppingDataWith:(XYProductType)productType;

/**
 修改商品价格

 @param price 商品价格
 @return 商品实例
 */
- (instancetype)updatePrice:(float)price;

/** ios 内购商品
 设置商品信息 gameId == -1 userId == -1 时不验证 , userId 若传请检查是否正确
 
 @param appInfo app信息
 @param productId 商品id
 @param productName 商品名称
 @param productPrice 商品价格（可以传 0）
 @param gameId gameId
 @param productCount 商品数量
 @param userId 用户id
 @return 商品实例
 */
- (instancetype)XYProductWithAppInfo:(NSString *)appInfo
                           productId:(NSString *)productId
                         productName:(NSString *)productName
                        productPrice:(float)productPrice
                              gameId:(NSInteger)gameId
                        productCount:(NSInteger)productCount
                              userId:(NSInteger)userId;



@end


#pragma mark - 分享请求类
@interface XYShareReq : NSObject

/**
 微信分享图片

 @param shareScene 发送的目标场景
 @param imageData 图片真实数据内容 大小不能超过10M
 @return 分享实例
 */
+ (instancetype)initWithScene:(XYShareScene)shareScene imageData:(NSData *)imageData;

/**
 微信分享链接

 @param shareScene 发送的目标场景
 @param title 标题 长度不能超过512字节
 @param nodeDes 描述内容 长度不能超过1K
 @param thumbData 缩略图数据 大小不能超过32K
 @param webpageUrl 网页的url地址 长度不能超过10K
 @return 分享实例
 */
+ (instancetype)initWithScene:(XYShareScene)shareScene title:(NSString *)title nodeDes:(NSString *)nodeDes thumbData:(NSData *)thumbData webpageUrl:(NSString *)webpageUrl;

+ (instancetype)initWithScene:(XYShareScene)shareScene title:(NSString *)title nodeDes:(NSString *)nodeDes imageData:(NSData *)imageData userName:(NSString *)userName path:(NSString *)path webpageUrl:(NSString *)webpageUrl;

@end


#pragma mark - 更新用户信息类
@interface XYUpdateUser : NSObject

/**
 创建用户更新信息

 @param platform 更新用户信息平台来源
 @return 用户更新信息
 */
+ (instancetype)createUpdateUserInfoWith:(XYUpdatePlatform)platform;

/**
 设置用户更新信息

 @param nickName 昵称
 @param tureName 真实姓名
 @param address 地址
 @param idCard <#idCard description#>
 @param phoneNum 手机号
 @param gender 性别
 @param headerUrl 微信用户的头像链接 可以为空默认不传
 @return 用户更新信息
 */
- (instancetype)XYUpdateUserInfoNickName:(NSString *)nickName trueName:(NSString *)tureName address:(NSString *)address idCard:(NSString *)idCard phoneNum:(NSString *)phoneNum gender:(NSString *)gender headerUrl:(NSString *)headerUrl;

@end


#pragma mark - SDK响应基类
@interface XYResp : TYBaseResp

///** 错误码 */
//@property (nonatomic, readonly, assign) NSInteger errCode;
///** 错误提示字符串 */
//@property (nonatomic, readonly, copy) NSString *errStr;
///** 响应数据 */
//@property (nonatomic, readonly, retain) id respObj;

@end

/**
 函数回调的block

 @param resp 返回信息
 */
typedef void(^XYRespBlock)(XYResp * _Nonnull resp);

#pragma mark - SDKCallback方法
typedef NS_ENUM(NSInteger, XYCallbackCodeType) {
    XYSDKCallBackCodeForContinue   = 1,     /**< 继续  */
    XYSDKCallBackCodeForStop       = 2,     /**< 中断流程 */
    XYSDKCallBackCodeForError      = 3,     /**< 报错，按原逻辑处理 */
};

@interface XYSDKCallBack : NSObject

typedef NSInteger (^CallbackBlock)(XYResp * _Nonnull resp);

@property (nonatomic, copy) CallbackBlock _Nullable callbackBlock;

- (NSInteger)performCallbackWith:(XYResp *_Nullable) resp;
@end

#pragma mark - 上报设备信息配置类
@interface XYReportDeviceInfoConfig : NSObject
/// 广告标识符
@property (nonatomic, copy) NSString * _Nonnull idfa;
/// appid
@property (nonatomic, copy) NSString * _Nonnull appid;
/**默认 XYReportDeviceInfoOnLaunch 每次启动上报 当前只支持此种模式*/
@property (nonatomic, assign) XYReportDeviceInfoPolicy reportPolicy;

/// 其他透传参数  一般不用
@property (nonatomic, copy) NSDictionary  * _Nullable  extraDic;

@end


#pragma mark - sdk 初始化配置
NS_ASSUME_NONNULL_BEGIN
@interface XYSDKInitConfig : NSObject

/**
 在生命周期的方法中 创建XYSDKInitConfig
 + (void)application:(UIApplication *)application
 didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
 默认/open/v4/sk/ios/order/v2 一般情况项目组不要改动 特殊需求使用
*/
// 启动时的application
@property (nonatomic, strong) UIApplication * launchApplication;
// 启动时的launchOptions
@property (nonatomic, strong) NSDictionary * launchOptions;
// 途游项目基本公共参数
@property (nonatomic, assign) NSInteger appId;
@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, copy) NSString *gameId;
@property (nonatomic, copy) NSString *cloudId;
@property (nonatomic, copy) NSString *serverUrl;
@property (nonatomic, copy) NSString *idfa;
/**设置是否查看SDK在控制台输出的日志  默认NO关闭 设置YES可以查看 发版前需要修改为NO关闭SDK控制台日志 */
@property (nonatomic, assign) BOOL openTerminalLog;


#pragma mark - GA打点配置

/**
 1. gaGameId、gaClientId、gaAppId、gaProjectId 请使用默认GA配置 特殊需求需要更改以上参数，请赋值
 
 2. URL默认国内 国外项目请传参使用国外类型 程序运行时检测到海外渠道会日志警告提示
 
 
 */

// GA gameID 默认20437
@property (nonatomic, copy) NSString * gaGameId;
// GA clientid 默认 IOS_5.0_guest.appStore.0-hall20437.appStore.sdkonline
@property (nonatomic, copy) NSString * gaClientId;
/// GA APPID 默认20437
@property (nonatomic, copy) NSString * gaAppId;
/// GA projectid 默认20437
@property (nonatomic, copy) NSString * gaProjectId;
/// GA serverURL 1国内 2国外  默认国内
@property (nonatomic, assign) int gaServerUrlType;





//===================================


#pragma mark - Google渠道参数 如果接入该渠道需要配置一下参数 不接该渠道不用配置


/// google的clientID 需要创建应用
@property (nonatomic, copy) NSString * googleClientid;

//=====================

#pragma mark - 微信渠道参数 如果接入该渠道需要配置一下参数 不接该渠道不用配置
/**
 向微信终端程序注册第三方应用。 先初始化XYSDK
 
 需要在每次启动第三方应用程序时调用。第一次调用后，会在微信的可用应用列表中出现，默认开启MTA数据上报。
 iOS7及以上系统需要调起一次微信才会出现在微信的可用应用列表中。
 */
/// 微信APPID 微信开发者ID
@property (nonatomic, copy) NSString * wxAppId;
/// 微信秘钥 微信appSecret
@property (nonatomic, copy) NSString * wxAppSecret;
/// 微信link
@property (nonatomic, copy) NSString * wxUniversalLink;


#pragma mark - 易盾渠道
// 易盾业务ID
@property (nonatomic, copy) NSString * yiDunBusinessid;

#pragma mark - dy归因

/// dygy appid 必传
@property (nonatomic, copy) NSString * dygyAppid;
/// dygy dygyAppName 必传
@property (nonatomic, copy) NSString * dygyAppName;
/// dygy dygyAppChannel
@property (nonatomic, copy) NSString * dygyAppChannel;
/// dygy 开发模式是否是debug模式 默认No 上线需要修改为No
@property (nonatomic, assign) BOOL dygyDevModel;

/// dygy 联运模式 0普通模式 默认0，1直播联运模式必须设置，指明当前为直播联运模式
@property (nonatomic, assign) int dygyAppUnionModel;

/// no归因整体无效  yes归因整体有效 默认no
@property (nonatomic, assign) BOOL dygyStatus;

/// dygy性能检测 no不检测 yes检测 默认no
@property (nonatomic, assign) BOOL dygyCarshObserverStatus;

/// dygy订单检测 no不检测 yes检测 默认no
@property (nonatomic, assign) BOOL dygyPYStatus;

@end
NS_ASSUME_NONNULL_END
