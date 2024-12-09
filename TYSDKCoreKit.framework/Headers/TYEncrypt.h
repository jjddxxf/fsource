//
//  TYEncrypt.h
//  TYSDK
//
//  Created by 戴晨惜 on 2017/12/5.
//  Copyright © 2017年 戴晨惜. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TYGTMBase64.h"

@interface TYEncrypt : NSObject

+ (NSString *)encryptStringUseBase64:(NSString *)clearText;

+ (NSDictionary *)encryptParametersWithDict:(NSDictionary *)dict;

+ (NSDictionary *)encryptParametersWithoutNiCi:(NSDictionary *)dict;

+ (NSString *)desNicaiAndBase64:(NSString *)originalStr;

+ (NSString *)decNicaiAndBase64:(NSString *)originalStr;

+ (NSString *)md5:(NSString *)str;

+ (NSString *)signatureParametersWithDict:(NSDictionary *)dic secret_key:(NSString *)secret_key;

@end


@interface NSString (sha256)

//SHA256加密
- (NSString*)sha256;
@end

@interface NSString(NICAI)

- (NSString *)nicaiString;

- (NSString *)xor_String;

- (NSString *)xor_DecString;

@end

@interface NSData(NICAI)

- (NSData *)xor_decrypt;

- (NSData *)xor_encrypt;

@end
