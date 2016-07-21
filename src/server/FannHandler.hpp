//
// Created by walter on 23/05/16.
//

#ifndef JARVIS_FANNHANDLER_HPP
#define JARVIS_FANNHANDLER_HPP

using Poco::Util::Application;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;

namespace server {

    class FannHandler : public HTTPRequestHandler {
    public:

        void handleRequest(HTTPServerRequest &request, HTTPServerResponse &response) {
            Application &app = Application::instance();
//            app.logger().information(" fann context request with url: " + request.clientAddress().toString());

            response.setChunkedTransferEncoding(true);
            response.setContentType("json");

            std::ostream &ostr = response.send();
            ostr << "{}";

        }


    };

};

#endif //JARVIS_FANNHANDLER_HPP
