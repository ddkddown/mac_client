//
//  TcpConnect.hpp
//  MacClient
//
//  Created by dong da kuan on 2019/12/20.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#ifndef TcpConnect_hpp
#define TcpConnect_hpp

#include <iostream>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "ConnectServer.hpp"
#include "SomeHeader.h"

using namespace ddk;
class TcpConnect : public ConnectServer{
private:
    boost::asio::ip::tcp::socket    *socket = nullptr;
    boost::asio::ip::tcp::endpoint  server_point;
    boost::asio::io_service         iosev;//boost库的所有asio类都要有io_service对象
    boost::system::error_code       error_message;
    
private:
    void set_server_point();
public:
    TcpConnect();
    ~TcpConnect();
    void set_server_ip_port(std::string tmp_ip, int tmp_port);
    bool connect_to_server();
    bool send_message_to_server();
    bool get_message_from_server();
    void close_connect();
    
};


#endif /* TcpConnect_hpp */
