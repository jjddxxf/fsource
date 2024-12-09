//
//  TYKeychain.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TYKeychain : NSObject

+ (id)loadValueForKey:(NSString *)keyStr;
+ (id)loadValueForKey:(NSString *)keyStr forAccessGroup:(NSString *)groupStr;

+ (BOOL)deleteValueForKey:(NSString *)keyStr;
+ (BOOL)deleteValueForKey:(NSString *)keyStr forAccessGroup:(NSString *)groupStr;

+ (BOOL)saveValue:(id)value forKey:(NSString *)keyStr;
+ (BOOL)saveValue:(id)value forKey:(NSString *)keyStr forAccessGroup:(NSString *)groupStr;

+ (NSString *)getBundleSeedID;

@end

@interface TYKeychain(TYPrivate)

+ (BOOL)save:(NSString *)keyStr data:(id)data;
+ (BOOL)deleteForKey:(NSString *)keyStr;
+ (id)load:(NSString *)keyStr;

@end

