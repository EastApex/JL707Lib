//
//  EABleManager.h
//  Template
//
//  Created by Aye on 2021/3/15.
//  version: 2022.12.06 

/**

 Demo & SDK
 https://github.com/EastApex/EASDKTool_iOS.git
 
 SDK access documentation
 https://www.showdoc.com.cn/2042713679210858/0
 
 
*/

#define kEASDKVERSION   @"1.1.25"
#define kEASDKBUILD     @"4"
#define kEAAppVersion   [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define kEAAppBulid     [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]





#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "EAPeripheralModel.h"
#import "EABleConfig.h"
#import "EABaseModel.h"
#import <EABluetooth/EAEnum.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN


/// Notification Name:Connect failed
/// 连接失败
#define kNTF_EAConnectStatusFailed              @"EAConnectStatusFailed"

/// Notification Name:Connect succeed
/// 连接成功（已获取服务）
#define kNTF_EAConnectStatusSucceed             @"EAConnectStatusSucceed"

/// Notification Name: Disconnect
/// 断开连接
#define kNTF_EAConnectStatusDisconnect          @"EAConnectStatusDisconnect"

/// Notification Name:Connection attempt succeeded (service not obtained)
/// 尝试连接成功（未获取服务）
#define kNTF_EAConnectStatusSucceedUnGetServer  @"EAConnectStatusSucceedUnGetServer"

/// Connecting
/// 连接中
#define kNTF_EAConnectStatusConnecting          @"EAConnectStatusConnecting"

/// ANCS
#define kNTF_EAEADidUpdateANCSAuthorization     @"EADidUpdateANCSAuthorization"

/// Notification Name: Bluetooth on
/// 蓝牙开启
#define kNTF_EABlePoweredOn                 @"EABlePoweredOn"
/// Notification Name: Bluetooth off
/// 蓝牙关闭
#define kNTF_EABlePoweredOff                @"EABlePoweredOff"

/// Notification Name: Receive a mobile phone message from the watch
/// 收到手表发送的操作手机消息
#define kNTF_EAGetDeviceOpsPhoneMessage     @"EAGetDeviceOpsPhoneMessage"

/// Notification Name: OTA data transmission is complete
/// OTA数据传输完成
#define kNTF_EAOTAAGPSDataFinish            @"EAOTADataFinish"

/// Notification Name: OTA progress
/// OTA进度
#define kNTF_EAOTAAGPSDataing               @"EAOTADataing"


/// Notification Name: OTA progress fail
/// OTA失败
#define kNTF_EAOTAFail                      @"EAOTAFail"


#define kNTF_EAOTAHisResFileKeys            @"EAOTAHisResFileKeys"
#define kNTF_EAOTAHisResFileFail            @"EAOTAHisResFileFail"
#define kNTF_EAOTARespond                   @"EAOTARespond"


/// 杰里连接成功，可以通讯了
#define kNTF_EAJLBleManager_CanCmd           @"EAJLBleManager_CanCmd"


/// 实时数据
/// Real time data
#define kNTF_EARealTimeData                 @"EARealTimeData"

/// App运动实时数据
/// App sport real time data
#define kNTF_EAAppSportRealTime             @"EAAppSportRealTime"

/// 上报启动手表测量结果【id = 48 测量结果）】
/// Report the measurement result of starting the watch [id = 48 measurement result]
#define kNTF_EAAppOpsData                   @"EAAppOpsData"


/// 回复信息
/// ReplayMessage
#define kNTF_EAReplayMessage                @"EAReplayMessage"

/// GPS bug
#define kNTF_EADebugGpsNmeaData             @"EADebugGpsNmeaData"

/// recording completed
#define kNTF_RecordingCompleted             @"EARecordingCompleted"

/// JL7070 Mandatory upgrade
#define kNTF_EAJLNeedForcedOTA             @"EAJLNeedForcedOTA"



#define kKeychainService                    @"com.eastapex.bluetooth"
#define kKeychainDataAccount                @"data_apexwear"


@protocol EABleManagerDelegate <NSObject>


/// Scanning Discovered watch (in real time)
/// 扫描发现的设备 （实时）
/// @param peripheralModel peripheral 设备
- (void)didDiscoverPeripheral:(EAPeripheralModel *)peripheralModel;

@end

/// Bluetooth data Broker
/// 蓝牙数据代理
@protocol EABleManagerDataDelegate <NSObject>

/// Bluetooth data 蓝牙数据
/// @param characteristic characteristic 通道
/// @param error error 错误信息
- (void)updateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

@end


/// Bluetooth data Broker
/// 蓝牙数据代理
@protocol EAJLBleManagerDataDelegate <NSObject>

#pragma mark - 设备特征回调
- (void)eaPeripheral:(CBPeripheral *)peripheral didDiscoverCharacteristicsForService:(CBService *)service ;

