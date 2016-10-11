//
// Created by walter on 09/12/15.
//
#ifndef JARVIS_SERVER_HPP
#define JARVIS_SERVER_HPP

#include <iostream>
#include <core/Application.hpp>
#include <dlib/server.h>

namespace server {

    USE_SHARED_PTR
    using std::ostringstream;
    using std::string;
    using dlib::incoming_things;
    using dlib::outgoing_things;
    using dlib::server_http;
    using dlib::key_value_map;
    using dlib::key_value_map_ci;

    class IRequestHandler {
    public:
        IRequestHandler() {
        }

        virtual ~IRequestHandler() = default;


        virtual const string doHandle(const incoming_things &incoming, outgoing_things &outgoing) {
            try {
                return onHandle(incoming, outgoing);
            } catch (const std::exception &exception) {
                BOOST_LOG_TRIVIAL(error)  << exception.what() ;
                return exception.what();
            }
        }

        virtual bool urlMatches(const std::string aGivenUrl)  = 0;

    protected:

        virtual const string onHandle(const incoming_things &incoming, outgoing_things &outgoing) = 0;

    private:
        string path;
    };

    class DefaultHandler : public IRequestHandler {
    public:

        DefaultHandler() = default;
        virtual ~DefaultHandler() override = default;

    protected:
        virtual const string onHandle(const incoming_things &incoming, outgoing_things &outgoing) override {
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

    public:
        virtual bool urlMatches(const std::string aGivenUrl) override {
            return true;
        }

    };


    class RestfulServer : public server_http {
    public:

        RestfulServer();

        ~RestfulServer();

        const std::string on_request(const incoming_things &incoming, outgoing_things &outgoing) {
            static DefaultHandler defaultHandler;
            for ( auto handler : handlers) {
                if (handler->urlMatches(incoming.path)) {
                    return handler->doHandle(incoming,outgoing);
                }
            }
            return defaultHandler.doHandle(incoming,outgoing);
        }

        void addHandler(shared_ptr<IRequestHandler> handler) {
            handlers.push_back(handler);
        }

    private:
        std::vector<shared_ptr<IRequestHandler> > handlers;

    };
};

#endif //JARVIS_SERVER_HPP
