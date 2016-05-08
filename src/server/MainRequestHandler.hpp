//
// Created by walter on 18/03/16.
//

#ifndef JARVIS_MAINREQUESTHANDLER_HPP
#define JARVIS_MAINREQUESTHANDLER_HPP

#include <TrainingDataService.hpp>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"

using Poco::Util::Application;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;

class RootHandler : public HTTPRequestHandler {
public:

    void handleRequest(HTTPServerRequest &request, HTTPServerResponse &response) {

        Application &app = Application::instance();
        app.logger().information("Request from " + request.clientAddress().toString());
        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");
        std::ostream &ostr = response.send();
        ostr << "<html><head><title>HTTP Server powered by POCO C++ Libraries</title></head>";
        ostr << "<body> bla bla bla </body></html>";

    }

};

class MainRequestHandlerFactory : public HTTPRequestHandlerFactory {
private:
    std::vector<boost::shared_ptr<HTTPRequestHandler> > handlers;
public:

    MainRequestHandlerFactory() : handlers() {
        handlers.push_back(boost::make_shared(TrainingDataService));
    }

    HTTPRequestHandler *createRequestHandler(const HTTPServerRequest &request) {

        if (request.getURI() == "/")
            return new RootHandler();
        else
            return new RootHandler();
    }
};


#endif //JARVIS_MAINREQUESTHANDLER_HPP
