//
//  MainWindowController.h
//  SomeWhereClient
//
//  Created by dong da kuan on 2019/12/15.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#ifndef MainWindowController_h
#define MainWindowController_h
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
@interface MainWindowController : NSWindowController{
    
    
}
@property(nonatomic, retain)IBOutlet NSTextField* articleName;
@property (weak) IBOutlet NSView *contents;

@property(nonatomic, retain)IBOutlet NSOutlineView* articleList;



- (IBAction)onNewClick:(id)sender;
- (IBAction)onResetClick:(id)sender;
- (IBAction)onSubmmitClick:(id)sender;
@end
#endif /* MainWindowController_h */
