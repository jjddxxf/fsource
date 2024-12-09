//  TYBaseDataModel.h
//  TYSDKCoreKit
//
//  Created by hui on 2021/3/25.
//  Copyright © 2021 周翔宇. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYDeviceInfoModel.h"



//NS_ASSUME_NONNULL_BEGIN


@interface TYBaseDataModel : NSObject

@property (nonatomic, strong) TYDeviceInfoModel *deviceInfo;

@property (nonatomic, copy) NSString *serverUrl;
@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, copy) NSString *gameId;
@property (nonatomic, copy) NSString *cloudId;
@property (nonatomic, copy) NSString *sdkTrackId;
@property (nonatomic, copy) NSString *sdkVersion;
@property (nonatomic, assign) NSInteger appId;
@property (nonatomic, assign) NSInteger userId;
//GA
@property (nonatomic, copy) NSString *projectId;

/// 理论上所有SDK的数据层 基本数据一致， 以防以后特殊需求 每个SDK单独持有一份自己的数据层
/// 除主初始化SDK外(xysdk), 其他SDK的数据层(basedata实例)使用此方法装载数据；其他SDK在主SDK初始化后 来此获取数据
/// @param dataModel 某个SDK的数据层模型
+ (NSMutableDictionary *)updateDataModelWith:(TYBaseDataModel *)dataModel;


/// 主初始化SDK(xysdk)的数据层更新数据
/// @param baseDataDic XYSDK中的数据层所有数据
+ (void)saveDataWith:(NSMutableDictionary *)baseDataDic;

/**
 获取基本请求信息

 @return 基本请求信息
 */
- (NSMutableDictionary *)getRequestParameters;

/**
 获取基本请求信息

 @return 基本请求信息
 */
- (NSMutableDictionary *)getRequestParametersWithObjects:(NSArray *)objects forKeys:(NSArray *)keys;

/**
 获取GA数据

 @return GA基本数据
 */
- (NSMutableDictionary *)getInitGAParam;

/**
 获取全部数据，基本数据和GA数据

 @param dic 自定义数据

 @return 基本数据和GA数据及自定义数据
 */
- (NSMutableDictionary *)getFullParmatersWithDic:(NSDictionary *)dic;

@end

//NS_ASSUME_NONNULL_END
