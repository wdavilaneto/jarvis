//
// Created by walter on 15/03/16.
//

#include "server.h"

Server::Server() {
    handler = new CoreRequestHandler;
    options = new ServerOptions(*handler);
    server = new HttpServer(options->address("0.0.0.0").port("8080"));
}

Server::~Server(){
    delete handler;
    delete options;
}
