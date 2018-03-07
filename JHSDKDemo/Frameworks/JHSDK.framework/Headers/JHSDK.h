//
//  JHSDK.h
//  JHSDK
//
//  Created by 熙文 张 on 2018/2/28.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "JHSDKParameters.h"
#import "JHUserModel.h"
#import "JHPayModel.h"
#import "JHSDKInitModel.h"
#import "JHRoleModel.h"


//! Project version number for JHSDK.
FOUNDATION_EXPORT double JHSDKVersionNumber;

//! Project version string for JHSDK.
FOUNDATION_EXPORT const unsigned char JHSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <JHSDK/PublicHeader.h>



typedef void (^jhLoginSuccessBlock)(JHUserModel *userModel);
typedef void (^jhLogoutBlock)(void);
typedef void (^jhFailureBlock)(int errcode, NSString *errorMessage);


@interface JHSDK : NSObject


/**
 *  返回一个静态单例对象
 *
 *  @return 单例对象
 */
+ (JHSDK *)sharedInstance;


/**
 *  获取SDK版本号 eg:1.0.0 三段
 */
- (NSString *)jhSDKVersion;


/**
 * SDK初始化参数对象
 */
@property (nonatomic, strong) JHSDKParameters *jhSdkParameters;

/**
 *  初始化
 *
 *  @param jhSdkParameters     聚合sdk初始化参数对象
 *  @param successBlock        登录成功回调
 *  @param errorBlock          登录失败回调
 */
- (void)jhInitWithSDKParameters:(JHSDKParameters *)jhSdkParameters
                        success:(void (^)(void))successBlock
                        failure:(void (^)(int errcode, NSString *errorMessage))errorBlock;

/**
 *  第三方支付回调
 *
 *  @param app     UIApplication
 *  @param url     NSURL
 *  @param options options
 */
- (void)jhPayResult:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options;

/**
 *  第三方支付回调
 *
 *  @param app     UIApplication
 *  @param url     NSURL
 *  @param sourceApplication sourceApplication
 */
- (void)jhPayResult:(UIApplication *)app openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication;


/**
 *  App从后台恢复至前台
 *
 *  @param application application
 */
- (void)jhWillEnterForeground:(UIApplication *)application;

/**
 *  登陆
 *
 *  @param view         所添加的视图
 *  @param successBlock 登陆成功回调
 *  @param errorBlock   登陆失败回调
 */
- (void)jhLogin:(UIView *)view
       success:(jhLoginSuccessBlock)successBlock
        failure:(void (^)(int errcode, NSString *errorMessage))errorBlock;

/**
 *  用户中心
 */
- (void)jhCenter;

/**
 *  注销
 */
- (void)jhLogout:(jhLogoutBlock)jhLogoutBlock;

/**
 *  支付
 *
 *  @param jhPayModel 订单对象
 */
- (void)jhPay:(JHPayModel *)jhPayModel;


/**
 *  上报角色
 *
 *  @param jhRoleModel    游戏角色
 */
- (void)jhReportRole:(JHRoleModel *)jhRoleModel;


@end
