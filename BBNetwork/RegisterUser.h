//
//  RegisterUser.h
//  BBNetwork
//
//  Created by Melvin on 3/17/16.
//  Copyright © 2016 TimeFace. All rights reserved.
//

#import "BBRequest.h"

@interface RegisterUser : BBRequest

- (id)initWithUsername:(NSString *)username password:(NSString *)password;

@end
