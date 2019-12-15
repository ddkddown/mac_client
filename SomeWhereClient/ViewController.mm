//
//  ViewController.m
//  SomeWhereClient
//
//  Created by dong da kuan on 2019/10/28.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)showError:(NSString*)errorMsg{
    NSAlert* alert = [[NSAlert alloc] init];
    [alert addButtonWithTitle:@"确定"];
    [alert setInformativeText:errorMsg];
    [alert setAlertStyle:NSWarningAlertStyle];
    [alert beginSheetModalForWindow:[self.view window] completionHandler:^(NSModalResponse returnCode) {
        //清空文本框
        _username.stringValue = @"";
        _password.stringValue = @"";
    }];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    std::string tmp = "127.0.0.1";
    int port = 7796;
    test.set_server_ip_port(tmp, port);
    test.connect_to_server();
    // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


- (IBAction)onLogInClick:(id)sender {
    std::string username = [[_username stringValue] UTF8String];
    std::string password = [[_password stringValue] UTF8String];
    //TODO 这里需要用正则表达式做一次用户名校验
    char message[sizeof(struct somewhere_message)];
    
    somewhere_message config;
    memset(&config, -1, sizeof(struct somewhere_message));//如果设置为0的话会导致后面字符串出错（与字符串结尾/0冲突）
    config.type = LOGIN_MESSAGE;
    config.is_end = MESSAGE_END;
    config.message_length = username.size() + password.size();
    strncpy(config.user_name, username.c_str(), username.size());
    strncpy(config.password, password.c_str(), password.size());
    memcpy(message, &config, sizeof(struct somewhere_message));
    
    //向服务器发送消息
    std::string tmp(message);
    test.set_send_buffer(tmp);
    test.send_message_to_server();
    
    //从服务器接收回复消息
    test.get_message_from_server();
    reply_message server_message;
    memcpy(&server_message, test.get_recv_buffer().c_str(), sizeof(reply_message));
    if(server_message.status == SUCCESS_STATUS){
        std::cout<<"message type: "<<server_message.type<<"success"<<std::endl;
        //隐藏登录界面
        [[self.view window] orderOut:nil];
        
        //显示主窗口
        MainWindowController* mainWindowControl = [[MainWindowController alloc] initWithWindowNibName:@"MainWindow"];
        [mainWindowControl showWindow:self];
        
    }else if (server_message.status == FAIL_STATUS){
        std::cout<<"message type: "<<server_message.type<<"failed!"<<std::endl;
        [self showError:@"用户名密码错误，请重新输入"];
    }
}
- (IBAction)onSignUpClick:(id)sender{
    std::string username = [[_username stringValue] UTF8String];
    std::string password = [[_password stringValue] UTF8String];
    //TODO 这里需要用正则表达式做一次用户名的检查
    
    //
    
    char message[sizeof(struct somewhere_message)];
    
    somewhere_message config;
    memset(&config, -1, sizeof(struct somewhere_message));//如果设置为0的话会导致后面字符串出错（与字符串结尾/0冲突）
    config.type = SIGNUP_MESSAGE;
    config.is_end = MESSAGE_END;
    config.message_length = username.size() + password.size();
    strncpy(config.user_name, username.c_str(), username.size());
    strncpy(config.password, password.c_str(), password.size());
    memcpy(message, &config, sizeof(struct somewhere_message));
    
    std::string tmp(message);
    test.set_send_buffer(tmp);
    test.send_message_to_server();
    test.get_message_from_server();
    reply_message server_message;
    memcpy(&server_message, test.get_recv_buffer().c_str(), sizeof(reply_message));
    if(server_message.status == SUCCESS_STATUS){
        std::cout<<"message type: "<<server_message.type<<"success"<<std::endl;
    }else if (server_message.status == FAIL_STATUS){
        std::cout<<"message type: "<<server_message.type<<"failed!"<<std::endl;
        [self showError:@"注册失败，请重试"];
    }
}
- (IBAction)onFindPassWordClick:(id)sender {
}
@end
