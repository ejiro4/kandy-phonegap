//
//  KandyUtil.h
//  Kandy
//
//  Created by Srinivasan Baskaran on 5/11/15.
//
//

#import <Foundation/Foundation.h>
#import <KandySDK/KandySDK.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>

typedef void (^successResponse)(CLLocation* location);
typedef void (^failureResponse)(NSError* error);

typedef void (^successAttachmentOPtions) (NSInteger index);
// Kandy PhoneGap Plugin String

extern NSString *kandy_error_message;
extern NSString *kandy_login_login_success;
extern NSString *kandy_login_logout_success;
extern NSString *kandy_login_empty_username_text;
extern NSString *kandy_login_empty_password_text;

extern NSString *kandy_calls_local_video_label;
extern NSString *kandy_calls_checkbox_label;
extern NSString *kandy_calls_state_video_label;
extern NSString *kandy_calls_state_audio_label;
extern NSString *kandy_calls_state_calls_label;
extern NSString *kandy_calls_hold_label;
extern NSString *kandy_calls_unhold_label;
extern NSString *kandy_calls_mute_label;
extern NSString *kandy_calls_unmute_label;
extern NSString *kandy_calls_video_label;
extern NSString *kandy_calls_novideo_label;
extern NSString *kandy_calls_call_button_label;
extern NSString *kandy_calls_hangup_button_label;
extern NSString *kandy_calls_receiving_video_state;
extern NSString *kandy_calls_sending_video_state;
extern NSString *kandy_calls_audio_state;
extern NSString *kandy_calls_phone_number_hint;
extern NSString *kandy_calls_invalid_phone_text_msg;
extern NSString *kandy_calls_invalid_domain_text_msg;
extern NSString *kandy_calls_invalid_hangup_text_msg;
extern NSString *kandy_calls_invalid_hold_text_msg;
extern NSString *kandy_calls_invalid_mute_call_text_msg;
extern NSString *kandy_calls_invalid_video_call_text_msg;
extern NSString *kandy_calls_attention_title_text;
extern NSString *kandy_calls_full_user_id_message_text;
extern NSString *kandy_calls_answer_button_label;
extern NSString *kandy_calls_ignore_incoming_call_button_label;
extern NSString *kandy_calls_reject_incoming_call_button_label;
extern NSString *kandy_calls_incoming_call_popup_message_label;
extern NSString *kandy_calls_remote_video_label;
extern NSString *kandy_chat_phone_number_verification_text;

extern NSString * const kandyFileTypes[];
NSString * const kandyMessageType[];

//Chat - Attachment
typedef enum {
    image = 0,
    video,
    audio,
    location,
    contact
}ChatAttachementType;

typedef enum {
    CONTACT_PICKER_RESULT = 1001,
    IMAGE_PICKER_RESULT = 1002,
    VIDEO_PICKER_RESULT = 1003,
    AUDIO_PICKER_RESULT = 1004,
    FILE_PICKER_RESULT = 1005,
}ChatAttachementResult;

extern NSString * METHOD;
extern NSString * PARAMS;
extern NSString * EXTRAPARAM;

typedef enum {
    CONFIG = 0,
    APIKEY,
    SETHOST,
    GETHOST,
    REPORT,
    REQUEST,
    VALIDATE,
    DEACTIVE,
    USERDETAILS,
    LOGIN,
    TOKENLOGIN,
    LOGOUT,
    CONSTATE,
    SESSION,
    VOIP,
    PSTN,
    SIP,
    SHOWLVIDEO,
    SHOWRVIDEO,
    HIDELVIDEO,
    HIDERVIDEO,
    HANGUP,
    MUTE,
    UNMUTE,
    HOLD,
    UNHOLD,
    EVIDEO,
    DVIDEO,
    SWITCHCAMERA,
    SPEAKERONOFF,
    TRANSFERCALL,
    ACCEPT,
    REJECT,
    IGNORE,
    INCALL,
    GSMCALL,
    USERPROFILE,
    CHAT,
    SMS,
    PAUDIO,
    SAUDIO,
    PVIDEO,
    SVIDEO,
    PIMAGE,
    SIMAGE,
    PCONTACT,
    SCONTACT,
    SCURRENTLOC,
    SLOC,
    OPENATTACHMENT,
    SENDATTACHMENT,
    DOWNLOADMEDIA,
    CANCELMEDIA,
    ACKNOWLEDGE,
    PULL,
    PULLHISTORY,
    PULLALLMESSAAGE,
    CREATEGROUP,
    MYGROUP,
    GROUPBYID,
    UPGROUPNAME,
    UPGROUPIMG,
    RMGROUPIMG,
    DOWNGROUPIMG,
    DOWNGROUPTHUMB,
    MUTEGROUP,
    UNMUTEGROUP,
    DELGROUP,
    LEAVEGROUP,
    RMPARTICIPANTS,
    MUTEPARTICIPANTS,
    UNMUTEPARTICIPANTS,
    ADDPARTICIPANTS,
    LASTSEEN,
    STARTPRESENCE,
    STOPPRESENCE,
    UPDATEPRESENCE,
    COUNTRYINFO,
    GETCURRENTLOC,
    ENABLE,
    DISABLE,
    DEVICECONTACT,
    DOMAINCONTACTS,
    FILTER,
    PERSONALADDBOOK,
    ADDCONTACT,
    REMOVECONTACT,
    UPDATEDEVICEPROFILE,
    USERDEVICEPROFILE,
    USERCREDIT,
    UPLOADMEDIA,
    DOWNLOADCLOUD,
    DOWNLOADMEDIATHUMB,
    CANCELCLOUDMEDIA
} KandyPluginServices;


@protocol KandyEventProtocol;
@interface KandyUtil : NSObject

@property (nonatomic) NSDictionary *kandyServices;
@property (nonatomic) NSDictionary *presenceStatus;

+ (KandyUtil *) sharedInstance;
+ (KandyRecord *) getRecipientKandyRecord:(NSString *)recipient;
+ (NSString *) saveImage:(UIImage *)image;
+ (void) saveAudioVideo:(NSData *)data;
+ (void) saveAPIKey:(NSString *)key secret:(NSString *)secret;
+ (NSDictionary *) dictionaryWithKandyGroup:(KandyGroup *)group;
+ (NSDictionary *) dictionaryWithKandyRecord:(KandyRecord *)record;
+ (KandyRecord *) recordWithGroupID:(NSString *)groupid;
+ (KandyChatMessage *) KandyMessageFromUUID:(NSString *)uuid;
+ (NSDictionary *) dictionaryWithTransferProgress:(KandyTransferProgress *)progress;
+ (NSDictionary *) dictionaryFromKandyCall:(id<KandyCallProtocol>)kandyCall;
+ (void) presentModalViewContriller:(id)viewcontroller;
+ (NSArray *)parseParticipants:(NSArray *)participants;
+ (void) saveHostURL:(NSString *)url;
+ (NSString *) getHostURL;
- (void) ringIn;
- (void) ringOut;
- (void) stopRingIn;
- (void) stopRingOut;
+ (NSString *) getDomainAPIKey;
+ (NSString *) getDomainSecrect;
+ (BOOL) validateInputParam:(NSArray *)params withRequiredInputs:(int)input;
+ (NSString *)documentsDirectory;
- (void) getCurrentLocationUsingBlcok:(successResponse)success andFailure:(failureResponse)failure;
- (void) showAttachmentOptionsUsingBlock:(successAttachmentOPtions)success;
- (NSArray *) enumerateContactDetails:(NSArray *)kandyContacts;
@end
