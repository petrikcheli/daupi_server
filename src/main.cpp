#include <boost/asio.hpp>
#include "server.h"

int main() {
    boost::asio::io_context io_context;
    Server server(io_context);
    io_context.run();

    return 0;
}
