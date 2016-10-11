//
// Created by walter on 15/03/16.
//

#include "server.hpp"
#include <boost/log/trivial.hpp>
//#define boostLog BOOST_LOG_TRIVIAL

namespace server {

    RestfulServer::RestfulServer() {
        this->set_listening_port(getConfig().get<int>("server.port"));
        BOOST_LOG_TRIVIAL(info) << "Restfull server iniitialization on " << getConfig().get<std::string>("server.port");
    }

    RestfulServer::~RestfulServer() {
        BOOST_LOG_TRIVIAL(info) << "Restfull shutdown gracefully ..bye";
    }

};