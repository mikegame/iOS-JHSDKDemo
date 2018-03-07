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
@interface JHMkSDKInitModel : NSObject

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

@end
