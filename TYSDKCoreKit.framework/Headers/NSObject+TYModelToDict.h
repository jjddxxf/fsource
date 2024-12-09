//
//  NSObject+TYModelToDict.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (TYModelToDict)

/**
 *  模型转字典
 *
 *  @return 字典
 */
- (NSDictionary *_Nullable)TYDictionaryFromModel;

/**
 *  带model的数组或字典转字典
 *
 *  @param object 带model的数组或字典转
 *
 *  @return 字典
 */
- (id _Nullable )TYObjectFromObject:(nonnull id)object;

@end
