//  TYUtils.h
//  UtilsHandle
//
//  Created by hui on 2021/2/20.
//  Copyright © 2021 周翔宇. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYUtils : NSObject

@property (nonatomic, copy, readonly, class) int (^safeInt)(id obj);
@property (nonatomic, copy, readonly, class) NSString *(^safeString)(id obj);
@property (nonatomic, copy, readonly, class) NSDictionary *(^safeDic)(id obj);
@property (nonatomic, strong, readonly, class) NSMutableDictionary *(^safeMutableDic)(id obj);


/// 字典转json
/// @param dict 字典
+ (NSString *)dicTojsonString:(NSDictionary *)dict;

+ (NSString *)convertArrayToString:(NSArray *)array;

/// 获取当前时间戳
+ (NSString *)getCurrentTimeStamp;
@end

NS_ASSUME_NONNULL_END
