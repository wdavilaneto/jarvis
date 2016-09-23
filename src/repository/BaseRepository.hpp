//
// Created by walter on 23/09/16.
//

#ifndef JARVIS_BASEREPOSITORY_HPP
#define JARVIS_BASEREPOSITORY_HPP

#include <core/Application.hpp>
#include <soci/soci.h>

namespace repository {

    using std::string;

    class BaseRepository : public core::ApplicationAware {
    public:

        BaseRepository() {
            session.open(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
            //session.set_log_stream(&std::cout);
        };

        virtual ~BaseRepository() {
            session.close();
        };

    protected:
        soci::session session;

    };

};

#endif //JARVIS_BASEREPOSITORY_HPP