#pragma mark - 更新通知特征的状态
- (void)eaPeripheral:(CBPeripheral *)peripheral didUpdateNotificationStateForCharacteristic:(nonnull CBCharacteristic *)characteristic;

#pragma mark - 设备返回的数据 GET
- (void)eaPeripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic;

#pragma mark - 设备断开连接
- (void)eaCentralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral;

#pragma mark - 蓝牙初始化 Callback
- (void)eaCentralManagerDidUpdateState:(CBCentralManager *)central;


@end



typedef void(^InitSuccBlock)(void);

@interface EABleManager : NSObject

/// The bluetooth Settings
/// 蓝牙设置
@property (nonatomic,strong) EABleConfig *bleConfig;

/// Searching for watch Agents
/// 搜索设备代理
@property(nonatomic,weak) id<EABleManagerDelegate> delegate;

/// 杰里
@property(nonatomic,weak) id<EAJLBleManagerDataDelegate> jlDelegate;

/// Watch connection status
/// 连接设备状态
@property(nonatomic,assign) EAConnectStateType connectState;

/// 当前连接的设备
/// Currently connected device
@property (nonatomic, strong, nullable) EAPeripheralModel *eaPeripheralModel;

/// 蓝牙状态
/// Bluetooth status
@property(nonatomic,assign) EABleState bleState;


@property(nonatomic,copy) InitSuccBlock initSuccBlock;

/// The singleton
/// 单例
+ (instancetype)defaultManager;


/**
 
 eaKey is an arbitrary fixed value, and this value is added to the EASDKKEY field of the project's info.plist.
 <key>EASDKKEY</key>
 <string>_______</string>
 
 eaKey为随意固定值，并且添加此值在项目的info.plist的EASDKKEY字段里。
 <key>EASDKKEY</key>
 <string>_______</string>
 
 See：https://github.com/EastApex/EASDKTool_iOS/blob/main/EASDKKEY.jpg
 */
- (void)setEASdkKey:(NSString *)eaKey;

#pragma mark - Equipment related Methods 设备相关方法

/// scan watch
/// 扫描
- (void)scanPeripherals;

/// stop scan watch
/// 停止扫描设备
- (void)stopScanPeripherals;

/// connect watch
/// 连接设备
- (void)connectToPeripheral:(EAPeripheralModel *)peripheralModel;

/// reconnection
/// 重连设备
- (void)reConnectToPeripheral;

/// reconnection（Need the SN number or mac address of the watch）
/// 重连设备（传手表的SN号或者mac address）
- (void)reConnectToPeripheral:(NSString *)sn;

/// reconnection（Need the uuidString of the watch）
/// 重连设备（传手表的uuidString）
- (void)reConnectToPeripheralWithUUIDString:(NSString *)uuidString;

/// Cancel connection
/// 取消连接（连接时可用）
- (void)cancelConnectingPeripheral;

/// Disconnect the watch. Restart the App, and EASDK will automatically connect the watch.
/// 断开手表连接。重启App，EASDK自动连接。
- (void)disconnectPeripheral;


/// Disconnect the watch. Restart the App, EASDK will not automatically connect to the watch.
/// 断开手表连接。重启App，EASDK不会自动连接。
- (void)disconnectAndNotReConnectPeripheral;

/// Disconnect the watch. Restart the App, EASDK will not automatically connect to the watch.
/// 断开手表连接。重启App，EASDK不会自动连接。
- (void)unbindPeripheral DEPRECATED_MSG_ATTRIBUTE("Please use \"disconnectAndNotReConnectPeripheral\"");


/// Disconnect from the watch and reset and clear the watch data.
/// 断开与手表的连接，重置并清除手表数据。
- (void)unbindAndResetPeripheral;



/// Check whether to enable Bluetooth
/// 是否开启蓝牙
- (BOOL)isBleOn;

/// Check whether the watch is connected
/// 是否已连接设备
- (BOOL)isConnected;

/// Gets the connected watch
/// 获取连接的设备信息
- (EAPeripheralModel *)getPeripheralModel;

#pragma mark 分析广播包
- (EAPeripheralModel *)analyseAdvertisementData:(NSDictionary *)advertisementData peripheral:(CBPeripheral *)peripheral  RSSI:( NSNumber *)RSSI;

/// ignore：
- (void)writeValue:(NSData *)Data forCharacteristic:(EACharacteristicType )characteristicType;
- (BOOL)isScanning;
- (BOOL)checkKey;
- (NSString *)getPeripheralId;
/// ignore：Bluetooth data Broker
/// 忽略：蓝牙数据代理
@property(nonatomic,weak) id<EABleManagerDataDelegate> dataDelegate;

@end

NS_ASSUME_NONNULL_END
