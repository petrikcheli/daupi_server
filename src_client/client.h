#pragma once

#include <boost/asio.hpp>
#include <boost/bind.hpp>
//#include <iostream>

using namespace boost::asio;

class Client
{
private:
    Client();
    ip::tcp::socket _socket_server;
    ip::tcp::endpoint _ep_server{ip::address::from_string("127.0.0.1"), 12345};
    ip::tcp::resolver resolver_;
    std::vector<unsigned char> buff;

private:
    void async_read_server();
    void connect_to_server();
    void create_ar();

public:
    Client(boost::asio::io_context& io_context, const std::string& host, int port)
        : _socket_server(io_context), resolver_(io_context){
        auto endpoints = resolver_.resolve(host, std::to_string(port));
        buff.resize(0);
        connect_to_server();
    }
    ~Client(){
        //delete[] buff;
    }
    void async_send_server();

};


