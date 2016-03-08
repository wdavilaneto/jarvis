#include <iostream>
#include <nghttp2/asio_http2_server.h>

using namespace nghttp2::asio_http2;
using namespace nghttp2::asio_http2::server;

int main(int arg, char *argv[]) {

    http2 server;

    server.handle("/", [](const request &req, const response &res) {
        res.write_head(200);
        res.end("hello, world\n");
    });

    boost::system::error_code ec;
    if (server.listen_and_serve(ec, "0.0.0.0", "8080")) {
        std::cerr << "error: " << ec.message() << std::endl;
    }
    return EXIT_SUCCESS;
};