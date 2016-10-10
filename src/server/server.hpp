//
// Created by walter on 09/12/15.
//
#ifndef JARVIS_SERVER_HPP
#define JARVIS_SERVER_HPP

#include <iostream>
#include <dlib/server.h>

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

    using std::ostringstream;
    using namespace dlib;

    class RestfulServer : public server_http {
    public:

        RestfulServer();

        ~RestfulServer();

        const std::string on_request(const incoming_things &incoming, outgoing_things &outgoing) {
            ostringstream sout;
            return sout.str();
        }

    };



    class web_server : public server_http {
        const std::string on_request(const incoming_things &incoming, outgoing_things &outgoing) {
            ostringstream sout;
            // We are going to send back a page that contains an HTML form with two text input fields.
            // One field called name.  The HTML form uses the post method but could also use the get
            // method (just change method='post' to method='get').
            sout << " <html> <body> "
                 << "<form action='/form_handler' method='post'> "
                 << "User Name: <input name='user' type='text'><br>  "
                 << "User password: <input name='pass' type='text'> <input type='submit'> "
                 << " </form>";

            // Write out some of the inputs to this request so that they show up on the
            // resulting web page.
            sout << "<br>  path = " << incoming.path << std::endl;
            sout << "<br>  request_type = " << incoming.request_type << std::endl;
            sout << "<br>  content_type = " << incoming.content_type << std::endl;
            sout << "<br>  protocol = " << incoming.protocol << std::endl;
            sout << "<br>  foreign_ip = " << incoming.foreign_ip << std::endl;
            sout << "<br>  foreign_port = " << incoming.foreign_port << std::endl;
            sout << "<br>  local_ip = " << incoming.local_ip << std::endl;
            sout << "<br>  local_port = " << incoming.local_port << std::endl;
            sout << "<br>  body = \"" << incoming.body << "\"" << std::endl;

            // If this request is the result of the user submitting the form then echo back
            // the submission.
            if (incoming.path == "/form_handler") {
                sout << "<h2> Stuff from the query string </h2>" << std::endl;
                sout << "<br>  user = " << incoming.queries["user"] << std::endl;
                sout << "<br>  pass = " << incoming.queries["pass"] << std::endl;
                // save these form submissions as cookies.
                outgoing.cookies["user"] = incoming.queries["user"];
                outgoing.cookies["pass"] = incoming.queries["pass"];
            }
            // Echo any cookies back to the client browser
            sout << "<h2>Cookies the web browser sent to the server</h2>";
            for (key_value_map::const_iterator ci = incoming.cookies.begin(); ci != incoming.cookies.end(); ++ci) {
                sout << "<br/>" << ci->first << " = " << ci->second << std::endl;
            }
            sout << "<br/><br/>";
            sout << "<h2>HTTP Headers the web browser sent to the server</h2>";
            // Echo out all the HTTP headers we received from the client web browser
            for (key_value_map_ci::const_iterator ci = incoming.headers.begin(); ci != incoming.headers.end(); ++ci) {
                sout << "<br/>" << ci->first << ": " << ci->second << std::endl;
            }

            sout << "</body> </html>";
            return sout.str();
        }

    };

};

#endif //JARVIS_SERVER_HPP
