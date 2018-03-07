//
//  JHSDKParameters.h
//  JHSDK
//
//  Created by 熙文 张 on 2018/3/1.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHSDKInitModel.h"


typedef NS_ENUM(NSInteger, JHPlatformType) {
    JHPlatformUnknown = 0,
    JHMKPlatform      = 1,          //米壳
};

@interface JHSDKParameters : NSObject

/**
 *  合作商编号
 */
@property (nonatomic, assign) int gameId;

/**
 *  游戏密钥
 */
@property (nonatomic, assign) int subGameId;

/**
 *  游戏密钥
 */


/**
 *  游戏密钥
 */
@property (nonatomic, strong) NSString *apiKey;

/**
 *  设置为 YES 时，控制台会显示网络请求的数据；设置为 NO 时，控制台不会有网络请求的数据显示
 */
@property (nonatomic, assign) BOOL      debug;


/**
 * @brief 支付宝支付，SSO回调到游戏， 该字段必传，游戏方需要在plist文件中定义 URL Scheme, 传入appScheme
 */

@property (nonatomic, copy) NSString *appScheme;


/**
 *  设置为 YES 时，关闭充值功能；设置为 NO 时，打开充值功能
 */
@property (nonatomic, assign) BOOL closeRecharge;


/**
 *  关闭充值功能的提示语
 */
@property (nonatomic, retain) NSString *closeRechargeAlertMessage;

/**
 *  检查游戏版本更新升级，若检查更新失败（网络错误或因后台报错）是否继续游戏，建议传YES(即：继续游戏，可能跳过强制更新），可根据版本需要传
 */
@property (nonatomic, assign) BOOL  isContinueWhenCheckUpdateFailed;


/**
 *  SDK初始化渠道
 */
@property (nonatomic, assign) JHPlatformType jhPlatformType;

/**
 *  米壳SDK初始化参数对象
 */
@property (nonatomic, strong) JHMkSDKInitModel *jhMkSDKInitModel;

/**
 *  获取JHSDKParameters单例
 *
 *  @return sharedJHSDKParameters单例对象
 */
+ (JHSDKParameters *)sharedJHSDKParameters;
@end
