//  NOT_ANALYSIS_CLASS
//  EAFastGetSnNumber.h
//  EABluetooth
//
//  Created by Aye on 2022/9/22.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
NS_ASSUME_NONNULL_BEGIN

@class CBPeripheral;




#define kWatchServices  @[[CBUUID UUIDWithString:@"8800"],[CBUUID UUIDWithString:@"9900"],[CBUUID UUIDWithString:@"0012"],[CBUUID UUIDWithString:@"0011"],[CBUUID UUIDWithString:@"9008"],[CBUUID UUIDWithString:@"FF10"]]

#define kFastGetClientCode  @"clientCode"
#define kFastGetSn          @"sn"
#define kFastGetJl707       @"jieli707"
@interface EAFastGetSnNumberManager : NSObject




+ (instancetype)defaultManager;


- (NSDictionary *)getSnNumbers;

- (NSArray *)getPairedWatches;

- (void)clear;

@end

NS_ASSUME_NONNULL_END
