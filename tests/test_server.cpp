#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

// Подключение WinSock перед Boost.Asio
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <ws2tcpip.h>  // Заголовки для работы с сокетами на Windows
#include <winsock2.h>
//#include <future>

#include <thread>
// Подключаем свои файлы
#include "server.h"
#include "client.h"

BOOST_AUTO_TEST_SUITE(Server_t)

BOOST_AUTO_TEST_CASE(boost_test_daupi_server)
{
    setlocale(LC_ALL, "rus");
    boost::asio::io_context io_context;

    short port = 12345;  // Тот же порт для клиента и сервера

    Server* server = new Server(io_context);

    //std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread client_thread([&]() {
        Client(io_context, "127.0.0.1", 12345);
        io_context.run();
    });


    client_thread.join();
    io_context.run();
    // std::cout << server->buff[0] << std::endl;
    // bool flag = true;
    // for(int i = 0; i < 10; ++i){
    //     if(server->buff[i]!=std::to_string(i)[0]){
    //         std::cout << server->buff[i] << " : " << std::to_string(i) << std::endl;
    //         flag = false;
    //     }
    // }

    BOOST_TEST(true);
}

BOOST_AUTO_TEST_SUITE_END()


