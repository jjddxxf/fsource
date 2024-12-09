//
//  XYApi+Setting.h
//  XYSDK
//
//  Created by 吴国倩 on 2024/7/8.
//  Copyright © 2024 tuyoo. All rights reserved.
//

#import <XYSDK/XYSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYApi (Setting)

#pragma mark - 设置语言环境
+ (void)setlLanguageCode:(XYLanguageCode)languageCode;

#pragma mark - 设置屏幕转向（修改内容：SDK内部所有页面）
+ (void)setUIFaceOrientation:(UIInterfaceOrientationMask)faceOrientation;

@end

NS_ASSUME_NONNULL_END
