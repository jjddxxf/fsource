//
//  XYThirdChannelBasePorvider.h
//  XYSDK
//
//  Created by 吴国倩 on 2024/9/24.
//  Copyright © 2024 tuyoo. All rights reserved.
//

// XYThirdChannelBasePorvider.h
#import <Foundation/Foundation.h>

@protocol XYThirdChannelBasePorvider <NSObject>

+ (nonnull NSString *)getTDKVersion;
+ (nonnull NSString *)getChannelVersion;
+ (nonnull NSString *)getChannelName;

@end
