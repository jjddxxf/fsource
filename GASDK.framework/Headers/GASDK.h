//
//  GASDK.h
//  GASDK
//
//  Created by 周翔宇 on 2020/1/9.
//  Copyright © 2020 周翔宇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GAConstants.h"
NS_ASSUME_NONNULL_BEGIN

@interface GASDK : NSObject

/**
获取项目组的GA实例
@param projectId  BI分配的projectId
*/
+ (instancetype)getGAlog:(NSString *)projectId;

/**
获取SDK的GA实例
@param projectId  BI分配的projectId
*/
+ (instancetype)getSDKGAlog:(NSString *)projectId;

/**
 GASDK初始化方法
 @param gameId 游戏id
 @param clientId 客户端id
 @param commonParams 通用参数，每次上报都会带上这儿设置的参数
 @param serverUrl 地址
 */
- (void)initWithGameId:(NSString *)gameId clientId:(NSString *)clientId withCommonParams:(NSDictionary *)commonParams serverUrl:(GAServerUrl)serverUrl;

/**
 设置 userId，登录成功后设置

 @param userId 用户 id
 */
- (void)setUserId:(NSString *)userId;

/**
 设置 yidunDeviceid
 
 @param yidunDeviceid 易盾设备指纹
 */
+ (void)setYidunDeviceid:(NSString *)yidunDeviceid;

/**
 上报日志
 
 @param object BI日志，传入的数据为完整的日志格式数据，内部只将数据转为 json 字符串上报到日志服
 */
- (void)track:(NSDictionary *)object type:(GAEventType)type event:(NSString *)event;

/**
 上报日志

 @param object BI日志，传入的数据为完整的日志格式数据，内部只将数据转为 json 字符串上报到日志服
 @param complate 上报结果回调
 */
- (void)track:(NSDictionary *)object type:(GAEventType)type event:(NSString *)event complate:(void(^)(BOOL isSuccess))complate;

/**
 获取上报数据

 @param object BI日志，传入的数据为完整的日志格式数据，内部只将数据转为 json 字符串上报到日志服
 */
- (NSDictionary *)getParamasWithObject:(NSDictionary *)object type:(GAEventType)type event:(NSString *)event;

/**
 获取上报url
 */
-(NSString *)requestUrl;

/**
 上报日志
 
 @param object BI日志，不传事件类型，默认为track
 */
- (void)track:(NSDictionary *)object event:(NSString *)event;


/**
设置用户特征

@param object BI日志，不传事件类型，默认为track
*/
- (void)trackProfile:(NSDictionary *)object event:(GAProfileEvent)event;

/**
是否log输出

@param enableLog  YES log输出，NO 不输出，默认为YES
*/
+ (void)enableLog:(BOOL)enableLog;
/**
 获取 SDK 版本号

 @return SDK 版本号
 */
+ (NSString *)getApiVersion;

/**
 设置 IDFA，可选，如果项目组需要在打点上传idfa，则需调用此方法传入

 @param idfa  广告标识符
 */
+ (void)setIDFA: (NSString *)idfa;

@end

NS_ASSUME_NONNULL_END
