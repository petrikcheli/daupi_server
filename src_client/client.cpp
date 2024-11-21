#include "client.h"
#include <iostream>

void Client::async_send_server() {
    //auto msg = std::make_shared<std::string>(message + "\n");
    std::cout << "send to server" << std::endl;
    _socket_server.async_send(boost::asio::buffer(buff),
                            [this](const boost::system::error_code& error, std::size_t) {
                                if (!error) {
                                    //delete[] ar;
                                    std::cout << "send to server done!!!!" << std::endl;
                                    async_read_server(); // Получаем ответ от сервера
                                }
                            });
}

void Client::async_read_server() {
    //auto buffer = std::make_shared<std::vector<unsigned char>>(0);
    _socket_server.async_receive(boost::asio::buffer(buff),
                                    [this](const boost::system::error_code& error, std::size_t) {
                                        if (!error) {
                                            std::cout << "read done!!!" << std::endl;
                                        }
                                    });
}

void Client::connect_to_server() {
    //_socket_server.open(ip::tcp::v4());
    _socket_server.connect(_ep_server);

    create_ar();

}

void Client::create_ar()
{
    std::cout << "hello" << std::endl;
    std::string str = "0123456789";
    for(int i = 0 ; i < str.length(); ++i) buff.push_back(str[i]);
    async_send_server();
}
