//
//  ILiveSDK.h
//  ILiveSDK
//
//  Created by kennethmiao on 16/10/25.
//  Copyright © 2016年 AlexiChen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ImSDK/TIMCallback.h>
#import "ILiveLogTypeDefine.h"

@class QAVContext;
@class TIMManager;



@interface ILiveSDK : NSObject

/**
 获取单例

 @return ILiveSDK 单例
 */
+ (instancetype)getInstance;

/**
 初始化SDK

 @param appId       用户标识接入SDK的应用ID
 @param accountType 用户的账号类型
 */
- (int)initSdk:(int)appId accountType:(int)accountType;

/**
 用户在线状态通知（登录之前设置有效）
 
 @param listener    监听者
 */
- (void)setUserStatusListener:(id<TIMUserStatusListener>)listener;

/**
 连接通知回调（登录之前设置有效）
 
 @param listener    监听者
 */
- (void)setConnListener:(id<TIMConnListener>)listener;

/**
 页面刷新接口（登录之前设置有效）（如有需要未读计数刷新，会话列表刷新等）
 
 @param listener    监听者
 */
- (void)setRefreshListener:(id<TIMRefreshListener>)listener;

/**
 获取版本号

 @return NSString 版本号
 */
- (NSString *)getVersion;

/**
 获取帐号类型

 @return int 帐号类型
 */
- (int)getAccountType;

/**
 获取AppId

 @return int AppId
 */
- (int)getAppId;

#pragma mark 高级功能接口

/**
 获取音视频控制类（登录之后获取有效）

 @return QAVContext 音视频控制类
 */
- (QAVContext *)getAVContext;

/**
 获取IM控制器

 @return TIMManager IM控制器
 */
- (TIMManager *)getTIMManager;

/**
 iLiveSDK模块日志打印

 @param level 日志等级（默认时Debug）
 @param tag 日志模块
 @param msg 日志内容
 */
- (void)iLivelog:(ILiveLogLevel)level tag:(NSString*)tag msg:(NSString*)msg;

/**
 iLiveSDK内部打印日志接口

 @param level 日志等级
 @param tag 日志是否为关键路径或支线路径
 @param msg 错误信息
 @param pos 打印位置
 @param ext 扩展信息
 */
- (void)iLiveLog:(NSString *)tag level:(ILiveLogLevel)level pos:(NSString *)pos msg:(NSString *)msg ext:(NSString *)ext;

/**
 设置日志等级

 @param level 日志等级
 */
- (void)setLogLevel:(ILiveLogLevel)level;

/**
 设置数据上报是否可用

 @param enbanle YES:正常数据上报 NO:不启用数据上报
 */
- (void)setDataReportEnable:(BOOL)enbanle;

/**
 获取数据上报当前状态

 @return YES:正常数据上报 NO:不启用数据上报
 */
- (BOOL)getDataReportEnable;

/**
 获取日志等级

 @return 日志等级
 */
- (ILiveLogLevel)getLogLevel;

/**
 设置控制台日志等级

 @param print YES:打印控制台日志 NO:不打印控制台日志
 */
- (void)setConsoleLogPrint:(BOOL)print;

/**
 日志上报
 
 @param logDesc      日志描述
 @param dayOffset    日期，0-当天，1-昨天，2-前天，以此类推
 @param uploadResult 上报回调
 */
- (void)uploadLog:(NSString *)logDesc logDayOffset:(int)dayOffset uploadResult:(ILiveLogUploadResultBlock)uploadResult;


/**
 将文件进行压缩成zip文件
 
 @param path     生成zip文件地址
 @param directoryPath    要压缩的文件夹
 @return  BOOL   创建成功或失败
 */
- (BOOL)createZipFileAtPath:(NSString *)path withContentsOfDirectory:(NSString *)directoryPath;
@end

