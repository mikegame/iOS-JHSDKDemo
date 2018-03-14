//
//  IEagleCenter+IEApplication.h
//  IBUnionSDK
//
//  Created by bingniao on 2017/9/28.
//  Copyright © 2017年 junhai. All rights reserved.
//

#import <IEagle/IEagle.h>

@interface IEagleCenter (IEApplication)

/** application完成启动 */
+ (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
/** application将要进入非活动状态，即将进入后台 */
+ (void)applicationWillResignActive:(UIApplication *)application;
/** application支持后台运行，则应用程序已经进入后台运行 */
+ (void)applicationDidEnterBackground:(UIApplication *)application;
/** application将要进入活动状态，即将进入前台运行 */
+ (void)applicationWillEnterForeground:(UIApplication *)application;
/** application已进入前台，处于活动状态 */
+ (void)applicationDidBecomeActive:(UIApplication *)application;
/** application将要退出 */
+ (void)applicationWillTerminate:(UIApplication *)application;
/** application系统内存不足 */
+ (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;

@end
