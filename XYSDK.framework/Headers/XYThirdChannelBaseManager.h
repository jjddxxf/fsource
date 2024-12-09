//
//  XYThirdChannelBaseManager.h
//  XYSDK
//
//  Created by 吴国倩 on 2024/9/4.
//  Copyright © 2024 tuyoo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XYSDK/XYThirdChannelBasePorvider.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYThirdChannelBaseManager : NSObject

+ (XYThirdChannelBaseManager *)defaultManager;

- (void)registerChannelWith:(Class<XYThirdChannelBasePorvider>)channel;

- (NSDictionary *)getDesChannelReportDict;

@end

NS_ASSUME_NONNULL_END
