//
//  TYFileManager.h
//  GMFramework
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TYFileManager : NSObject
/** @name 读取 */
/**
 加载文件
 @param path 文件路径
 @return NSObject 文件中的数据
 */
+ (id )loadDataFromPath:(NSString *)path;

/**
 异步加载文件
 @param path 文件路径
 @param callback 加载完成后回调
 @return BOOL 同步返回文件是否存在
 */
+ (BOOL)asyncLoadDataFromPath:(NSString *)path callback:(void(^)(NSObject *data))callback;

/** @name 写入 */
/**
 存储数据到本地
 @param path 文件路径
 @param data 需要存储的数据
 @return NSData 文件中的数据
 */
+ (BOOL)saveData:(NSObject *)data withPath:(NSString *)path;

/**
 异步存储数据到本地
 @param path 文件路径
 @param data 需要存储的数据
 @param callback 存储完成后回调
 */
+ (void)asyncSaveData:(NSObject *)data withPath:(NSString *)path callback:(void(^)(BOOL succeed))callback;


/**
 存储数据到本地
 @param path 文件路径
 @param data 需要存储的数据
 @param fileName 文件名
 @return NSData 文件中的数据
 */
+ (BOOL)saveData:(NSObject *)data withPath:(NSString *)path fileName:(NSString *)fileName;


/**
 异步存储数据到本地
 @param path 文件路径
 @param data 需要存储的数据
 @param fileName 文件名
 @param callback 完成后的回调
 */
+ (void)asyncSaveData:(NSObject *)data
             withPath:(NSString *)path
             fileName:(NSString *)fileName
             callback:(void(^)(BOOL succeed))callback;

/** @name 删除 */
/**
 删除文件
 @param path 文件路径
 @return 是否删除成功
 */
+ (BOOL)removeFileAtPath:(NSString *)path;

/**
 删除文件目录和目录下的所有文件
 @param path 文件目录路径
 @param condition 文件删除条件判断
 */
+ (void)removeFileAtPath:(NSString *)path condition:(BOOL (^)(NSDictionary *fileInfo))condition;

/**
 删除文件目录和目录下的所有文件
 @param path 文件目录路径
 @param condition 文件删除条件判断
 */
+ (void)asyncRemoveFileAtPath:(NSString *)path condition:(BOOL (^)(NSDictionary *fileInfo))condition;


/** @name 其他 */
/**
 判断该路径是否有文件
 @param path 文件路径
 @return BOOL 是否有文件存在
 */
+ (BOOL)fileExistsAtPath:(NSString *)path;

@end

@interface TYFileManager (TYPahtHelper)

+ (BOOL)createPathIfNecessary:(NSString*)path;

+ (NSString*)documentDirectoryPath;

+ (NSString*)documentDirectoryPathWithName:(NSString*)name;

+ (NSString*)cacheDirectoryPathWithName:(NSString*)name;

@end
