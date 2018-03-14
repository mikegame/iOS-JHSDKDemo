//
//  IEFlash.h
//  IBUnionSDK
//
//  Created by bingniao on 17/8/15.
//  Copyright © 2017年 junhai. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IEagle/IEagle.h>

@interface IEFlash : UIViewController
/** 闪屏时长(默认2s) */
@property (nonatomic, assign) CGFloat flashDuration;

/**
 初始化闪屏

 @param image           闪屏图像
 @param screenDirection 屏幕方向(0-竖屏;1-横屏)
 @param completeHandler 回调方法
 @return 实例
 */
- (instancetype)initWithImage:(UIImage*)image screenDirection:(IEScreenDirectionType)screenDirection completeHandler:(void(^)())completeHandler;

@end
