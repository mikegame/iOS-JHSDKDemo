//
//  AppDelegate.m
//  JHSDKDemo
//
//  Created by 熙文 张 on 2018/3/7.
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
    JHMkSDKInitModel *jhMkSDKInitModel = [JHMkSDKInitModel new];
    [jhMkSDKInitModel setGameId:1];
    [jhMkSDKInitModel setSubGameId:1];
    [jhMkSDKInitModel setApiKey:@"4f76c696869efaa7f84afe5a2d0de332"];
    [jhMkSDKInitModel setGameKey:@"459922aa8968c4a664a988df9749bcba"];
    [jhMkSDKInitModel setTrackKey:@"04e7406bd01299d05dd5528c459bb2f1"];
    [jhMkSDKInitModel setRyChannelID:@"unknown"];
    [[JHSDKParameters sharedJHSDKParameters] setJhMkSDKInitModel:jhMkSDKInitModel];
    // 设置当前编译渠道
    [[JHSDKParameters sharedJHSDKParameters] setJhPlatformType:JHMKPlatform];
    
    
    [[JHSDK sharedInstance] jhInitWithSDKParameters:[JHSDKParameters sharedJHSDKParameters] success:^{
        NSLog(@"聚合SDK初始化成功");
    } failure:^(int errcode, NSString *errorMessage) {
        NSLog(@"聚合SDK初始化失败");
    }];
    
    //    [[JHSDK sharedInstance] jhInitWithSDKParameters:[JHSDKParameters sharedJHSDKParameters] success:nil failure:nil];
    
    return YES;
}



- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url
{
    [[JHSDK sharedInstance] jhPayResult:application openURL:url options:nil];
    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options{
    
    [[JHSDK sharedInstance] jhPayResult:app openURL:url options:options];
    return YES;
}


- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    [[JHSDK sharedInstance] jhPayResult:application openURL:url sourceApplication:sourceApplication];
    return YES;
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [[JHSDK sharedInstance] jhWillEnterForeground:application];
}

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
//        横屏 return UIInterfaceOrientationMaskLandscape
        return UIInterfaceOrientationMaskLandscape;
//        横屏 return UIInterfaceOrientationMaskPortraitUpsideDown
//        return UIInterfaceOrientationMaskAllButUpsideDown;
}



- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}





- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
