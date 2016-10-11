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
                BOOST_LOG_TRIVIAL(error) << exception.what();
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
            // method (just change method='post' to method='get' /form_handler).
            sout << "{path:'" << incoming.path << "',request_type:'" << incoming.request_type;
            if (!incoming.content_type.empty()) {
                sout << "',content_type:'" << incoming.content_type;
            }
            sout << "',protocol:'" << incoming.protocol
                 << "',foreign_ip:'" << incoming.foreign_ip
                 << "',foreign_port:" << incoming.foreign_port
                 << ",local_ip:'" << incoming.local_ip
                 << "',local_port:" << incoming.local_port;

            if (!incoming.body.empty()) {
                sout << ",body:'" << incoming.body << "'";
            }


            // If this request is the result of the user submitting the form then echo back the submission.
            if (incoming.path == "/form_handler") {
                sout << ",user:'" << incoming.queries["user"] << "',password:'" << incoming.queries["pass"] << "'";
                outgoing.cookies["user"] = incoming.queries["user"];
                outgoing.cookies["pass"] = incoming.queries["pass"];
            }
            for (key_value_map::const_iterator ci = incoming.cookies.begin(); ci != incoming.cookies.end(); ++ci) {
                sout << "," << ci->first << ":'" << ci->second << "'";
            }
            for (key_value_map_ci::const_iterator ci = incoming.headers.begin(); ci != incoming.headers.end(); ++ci) {
                sout << "," << ci->first << ":'" << ci->second << "'";
            }
            sout << "}";
            return sout.str();
        };

    public:
        virtual bool urlMatches(const std::string aGivenUrl) override {
            return true;
        };

    };

    class RestfulServer : public server_http, public core::ApplicationAware {
    public:

        RestfulServer();

        ~RestfulServer();

        const std::string on_request(const incoming_things &incoming, outgoing_things &outgoing) {
            for (auto handler : handlers) {
                if (handler->urlMatches(incoming.path)) {
                    return handler->doHandle(incoming, outgoing);
                }
            }
            return defaultHandler.doHandle(incoming, outgoing);
        }

        void addHandler(shared_ptr<IRequestHandler> handler) {
            handlers.push_back(handler);
        }

    private:
        std::vector<shared_ptr<IRequestHandler> > handlers;
        DefaultHandler defaultHandler;

    };
};

#endif //JARVIS_SERVER_HPP
