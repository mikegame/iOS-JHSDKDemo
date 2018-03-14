//
//  ViewController.m
//  JHLNSDKDemo
//
//  Created by 熙文 张 on 2018/3/14.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import "ViewController.h"
#import <JHSDK/JHSDK.h>

@interface ViewController ()
{
    UIImageView *_bgImageView;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    NSLog(@"聚合SDK版本%@", [[JHSDK sharedInstance] jhSDKVersion]);
    [super viewDidLoad];
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    UIImageView *bgImageView = [UIImageView new];
    //    [bgImageView setContentMode:UIViewContentModeScaleAspectFit];
    [bgImageView setContentMode:UIViewContentModeScaleAspectFill];
    if (UIInterfaceOrientationIsLandscape(orientation))
    {
        [bgImageView setImage:[UIImage imageNamed:@"BG1_L"]];
    }
    else
    {
        [bgImageView setImage:[UIImage imageNamed:@"BG1"]];
    }
    [bgImageView setFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    [self.view addSubview:bgImageView];
    _bgImageView = bgImageView;
    
    
    UIImage *buttonImage = [UIImage imageNamed:@"Button_Normal"];
    UIImage *buttonImageHighlighted = [UIImage imageNamed:@"Button_Highlighted"];
    
    
    UIButton *loginButton = [UIButton new];
    [loginButton setFrame:CGRectMake(140, 100, 100, 36)];
    [loginButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [loginButton setBackgroundImage:buttonImage forState:UIControlStateNormal];
    [loginButton setBackgroundImage:buttonImageHighlighted forState:UIControlStateHighlighted];
    [loginButton setTitle:@"登 陆" forState:UIControlStateNormal];
    [loginButton addTarget:self action:@selector(loginButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:loginButton];
    
    
    UIButton *payButton = [UIButton new];
    [payButton setFrame:CGRectMake(140, 160, 100, 36)];
    [payButton setTitle:@"买个表" forState:UIControlStateNormal];
    [payButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [payButton setBackgroundImage:buttonImage forState:UIControlStateNormal];
    [payButton addTarget:self action:@selector(payButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:payButton];
    
    UIButton *logOutButton = [UIButton new];
    [logOutButton setFrame:CGRectMake(140, 220, 100, 36)];
    [logOutButton setTitle:@"注 销" forState:UIControlStateNormal];
    [logOutButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [logOutButton setBackgroundImage:buttonImage forState:UIControlStateNormal];
    [logOutButton addTarget:self action:@selector(logOutButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:logOutButton];
    
    
    UIButton *centerButton = [UIButton new];
    [centerButton setFrame:CGRectMake(140, 280, 100, 36)];
    [centerButton setTitle:@"用户中心" forState:UIControlStateNormal];
    [centerButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [centerButton setBackgroundImage:buttonImage forState:UIControlStateNormal];
    [centerButton addTarget:self action:@selector(centerButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:centerButton];
    
    
}


#pragma mark --支付按钮事件--
- (void)payButtonClick
{
    JHPayModel *jhPayModel = [JHPayModel new];
    CFUUIDRef uuidRef = CFUUIDCreate(kCFAllocatorDefault);
    NSString *orderId = (NSString *)CFBridgingRelease(CFUUIDCreateString(kCFAllocatorDefault, uuidRef));
    jhPayModel.cpOrderId = orderId;
    //支付金额 单位 分
    jhPayModel.serverId = @"1";
    //支付金额 单位 分
    jhPayModel.totalFee = 1;
    jhPayModel.roleId = @"游戏角色编号";
    jhPayModel.roleName = @"游戏角色名称";
    jhPayModel.roleLevel = @"10";
    jhPayModel.productId = @"com.mk.mksdkdemo1.6";
    jhPayModel.productName = @"98K";
    jhPayModel.productDescription = @"Kar 98k毛瑟步枪，由Gew 98毛瑟步枪改进而来";
    jhPayModel.customInfo = @"来表演一波15倍镜98k爆头";
    [[JHSDK sharedInstance] jhPay:jhPayModel success:^{
        NSLog(@"聚合支付成功");
    } failure:^(int errcode, NSString *errorMessage) {
        NSLog(@"聚合支付失败 - %@", errorMessage);
    }];
}


#pragma mark --登陆按钮事件--
- (void)loginButtonClick
{
    [[JHSDK sharedInstance] jhLogin:self.view success:^(JHUserModel *userModel) {
        NSString *userId    = userModel.userId;
        NSString *accessToken = userModel.accessToken;
        
        NSLog(@"聚合登录成功：");
        NSLog(@"userId      -- %@", userId);
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


- (void)centerButtonClick
{
    [[JHSDK sharedInstance] jhCenter];
}


- (void)logOutButtonClick
{
    [[JHSDK sharedInstance] jhLogout:^{
        NSLog(@"聚合SDK注销成功");
    }];
}


- (NSString *)getOrderStringByTime
{
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"YYYYMMddhhmmssSS"];
    NSString *dateString = [dateFormatter stringFromDate:date];
    NSLog(@"order:%@", dateString);
    return dateString;
}




- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
    [_bgImageView setFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    if (UIInterfaceOrientationIsPortrait(toInterfaceOrientation)) {
        [_bgImageView setImage:[UIImage imageNamed:@"BG1"]];
    }else if (UIInterfaceOrientationIsLandscape(toInterfaceOrientation)) {
        [_bgImageView setImage:[UIImage imageNamed:@"BG1_L"]];
    }
}

@end

