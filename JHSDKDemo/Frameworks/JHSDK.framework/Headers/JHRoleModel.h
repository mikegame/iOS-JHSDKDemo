//
//  JHRoleModel.h
//  JHSDK
//
//  Created by 熙文 张 on 2018/3/7.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JHRoleModel : NSObject

/**
 *  服务器Id
 */
@property (nonatomic, strong) NSString *serverId;

/**
 *  服务器名称
 */
@property (nonatomic, strong) NSString *serverName;

/**
 *  角色Id
 */
@property (nonatomic, strong) NSString *roleId;

/**
 *  角色名称
 */
@property (nonatomic, strong) NSString *roleName;

/**
 *  角色等级
 */
@property (nonatomic, assign) NSUInteger roleLevel;

/**
 *  登陆时间
 */
@property (nonatomic, strong) NSString *loginTime;


@end
