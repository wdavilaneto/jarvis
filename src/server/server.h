//
// Created by walter on 15/03/16.
//
#ifndef JARVIS_SERVER_H
#define JARVIS_SERVER_H

#include <boost/network.hpp>
#include <boost/network/protocol/http/server.hpp>


namespace http = boost::network::http;

// Forward declaration of main handler
class CoreRequestHandler;

typedef http::server<CoreRequestHandler> HttpServer;
typedef HttpServer::request Request;
typedef HttpServer::response Response;
typedef HttpServer::options ServerOptions;

// CoreRequestHandler chains possible
class CoreRequestHandler {
public:
    void operator()(Request const &request, Response &response) {
        std::string source = boost::network::http::source(request);
        std::cout << source << std::endl;
        response = HttpServer::response::stock_reply(HttpServer::response::ok, "{server_status:\"OK!\"}");
    }

    void log(HttpServer::string_type const &info) {
        std::cerr << "ERROR: " << info << std::endl;
    }

};

//  Very very Simple singleton implementation

class Server {
private:
    Server();

    CoreRequestHandler *handler;
    ServerOptions *options;
    HttpServer *server;
public:
    static Server &getInstance() {
        static Server server; // not thread safe... but ok after first non concurrent use
        return server;
    }

    virtual ~Server();

    void run() {
        server->run();
    }

    void stop() {
        server->stop();
    }

};


#endif //JARVIS_SERVER_H
