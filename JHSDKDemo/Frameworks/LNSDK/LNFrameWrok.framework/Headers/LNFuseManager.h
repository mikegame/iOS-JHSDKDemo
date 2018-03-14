//
//  LNFuseManager.h
//  LNFrameWrok
//
//  Created by huangsite on 16/4/28.
//  Copyright © 2016年 ln. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LNFuseManager : NSObject

+ (LNFuseManager *)sharedInstance;



- (BOOL)getPushStatus;

- (NSString *)getPushtoken;

- (void)leNiuPushAction;

- (void)leNiuPush;

- (void)leNiuPushSetDeviceTokenFromData:(NSData *)token;

- (void)leNiuPushHandleWithApplication:(UIApplication *)application andNotification:(NSDictionary *)userInfo andIsCheck:(BOOL)check;

- (void)leNiuPushReportWithApplication:(UIApplication *)application andIsCheck:(BOOL)check;


- (NSString *)leNiuChanel;

/**
 *  打开链接
 *
 *  @param url http://
 *
 *  @return
 */

- (void)openWithUrl:(NSString *)url;

/**
 *  应用初始化接口
 *
 *  @param appId
 *
 *  @return
 */
- (void)leNiuInit;

/**
 *  Account模式下登录
 */
- (void)leNiuLogin;

/**
 *  绑定手机
 */
- (void)leNiuBindPhone;

/**
 * 充值
 * @orderid        CP 订单号
 * @productName    商品名称
 * @flag           商品标识
 * @amount         金额（单位：分）
 * @server         服务器标识
 * @rolename       角色名称
 * @level          角色等级
 * @ext            扩展参数
 */

- (void)leNiuCharge:(NSString *)orderid
     andProductName:(NSString *)productName
          andAmount:(NSString *)amount
            andFlag:(NSString *)flag
          andServer:(NSString *)server
        andRolename:(NSString *)rolename
           andLevel:(NSString *)level
             andExt:(NSString *)ext;

/**
 * 收集信息
 * @type            1 创角/2 升级/3 进入服务器
 * @roleid          角色 ID
 * @rolename        角色名
 * @sex             1 男 2 女 0 未知
 * @serverid        服务器标识
 * @balance         剩余元宝，可空
 * @partname        帮派名称，可空
 * @sword           战斗力，可空
 * @mount           坐骑，可空
 * @vip             Vip 等级，可空
 */
- (void)collectRoleInfoWithType:(NSString *)type
                      andRoleid:(NSString *)roleid
                    andRolename:(NSString *)rolename
                       andLevel:(NSString *)level
                         andSex:(NSString *)sex
                    andServerid:(NSString *)serverid
                     andBalance:(NSString *)balance
                    andPartname:(NSString *)partname
                       andSword:(NSString *)sword
                       andMount:(NSString *)mount
                         andVip:(NSString *)vip;

//程序切换后台调用
- (void)LNEnterBackground;

//程序切换回前台调用
- (void)LNEnterForeground;

/**
 *  BUG收集
 */
- (void)collectBUG;

/**
 *  注销
 */
- (void)logout;

- (NSString *)productId;

@end
