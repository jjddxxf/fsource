//
//  NSString+TYProject.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TYProject)


/**
 空
 */
- (BOOL)isEmpty;
/**
 非空
 */
- (BOOL)isNotEmpty;


/**
 md5
 */
- (NSString *)md5;


- (BOOL)checkTel;

@end
