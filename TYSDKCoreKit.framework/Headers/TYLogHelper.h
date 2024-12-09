//
//  TYLogHelper.h
//  TYSDKCoreKit
//
//  Created by Liang shi on 2021/2/4.
//  Copyright © 2021 刘磊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYBaseResp.h"

#define TYTerminalLogWithDesc(logKey, description)  [TYLogHelper logWithFile:[NSString stringWithFormat:@"%s", __FILE_NAME__] func:[NSString stringWithFormat:@"%s", __func__] key:logKey desc:description];

#define TYTerminalLogWithResp(logKey, logResp) [TYLogHelper logWithFile:[NSString stringWithFormat:@"%s", __FILE_NAME__] func:[NSString stringWithFormat:@"%s", __func__] key:logKey resp:logResp]

#define TYTerminalLogInfoWithDesc(logDesc) [TYLogHelper logInfoWithFile:[NSString stringWithFormat:@"%s", __FILE_NAME__] func:[NSString stringWithFormat:@"%s", __func__] desc:logDesc]

#define TYTerminalLogInfoWithDesc(logDesc, ...) [TYLogHelper logInfoWithFile:[NSString stringWithFormat:@"%s", __FILE_NAME__] func:[NSString stringWithFormat:@"%s", __func__] desc:[NSString stringWithFormat:logDesc, ##__VA_ARGS__]]

NS_ASSUME_NONNULL_BEGIN

@interface TYLogHelper : NSObject

+ (void)checkTerminalLog:(BOOL)check;

/// 根据外界key读取预配置文案 格式化打印
/// @param key 文案对应的key
/// @param desc 使用外界传入的配置好的描述方案 如果传nil或空字符串，将使用默认的打印
+ (void)logWithFile:(NSString *)currFile func:(NSString *)currFunc key:(NSString *)key desc:(NSString *)desc;

/// 根据外界key读取预配置文案 格式化打印
/// @param key 文案对应的key
/// @param resp 使用外界传入的错误信息
+ (void)logWithFile:(NSString *)currFile func:(NSString *)currFunc key:(NSString *)key resp:(TYBaseResp *)resp;

/// 通用格式化打印
+ (void)logInfoWithFile:(NSString *)currFile func:(NSString *)currFunc desc:(NSString *)desc;

/// 更新本地打印数据
+ (void)updateLogDataSourceWith:(NSDictionary *)dic key:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
