//
//  IEFuInfo.h
//  AgentStaticLib
//
//  Created by 君海小mini on 15/9/1.
//  Copyright (c) 2015年 junhai. All rights reserved.
//


/**
 * 商品参数尤为重要，以下是例子
 * 例：充值10元，100钻石
 * productName = @“钻石”;
 * productCount = @"100";
 * fuQian = 1000;
 * rate = 10;
 **/

@interface IEFuInfo : NSObject <NSCoding, NSCopying>

@property (nonatomic, copy)   NSString *orderId;//订单号
@property (nonatomic, copy)   NSString *productId;//商品ID
@property (nonatomic, copy)   NSString *productName;//商品名称
@property (nonatomic, assign) NSUInteger productCount;//商品数量
@property (nonatomic, assign) NSUInteger fuQian;//总金额，单位为分
@property (nonatomic, assign) NSUInteger serverId;//区服id
@property (nonatomic, copy)   NSString *serverName;//区服名称
@property (nonatomic, copy)   NSString *roleId;//角色id
@property (nonatomic, copy)   NSString *roleName;//角色名
@property (nonatomic, assign) NSUInteger rate;//兑换比例，即1元可以买多少商品
@property (nonatomic, copy)   NSString *productDesc;//订单详情信息
@property (nonatomic, copy)   NSString *notifyUrl;//充值回调地址
@property (nonatomic, copy)   NSString *appleProductId;//苹果后台申请到的商品编码

@end
