//
// Created by walter on 09/12/15.
//

#ifndef JARVIS_SERVER_HPP
#define JARVIS_SERVER_HPP

//#include "Poco/Net/HTTPServer.h"
//#include "Poco/Net/HTTPRequestHandler.h"
//#include "Poco/Net/HTTPRequestHandlerFactory.h"
//#include "Poco/Net/HTTPServerParams.h"
//#include "Poco/Net/HTTPServerRequest.h"
//#include "Poco/Net/HTTPServerResponse.h"
//#include "Poco/Net/HTTPServerParams.h"
//#include "Poco/Net/ServerSocket.h"
//#include "Poco/Timestamp.h"
//#include "Poco/DateTimeFormatter.h"
//#include "Poco/DateTimeFormat.h"
//#include "Poco/Exception.h"
//#include "Poco/ThreadPool.h"
//#include "Poco/Util/ServerApplication.h"
//#include "Poco/Util/Option.h"
//#include "Poco/Util/OptionSet.h"
//#include "Poco/Util/HelpFormatter.h"
#include "MainRequestHandler.hpp"
#include <iostream>

//using Poco::Net::ServerSocket;
//using Poco::Net::HTTPRequestHandler;
//using Poco::Net::HTTPRequestHandlerFactory;
//using Poco::Net::HTTPServer;
//using Poco::Net::HTTPServerRequest;
//using Poco::Net::HTTPServerResponse;
//using Poco::Net::HTTPServerParams;
//using Poco::Timestamp;
//using Poco::DateTimeFormatter;
//using Poco::DateTimeFormat;
//using Poco::ThreadPool;
//using Poco::Util::ServerApplication;
//using Poco::Util::Application;
//using Poco::Util::Option;
//using Poco::Util::OptionSet;
//using Poco::Util::OptionCallback;
//using Poco::Util::HelpFormatter;


namespace server {

    class RestfulServer {
        /*: public Poco::Util::ServerApplication { */
    public:

        RestfulServer();

        ~RestfulServer();
        /*
    protected:

        int main(const std::vector<std::string> &args) {

            unsigned short port = (unsigned short) config().getInt("RestfulServer.port", 8080);

            std::string format(config().getString("RestfulServer.format", DateTimeFormat::SORTABLE_FORMAT));
            ServerSocket svs(port);
            HTTPServer srv(new MainRequestHandlerFactory, svs, new HTTPServerParams);
            srv.start();
            waitForTerminationRequest();
            srv.stop();

            return Application::EXIT_OK;
        }
             */

    };

};

#endif //JARVIS_SERVER_HPP
