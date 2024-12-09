//
//  TDKIndicatorHelper.h
//  TYUICoreKit
//
//  Created by 史良 on 2021/12/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TDKIndicatorHelper : NSObject


/// 弹出toast指示器
/// @param toast 文案
/// @param alertView 文案视图
+ (void)alertTDKIndicatorToastWith:(NSString *)toast alertview:(UIView *)alertView;


/// 弹出hud指示器
/// @param alertView 文案视图
+ (void)alertTDKIndicatorHUDWithAlertview:(UIView *)alertView;


/// 消失指示器
/// @param alertView 文案视图
+ (void)dissmissTDKIndicatorWith:(UIView *)alertView;;



@end

NS_ASSUME_NONNULL_END
