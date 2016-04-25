//
//  NSData+CPNGZIP.h
//  CPNetWork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (BBNGZIP)

- (nullable NSData *)bbn_gzippedDataWithCompressionLevel:(float)level;
- (nullable NSData *)bbn_gzippedData;
- (nullable NSData *)bbn_gunzippedData;
- (BOOL)bbn_isGzippedData;

@end
