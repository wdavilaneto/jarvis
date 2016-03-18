//
// Created by walter on 18/03/16.
//

#ifndef JARVIS_TRAININGDATASERVICE_HPP
#define JARVIS_TRAININGDATASERVICE_HPP

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Util/Application.h>
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"

using Poco::Util::Application;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPRequestHandler;

class RootHandler : public HTTPRequestHandler {
public:

    void handleRequest(HTTPServerRequest &request, HTTPServerResponse &response) {
        Application &app = Application::instance();
        app.logger().information("Request from " + request.clientAddress().toString());

        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");
        std::ostream &ostr = response.send();



    }

};


#endif //JARVIS_TRAININGDATASERVICE_HPP
