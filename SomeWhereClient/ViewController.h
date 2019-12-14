//
//  ViewController.h
//  SomeWhereClient
//
//  Created by dong da kuan on 2019/10/28.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>

#include "TcpConnect.hpp"
#include "SomeHeader.h"

@interface ViewController : NSViewController{
    TcpConnect test;
    

}
@property(nonatomic, retain)IBOutlet NSTextField* username;
@property(nonatomic, retain)IBOutlet NSTextField* password;

- (IBAction)onLogInClick:(id)sender;
- (IBAction)onSignUpClick:(id)sender;
- (IBAction)onFindPassWordClick:(id)sender;
@end

