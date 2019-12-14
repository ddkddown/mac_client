//
//  ConnectServer.hpp
//  SomeWhereLib
//
//  Created by dong da kuan on 2019/10/27.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#ifndef ConnectServer_hpp
#define ConnectServer_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio.hpp>
namespace ddk{
    //连接服务器的类
    class ConnectServer{
    private:
        std::string server_ip;
        int         server_port;
        
    private:
        bool is_connected = false;
    protected:
        std::string  send_buff;
        std::string  recv_buff;
        
    public:
        ConnectServer(){ server_ip.clear();server_port = -1;}
        virtual ~ConnectServer(){};
        
    public:
        virtual bool connect_to_server() = 0;
        void set_server_ip(std::string tmp){ server_ip = tmp;}
        std::string& get_server_ip(){ return server_ip;}
        void clean_server_ip(){ server_ip.clear();}
        void set_server_port(int tmp){ server_port = tmp;}
        int  get_server_port(){ return server_port;}
        void clean_server_port(){ server_port = -1;}
        void set_send_buffer(std::string& tmp){ send_buff = tmp;}
        std::string get_send_buffer(){ return send_buff;}
        std::string get_recv_buffer(){ return recv_buff;}
        void set_status(bool status){ is_connected = status;}
        bool get_status(){  return is_connected;}
    };
    
}


#endif /* ConnectServer_hpp */
