# 米壳游戏iOS 聚合SDK客户端说明文档
[![License MIT](https://img.shields.io/badge/license-MIT-green.svg?style=flat)](https://raw.githubusercontent.com/mikegame/iOS-JHSDKDemo/master/LICENSE)&nbsp;
[![Support](https://img.shields.io/badge/support-iOS%208%2B%20-blue.svg?style=flat)](https://www.apple.com/nl/ios/)&nbsp;


[点击查看更新日志](https://github.com/mikegame/iOS-JHSDKDemo/blob/master/JHSDKVerisonReadMe.txt "Title")
==============

演示项目
==============
查看并运行 `JHSDKDemo/JHSDKDemo.xcodeproj`


使用
==============


1. 下载 JHSDKDemo 文件夹内的所有内容。<br/>
<img src="https://github.com/mikegame/iOS-JHSDKDemo/blob/master/Snapshots/FrameworkPath.png"><br/>
2. 将 Frameworks 内的MKSDK.framework和MKSDK.xcassets添加(拖放)到你的工程目录中。
<img src="https://github.com/mikegame/iOS-JHSDKDemo/blob/master/Snapshots/Framework.png"><br/>
3. 在对应项目Targets下找到General。<br/>
在Deployment Info根据游戏需要，自行限制横屏还是竖屏。并且在AppDelegate入口限制方向<br/>
```
- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
    return UIInterfaceOrientationMaskPortrait;
}
```
4. 勾选 Hide status bar 和requires full screen，并且在info.plist下加View controller-based status bar appearance 设置为NO
并且在Embedded Binaries和Linked Frameworks and Libraries链接 frameworks:
<img src="https://github.com/mikegame/iOS-JHSDKDemo/blob/master/Snapshots/FrameworkLink.png"><br/>

5. 导入 `<JHSDK/JHSDK.h>`。
```
#import <JHSDK/JHSDK.h>
```
6. 初始化SDK。并更改对应的参数

#### 初始化SDK `初始化方法要写在[self.window makeKeyAndVisible]方法之后`

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    // 设置聚合SDK参数
    [[JHSDKParameters sharedJHSDKParameters] setGameId:1];
    [[JHSDKParameters sharedJHSDKParameters] setSubGameId:1];
    [[JHSDKParameters sharedJHSDKParameters] setApiKey:@"b174bb7124c887547d384bbe11aaaa01"];
    
    /**
     *  设置渠道SDK参数
     */
     
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

    return YES;
}
```

#### 获取SDK版本号

```objective-c
    [[JHSDK sharedInstance] jhSDKVersion];
```

#### 登陆方法

```objective-c
- (void)loginButtonClick
{
    [[JHSDK sharedInstance] jhLogin:self.view success:^(JHUserModel *userModel) {
        NSString *userId    = userModel.userId;
        NSString *userName  = userModel.username;
        NSString *accessToken = userModel.accessToken;

        NSLog(@"聚合登录成功：");
        NSLog(@"userId      -- %@", userId);
        NSLog(@"userName    -- %@", userName);
        NSLog(@"accessToken -- %@", accessToken);


        NSDate *date = [NSDate date];
        NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
        [formatter setDateStyle:NSDateFormatterMediumStyle];
        [formatter setTimeStyle:NSDateFormatterShortStyle];
        [formatter setDateFormat:@"YYYY-MM-dd hh:mm:ss"];
        NSString *dateTime = [formatter stringFromDate:date];

        //登录成功后或者每次角色发生改变时（等级发生改变）调用上报角色信息
        JHRoleModel *roleModel = [JHRoleModel new];
        [roleModel setServerId:@"serverId1"];
        [roleModel setServerName:@"紫陌红尘"];
        [roleModel setRoleId:@"9527"];
        [roleModel setRoleName:@"伊泽瑞尔"];
        [roleModel setRoleLevel:1];
        [roleModel setLoginTime:dateTime];
        [[JHSDK sharedInstance] jhReportRole:roleModel];
    } failure:^(int errcode, NSString *errorMessage) {
        NSLog(@"聚合登录失败：%d -- %@", errcode, errorMessage);
    }];
}
```

#### 支付方法

```objective-c
- (void)payButtonClick
{
    JHPayModel *jhPayModel = [JHPayModel new];
    CFUUIDRef uuidRef = CFUUIDCreate(kCFAllocatorDefault);
    NSString *orderId = (NSString *)CFBridgingRelease(CFUUIDCreateString(kCFAllocatorDefault, uuidRef));
    jhPayModel.cpOrderId = orderId;
    jhPayModel.serverId = @"服务器编号";
    //支付金额 单位 分
    jhPayModel.totalFee = 1;
    jhPayModel.roleId = @"游戏角色编号";
    jhPayModel.roleName = @"游戏角色名称";
    jhPayModel.productId = @"com.mk.mksdkdemo1.6";
    jhPayModel.productName = @"98K";
    jhPayModel.productDescription = @"Kar 98k毛瑟步枪，由Gew 98毛瑟步枪改进而来";
    jhPayModel.customInfo = @"来表演一波15倍镜98k爆头";
    [[JHSDK sharedInstance] jhPay:jhPayModel];
}
```



#### 用户注销方法

```objective-c
- (void)logOutButtonClick
{
    [[JHSDK sharedInstance] jhLogout:^{
        NSLog(@"聚合SDK注销成功");
    }];
}
```


#### 用户中心方法
```objective-c
- (void)centerButtonClick
{
    [[JHSDK sharedInstance] jhCenter];
}
```

#### 支付或事件回调
```objective-c
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
```




渠道接入
==============

#### 米壳SDK

1、将MKSDK.framework添加到Embedded Binaries下。并且将资源文件MKSDK.xcassets导入到工程项目中。
2、info.plist在Source Code视图下加入如下属性
```
<key>NSPhotoLibraryAddUsageDescription</key>
<string>需要获取您的相册权限用以保存账号密码</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>需要获取您的相册权限用以保存账号密码</string>
<key>UIRequiredDeviceCapabilities</key>
```



注意
==============
1、项目编译build Settings 的Base SDK选当前最新的版本。至少iOS11以上。不然会出现一些比较奇怪的问题。


系统要求
==============
该项目最低支持 `iOS 8.0` 和 `Xcode 7.0`。



许可证
==============
MKSDK 使用 MIT 许可证，详情见 LICENSE 文件。

