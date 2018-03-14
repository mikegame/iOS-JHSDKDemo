//
//  IEObject.h
//  iibsdk-ios_H5
//
//  Created by bingniao on 17/7/3.
//  Copyright © 2017年 ibingniao. All rights reserved.
//

#ifdef _IBN_PROP_H5
#import <Foundation/Foundation.h>
#import "Constants.h"
#import "IECommon.h"

/******** 回调通知信息订阅名称 ********/
extern NSString * const IEJSonInitSuccess;
extern NSString * const IEJSonInitFailed;
extern NSString * const IEJSonLoginSuccess;
extern NSString * const IEJSonLoginFailed;
extern NSString * const IEJSonLoginCancel;
extern NSString * const IEJSonLogoutSuccess;
extern NSString * const IEJSonLogoutFailed;
extern NSString * const IEJSonSwitchSuccess;
extern NSString * const IEJSonSwitchFailed;
extern NSString * const IEJSonLoginRspSuccess;
extern NSString * const IEJSonLoginRspFailed;
extern NSString * const IEJSonCdejaaSuccess;
extern NSString * const IEJSonCdejaaFailed;
extern NSString * const IEJSonCdejaaCancel;
/******** **************** ********/


@class IEFuInfo;
@interface IEObject : NSObject
/** 单例 */
+ (instancetype)sharedObject;

/** url, 可使用KVO监听 */
@property (nonatomic, strong) NSString *siteStr;


/**
 初始化接口
 
 @param orientation 游戏屏幕旋转方向
 @param callbackName 接收回调的函数方法名
 */
- (void)onInit:(IEScreenDirectionType)orientation callbackName:(NSString*)callbackName;


/**
 登录接口: 启动登录界面(已登录过则进行自动登录)
 */
- (void)onLogin;


/**
 登录二次验证接口:
 登录成功后, 将在回调中拿到含有"session_id"的NSDictionary, 请将"session_id"交由游戏服务器，向我方服务器进行两次验证;
 如果二次验证失败情况, 请按顺序先后调用userLogout(), startLogin()回到界面;
 
 @param userInfo 请传入二次验证由 user_id & access_token 组成的字典;
 */
- (void)onLoginRsp:(NSDictionary *)userInfo;


/**
 登出接口
 */
- (void)onLogout;


/**
 支付接口
 
 @param fuInfo 订单实例
 */
- (void)onCdejaa:(NSDictionary *)fuInfo;


/**
 用户扩展信息接口
 @param userInfo 用户信息，请务必传入真实信息，具体内容:
 IE_ROLE_ID        IE_SERVER_ID      IE_SERVER_NAME
 IE_ROLE_NAME      IE_VIP_LEVEL      IE_PRODUCT_COUNT
 IE_PRODUCT_NAME   IE_ROLE_LEVEL
 */
- (void)onLoginRoleInfo:(NSDictionary *)userInfo;
- (void)onUpdateRoleInfo:(NSDictionary *)userInfo;


/**
 获取用户信息接口，该接口在完成登录后调用即可获得用户信息
 
 @return IE_UID、IE_SESSION_ID、IE_UNAME(非法调用将返回nil)
 */
- (NSDictionary *)getUserInfo;


/**
 获取SDK版本号接口
 
 @return SDK版本号
 */
- (NSString *)getSDKVersion;

@end


#else

#import <Foundation/Foundation.h>
@interface IEObject : NSObject
@end

#endif

