//
//  FDSDKInitModel.h
//  JHSDK
//
//  Created by 熙文 张 on 2018/3/1.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface JHSDKInitModel : NSObject

@end


/**
 *  米壳游戏初始化参数
 */
@interface JHMKSDKInitModel : NSObject

/**
 *  游戏编号
 */
@property (nonatomic, assign) int gameId;

/**
 *  游戏渠道
 */
@property (nonatomic, assign) int subGameId;

/**
 *  游戏密钥
 */
@property (nonatomic, strong) NSString *apiKey;


/**
 *  热云运营KEY
 */
@property (nonatomic, strong) NSString *gameKey;


/**
 *  热云广告KEY
 */
@property (nonatomic, strong) NSString *trackKey;

/**
 *  热云渠道ID
 */
@property (nonatomic, strong) NSString *ryChannelID;

@property (nonatomic, copy) id jhLogoutBlock;

@end


/**
 *  乐牛游戏初始化参数
 */
@interface JHLNSDKInitModel : NSObject


/**
 *  程序入口application
 */
@property (nonatomic, strong) UIApplication *application;


@end



/**
 *  冰鸟游戏初始化参数
 */
@interface JHIESDKInitModel : NSObject

/**
 *  冰鸟提供的appKey
 */
@property (nonatomic, strong) NSString *appKey;


/**
 *  冰鸟提供的signKey
 */
@property (nonatomic, strong) NSString *signKey;


/**
 *  冰鸟提供的appSecret
 */
@property (nonatomic, strong) NSString *appSecret;


/**
 *  程序入口application
 */
@property (nonatomic, strong) UIApplication *application;


/**
 *  程序入口launchOptions
 */
@property (nonatomic, strong) NSDictionary *launchOptions;


/**
 *  支付通知地址
 */
@property (nonatomic, strong) NSString *notifyUrl;


/**
 *  1横屏 ，0竖屏
 */
@property (nonatomic, assign) int ieScreenDirectionType;



@end

