//
//  IECommon.h
//  IBUnionSDK
//
//  Created by bingniao on 17/4/22.
//  Copyright © 2017年 junhai. All rights reserved.
//

#ifndef IECommon_h
#define IECommon_h

/** SDK强制旋转方向 */
typedef NS_OPTIONS(NSInteger, IEScreenDirectionType)
{
    IEScreenDirectionUnlimited = -1,
    IEScreenDirectionPortrait = 0,
    IEScreenDirectionLandscape = 1,
};

/** 用户扩展信息动作(GAME/ROLEUPDATE) */
typedef NS_OPTIONS(NSInteger, IEUploadUserDataAction)
{
    IEonEnterServer = 0,
    IEonRoleUpdate = 1,
};

/** 接口版本禁用声明 */
#define IE_DEPRECATED(_version, ...) __attribute__((deprecated("接口已不可用,版本号:"#_version#__VA_ARGS__)))

#endif /* IECommon_h */
