//
//  AppDelegate.h
//  MacClient
//
//  Created by dong da kuan on 2019/12/19.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "TcpConnect.hpp"
#include "MainPage.h"
@interface AppDelegate : NSObject <NSApplicationDelegate>{
        TcpConnect test;
}

@property(nonatomic, retain) IBOutlet NSTextField* username;
@property(nonatomic, retain) IBOutlet NSTextField* password;

- (IBAction)onLogInClick:(id)sender;
- (IBAction)onSignUpClick:(id)sender;
- (IBAction)onFindPassWordClick:(id)sender;
@end



