//
//  MainPage.m
//  MacClient
//
//  Created by dong da kuan on 2019/12/21.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#import "MainPage.h"

@interface MainPage ()

@end

@implementation MainPage

- (void)windowDidLoad {
    [super windowDidLoad];
    NSLog(@"test");
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}
- (IBAction)test:(id)sender {
    NSLog(@"test");
    std::cout<<"hello"<<std::endl;
}
@end
