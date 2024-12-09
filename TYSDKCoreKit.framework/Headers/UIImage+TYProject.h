//
//  UIImage+TYProject.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/6.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (TYProject)

/**
 *  压缩到 20k
 */
- (UIImage *)CompressionImage;

/**
 *  压缩图片大小到 ( bit ) 原比例
 */
- (UIImage *)CompressionImageToSize:(NSInteger )size;

// 按大小压缩
- (UIImage*)imageWithSize:(CGSize)newSize;

@end
