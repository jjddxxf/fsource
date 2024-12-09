//
//  TYUpLoadImage.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/19.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^TYSelectImageBlock)(UIImage *img);
@interface TYUpLoadImage : NSObject

@property(nonatomic, copy) TYSelectImageBlock block;

- (void)selectImageWithUpLoad:(TYSelectImageBlock)block;
- (void)selectImageWithUpLoad;

@end
