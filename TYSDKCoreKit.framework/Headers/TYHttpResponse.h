//
//  TYHttpResponse.h
//  TYSDKCoreKit
//
//  Created by 史良 on 2022/3/25.
//  Copyright © 2022 周翔宇. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYHttpResponse : NSObject


/// 快速判断 code=0为yes
@property (nonatomic, assign, readonly, getter=isSuccess) BOOL success;

/// 业务处理结果 通常0成功
@property (nonatomic, assign) int code;

/// 错误描述 优先取服务端info
@property (nonatomic, copy) NSString * msg;

/// 返回内容
@property (nonatomic, assign) id respObj;

/// 非200
@property (nonatomic, assign) BOOL httpError;


/// 创建返回层数据
/// @param obj http返回的原始数据
+ (TYHttpResponse *)createResponseWith:(id)obj;


@end

NS_ASSUME_NONNULL_END
