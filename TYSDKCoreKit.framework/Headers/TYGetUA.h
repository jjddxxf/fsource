//
//  TYGetUA.h
//  TYSDK
//
//  Created by 周翔宇 on 2019/11/13.
//  Copyright © 2019 刘磊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYGetUA : NSObject
@property (nonatomic,copy) NSString *userAgrntString;
+ (instancetype)sharedManager;

-(void)getUserAgent;
@end

NS_ASSUME_NONNULL_END
