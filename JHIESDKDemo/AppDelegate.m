//
//  AppDelegate.m
//  JHIESDKDemo
//
//  Created by 熙文 张 on 2018/3/14.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <JHSDK/JHSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    ViewController *viewController = [ViewController new];
    [self.window setRootViewController:viewController];
    [self.window makeKeyAndVisible];
    [self.window setBackgroundColor:[UIColor whiteColor]];
    
    
    // 设置聚合SDK参数
    [[JHSDKParameters sharedJHSDKParameters] setGameId:1];
    [[JHSDKParameters sharedJHSDKParameters] setSubGameId:121];
    [[JHSDKParameters sharedJHSDKParameters] setApiKey:@"f2aab7b9e3e3e6beb8ad2286911d3456"];
    
    // 设置冰鸟SDK参数
    JHIESDKInitModel *jhIESDKInitModel = [JHIESDKInitModel new];
    [jhIESDKInitModel setAppKey:@"100000000"];
    [jhIESDKInitModel setSignKey:@"8d9da7422e37b95432a2cd4d52173b5c"];
    [jhIESDKInitModel setAppSecret:@"ae879c59f1f732557211b549086a83d6"];
    [jhIESDKInitModel setNotifyUrl:@"https://pay.jh.mikegame.cn/PayNotify/bingniao"];
    [jhIESDKInitModel setApplication:application];
    [jhIESDKInitModel setLaunchOptions:launchOptions];
    [jhIESDKInitModel setIeScreenDirectionType:JHInterfaceOrientationUnknown];
    
    [[JHSDKParameters sharedJHSDKParameters] setJhIESDKInitModel:jhIESDKInitModel];
    // 设置当前编译渠道
    [[JHSDKParameters sharedJHSDKParameters] setJhPlatformType:JHIEPlatform];
    
    [[JHSDK sharedInstance] jhInit:^{
        NSLog(@"聚合SDK初始化成功");
    } failure:^(int errcode, NSString *errorMessage) {
        NSLog(@"聚合SDK初始化失败 - %@", errorMessage);
    }];
    return YES;
}

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
    //    横屏 return UIInterfaceOrientationMaskLandscape
    return UIInterfaceOrientationMaskLandscape;
    //    横屏 return UIInterfaceOrientationMaskPortraitUpsideDown
    //    return UIInterfaceOrientationMaskPortrait;
}



- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    [[JHSDK sharedInstance] jhApplication:application openURL:url options:nil];
    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    
    [[JHSDK sharedInstance] jhApplication:app openURL:url options:options];
    return YES;
}


- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    [[JHSDK sharedInstance] jhApplication:application openURL:url sourceApplication:sourceApplication annotation:annotation];
    return YES;
}


- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    [[JHSDK sharedInstance] jhApplication:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [[JHSDK sharedInstance] jhApplication:application didReceiveRemoteNotification:userInfo];
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    [[JHSDK sharedInstance] jhApplicationWillEnterForeground:application];
}


- (void)applicationWillResignActive:(UIApplication *)application {
    [[JHSDK sharedInstance] jhApplicationWillResignActive:application];
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    [[JHSDK sharedInstance] jhApplicationDidEnterBackground:application];
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    [[JHSDK sharedInstance] jhApplicationDidBecomeActive:application];
}


- (void)applicationWillTerminate:(UIApplication *)application {
    [[JHSDK sharedInstance] jhApplicationWillTerminate:application];
}


@end
