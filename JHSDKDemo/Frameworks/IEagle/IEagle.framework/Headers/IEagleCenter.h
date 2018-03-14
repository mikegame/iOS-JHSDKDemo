
#import <Foundation/Foundation.h>
#import "IEFuInfo.h"
#import "Constants.h"
#import "IECommon.h"


/**
 *
 * 冰鸟用户、支付系统，调用中心类
 *
 **/

@interface IEagleCenter : NSObject

/**
 * 获取IEagleCenter单例对象
 **/
+ (instancetype)sharedCenter;

/**
 * 初始化SDK接口
 *
 * @param    appKey             冰鸟提供的appKey
 * @param    signKey            冰鸟提供的signKey
 * @param    screenDirection    游戏的横竖屏方向
 **/
- (void)initSDKWithAppKey:(NSString *)appKey signKey:(NSString *)signKey screenDirection:(IEScreenDirectionType)screenDirection;

/**
 * 登录接口
 **/
- (void)startLogin;

/**
 * 二次登录验证接口
 * 登陆两步验证结果回传，收到登陆回调后，请将session_id交由游戏服务器，向我方服务器进行两步验证
 * 验证结果的json请原样转成NSDictionary传入该接口，SDK将做登陆验证
 *
 * @param    userInfo    json解析为NSDictionary后传入,
 *                       或 传入含有IE_ACCESS_TOKEN和IE_UID的NSDictionary
 **/
- (void)onLoginResp:(NSDictionary *)userInfo;

/**
 * 登出接口
 **/
- (void)userLogout;

/**
 * 支付接口
 *
 * @param   fuInfo     订单模型
 **/
- (void)fuWithIEFuInfo:(IEFuInfo *)fuInfo;

/**
 * 用户扩展信息接口
 *
 * @param    action      扩展事件名称
 * @param    userData    用户信息，请务必传入真实信息，具体内容
 *                       IE_ROLE_ID        IE_SERVER_ID      IE_SERVER_NAME
 *                       IE_ROLE_NAME      IE_VIP_LEVEL      IE_PRODUCT_COUNT
 *                       IE_PRODUCT_NAME   IE_ROLE_LEVEL
 **/
- (void)uploadUserData:(IEUploadUserDataAction)action userData:(NSDictionary *)userData;

/**
 * 获取用户信息接口，
 * 该接口在完成登录后调用即可获得用户信息，包含：IE_UID、IE_SESSION_ID、IE_UNAME
 *
 * @return  包括user_id,user_name,access_token的字典(登录完成前将返回nil)
 **/
- (NSDictionary *)getUserInfo;

/**
 * 获取SDK版本号接口
 *
 * @return SDK版本号
 */
- (NSString *)getSDKVersion;


/**
 * 显示/隐藏悬浮窗接口(登录流程后可用)
 */
- (void)onShowFloatWidget;
- (void)onHideFloatWidget;

@end
