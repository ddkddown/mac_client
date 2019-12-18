//
//  MainPage.h
//  SomeWhereClient
//
//  Created by dong da kuan on 2019/12/18.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface MainPage : NSWindowController{
    
}
@property(nonatomic, retain)IBOutlet NSTextField* articleName;
@property (unsafe_unretained) IBOutlet NSTextView *contents;

@property(nonatomic, retain)IBOutlet NSOutlineView* articleList;



- (IBAction)onNewClick:(id)sender;
- (IBAction)onResetClick:(id)sender;
- (IBAction)onSubmmitClick:(id)sender;
@end
