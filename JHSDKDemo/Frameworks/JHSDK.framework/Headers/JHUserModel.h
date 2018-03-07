//
//  JHUserModel.h
//  JHSDK
//
//  Created by 熙文 张 on 2018/3/1.
//  Copyright © 2018年 熙文 张. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JHUserModel : NSObject

/**
 *  用户ID
 */
@property (nonatomic, strong) NSString *userId;

/**
 *  用户名
 */
@property (nonatomic, strong) NSString *username;

/**
 *  会话ID
 */
@property (nonatomic, strong) NSString *accessToken;




@end
