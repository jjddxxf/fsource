//
//  XYShareContents.h
//  XYSDK
//
//  Created by 史良 on 2021/6/4.
//  Copyright © 2021 刘磊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYApiShares.h"
#import "XYApiEnumerations.h"

NS_ASSUME_NONNULL_BEGIN

#define  kUIImageKey                @"UIImageKey"
#define  kNSURLKey                  @"NSURLKey"
#define  kPHImageAssetKey           @"PHImageAssetKey"
#define  kPHVideoAssetKey           @"PHVideoAssetKey"
#define  kNSDataKey                 @"NSDataKey"
#define  kXYShareFBImageConfigKey   @"XYShareFBImageConfigKey"
#define  kUserGeneratedKey          @"UserGeneratedKey"
#define  kXYShareFBConfigType       @"kXYShareFBConfigType"
#define  kXYShareFBConfigVideoType  @"kXYShareFBConfigVideoType"
#define  kXYShareFBConfigImageType  @"kXYShareFBConfigImageType"


@interface XYShareFBImageConfig ()
@end
@interface XYShareFBVideoConfig ()
@end


@interface XYShareContents : NSObject
@end

/// 新版分享 基类
@interface XYShareBaseContent()

@property (nonatomic, assign) XYShareChannelType shareChannel;
@property (nonatomic, strong) NSURL * contentUrl;
@property (nonatomic, copy) NSArray * peopleIDs;
@property (nonatomic, copy) NSString * quote;
@property (nonatomic, copy) NSString * hashTagString;
@property (nonatomic, copy) NSString * placeID;
@property (nonatomic, copy) NSString * ref;
@property (nonatomic, copy) NSString * pageID;

@end


/// 文本消息类
@interface XYShareMessageContent ()
@end


/// 图片消息类
@interface XYShareImageContent ()
@property (nonatomic, strong)NSMutableArray<XYShareFBImageConfig *> * fbImageConfigAry;
@end

/// 视频消息类
@interface XYShareVideoContent ()
@property (nonatomic, strong)XYShareFBVideoConfig * videoConfig;
@end


/// 多媒体消息类
@interface XYShareMediaContent ()
@property (nonatomic, strong)NSMutableArray<NSMutableDictionary *> * mediaConfigAry;
@end


NS_ASSUME_NONNULL_END
