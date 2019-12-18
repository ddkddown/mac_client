//
//  AppDelegate.m
//  SomeWhereClient
//
//  Created by dong da kuan on 2019/10/28.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    [self initMainWindow];
    // Insert code here to initialize your applicationf
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (void)initMainWindow{
    _loginWindow = [[LoginWindow alloc] initWithWindowNibName:@"LoginWindow"];
    [[_loginWindow window] center];
    [_loginWindow.window orderFront:nil];
}
@end
