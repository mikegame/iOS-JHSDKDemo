//
//  AppDelegate.m
//  JHMKSDKDemo
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
    [[JHSDKParameters sharedJHSDKParameters] setSubGameId:1];
    [[JHSDKParameters sharedJHSDKParameters] setApiKey:@"b174bb7124c887547d384bbe11aaaa01"];
    
    // 设置米壳SDK参数
    JHMKSDKInitModel *jhMKSDKInitModel = [JHMKSDKInitModel new];
    [jhMKSDKInitModel setGameId:1];
    [jhMKSDKInitModel setSubGameId:1];
    [jhMKSDKInitModel setApiKey:@"4f76c696869efaa7f84afe5a2d0de332"];
    [jhMKSDKInitModel setGameKey:@"459922aa8968c4a664a988df9749bcba"];
    [jhMKSDKInitModel setTrackKey:@"04e7406bd01299d05dd5528c459bb2f1"];
    [jhMKSDKInitModel setRyChannelID:@"unknown"];
    
    [[JHSDKParameters sharedJHSDKParameters] setJhMKSDKInitModel:jhMKSDKInitModel];
    // 设置当前编译渠道
    [[JHSDKParameters sharedJHSDKParameters] setJhPlatformType:JHMKPlatform];
    
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
