//
//  ViewController.m
//  BBNetwork
//
//  Created by Gary on 4/25/16.
//  Copyright © 2016 Gary. All rights reserved.
//

#import "ViewController.h"
#import "RegisterUser.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}




- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    RegisterUser *registerUser = [[RegisterUser alloc] initWithUsername:@"" password:@""];
    [registerUser startWithCompletionBlockWithSuccess:^(__kindof BBBaseRequest *request) {
        NSLog(@"request:%@",registerUser.responseObject);
    } failure:^(__kindof BBBaseRequest *request) {
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
