//
//  TcpConnect.cpp
//  SomeWhereLib
//
//  Created by dong da kuan on 2019/10/27.
//  Copyright © 2019年 dong da kuan. All rights reserved.
//

#include "TcpConnect.hpp"

TcpConnect::TcpConnect(){
    socket = new (std::nothrow) boost::asio::ip::tcp::socket(iosev);
    if(!socket){
        std::cout<< "init socket failed!, app will terminate!"<<std::endl;
        exit(-1);
    }
}

TcpConnect::~TcpConnect(){
    if(socket){
        delete socket;
    }
}

void TcpConnect::set_server_ip_port(std::string tmp_ip, int tmp_port){
    std::ifstream fs;
    boost::property_tree::ptree ptree;
    
    fs.open("/Users/dongdakuan/Downloads/mac_client/mac_client/SomeWhereClient/conf/config.json",std::fstream::in);
    if(!fs.is_open()){
        std::cout<<"open config.json failed!"<<std::endl;
    }
    std::string s((std::istreambuf_iterator<char>(fs)),
                    std::istreambuf_iterator<char>());
    std::stringstream ss(s);
    
    try {
        boost::property_tree::read_json(ss, ptree);
    } catch (std::exception e) {
        std::cout<<"read json failed! check the json file!"<<std::endl;
        exit(1);
    }
    
    auto node = ptree.get_child_optional("server_ip")->get_value<std::string>();
    if(node.empty()){
        std::cout<<"get server_ip failed!"<<std::endl;
    }else{
        std::cout<<"server_ip is "<<node<<std::endl;
        tmp_ip = node;
    }
    
    node = ptree.get_child_optional("server_port")->get_value<std::string>();
    if(node.empty()){
        std::cout<<"get server_port failed!"<<std::endl;
    }else{
        std::cout<<"server_port is "<<node<<std::endl;
        tmp_port = atoi(node.c_str());
    }
    
    set_server_ip(tmp_ip);
    set_server_port(tmp_port);
}

void TcpConnect::set_server_point(){
    server_point.address(boost::asio::ip::address_v4::from_string(get_server_ip().c_str()));
    server_point.port(get_server_port());
}

bool TcpConnect::send_message_to_server(){
    size_t send_len;
    bool ret = false;
    if(get_send_buffer().empty())
    {
        std::cout<<"send buffer is empty! close socket and return!";
        socket->close();
        goto out;
    }
    
    send_len = socket->write_some(boost::asio::buffer(get_send_buffer(),get_send_buffer().length()),error_message);
    if(error_message){
        std::cout<<"write_some: "<<boost::system::system_error(error_message).what()<<std::endl;
        socket->close();
        goto out;
    }
    
    ret = true;
out:
    return ret;
}

bool TcpConnect::get_message_from_server(){
    size_t recv_len;
    bool ret = false;
    char recv_message[sizeof(reply_message)] = {0};
    socket->wait(socket->wait_read);
    std::cout<<"ready to read!"<<std::endl;
    recv_len = socket->read_some(boost::asio::buffer(recv_message),error_message);
    if(error_message){
        std::cout<<"read_some: "<<boost::system::system_error(error_message).what()<<std::endl;
        socket->close();
        goto out;
    }
    std::cout<<recv_message<<std::endl;
    recv_buff.clear();
    recv_buff.append(recv_message);
    ret = true;
out:
    return ret;
}

bool TcpConnect::connect_to_server(){
     bool ret = false;
     if(get_server_port() == -1){
     std::cout<<"port == -1 , that is invalid! return!";
     set_status(false);
     goto out;
     }
    
     set_server_point();
    
     socket->connect(server_point,error_message);
     if(error_message){
         std::cout<<"connect error! client will exit:  "<<boost::system::system_error(error_message).what()<<std::endl;
         set_status(false);
         exit(1);
     }
     set_status(true);
    
     ret = true;
out:
     return ret;
}

void TcpConnect::close_connect(){
    if(get_status()){
        socket->close();
    }
    set_status(false);
}

