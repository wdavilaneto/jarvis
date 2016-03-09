#include <iostream>
#include <nghttp2/asio_http2_server.h>

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;

int main(int arg, char *argv[]) {

    http2 server;

    server.num_threads(4);

    server.handle("/", [](const request &req, const response &res) {
        res.write_head(200);
        res.end("hello, world\n");
    });

    try {
        boost::system::error_code ec;
        if (server.listen_and_serve(ec, "localhost", "8000")) {
            std::cerr << "error: " << ec.message() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

};