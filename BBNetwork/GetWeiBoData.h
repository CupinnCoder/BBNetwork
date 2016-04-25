//
//  GetWeiBoData.h
//  BBNetwork
//
//  Created by Melvin on 3/17/16.
//  Copyright © 2016 TimeFace. All rights reserved.
//

#import "BBRequest.h"
#import "UserModel.h"

@interface GetWeiBoData : BBRequest

@property (nonatomic ,strong ,readonly) UserModel *userModel;

@end
