//
//  HDDevice.h
//  Movie
//
//  Created by wmz on 2023/2/26.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdSupport/AdSupport.h>
#import <sys/utsname.h>
#import <CoreTelephony/CoreTelephonyDefines.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kCTSMSMessageReceivedNotification;
extern NSString* const kCTSMSMessageReplaceReceivedNotification;
extern NSString* const kCTSIMSupportSIMStatusNotInserted;
extern NSString* const kCTSIMSupportSIMStatusReady;
id CTTelephonyCenterGetDefault(void);
void CTTelephonyCenterAddObserver(id,id,CFNotificationCallback,NSString*,void*,int);
void CTTelephonyCenterRemoveObserver(id,id,NSString*,void*);
int CTSMSMessageGetUnreadCount(void);
int CTSMSMessageGetRecordIdentifier(void * msg);
NSString * CTSIMSupportGetSIMStatus(void);
NSString * CTSIMSupportCopyMobileSubscriberIdentity(void);
id CTSMSMessageCreate(void* unknow/*always 0*/,NSString* number,NSString* text);
void * CTSMSMessageCreateReply(void* unknow/*always 0*/,void * forwardTo,NSString* text);
void* CTSMSMessageSend(id server,id msg);
NSString *CTSMSMessageCopyAddress(void *, void *);
NSString *CTSMSMessageCopyText(void *, void *);

@interface HDDevice : NSObject

@property (nonatomic, copy) NSString * token;

@property (nonatomic, copy) NSString * app_version;

@property (nonatomic, copy) NSString * device_name;

@property (nonatomic, copy) NSString * device_model;

@property (nonatomic, copy) NSString * device_system_name;

@property (nonatomic, copy) NSString * device_system_version;

@property (nonatomic, copy) NSString * identifier;

@property (nonatomic, copy) NSString * device_model_name;

@property (nonatomic, copy) NSString * language;

- (NSString *)getIMSIInfo;

@end

NS_ASSUME_NONNULL_END
