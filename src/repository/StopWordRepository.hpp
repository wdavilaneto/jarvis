//
// Created by walter on 28/07/16.
//

#ifndef JARVIS_STOPWORDREPOSITORY_HPP
#define JARVIS_STOPWORDREPOSITORY_HPP

#include <core/Application.hpp>
#include <soci/soci.h>
#include "soci/sqlite3/soci-sqlite3.h"
#include <boost/property_tree/ini_parser.hpp>


namespace repository {

    using std::string;
    using std::vector;

    class StopWordRepository : core::ApplicationAware {
    public:
        StopWordRepository() = default;
        ~StopWordRepository() = default;

        vector<string> findAll () {
            // TODO use connection pool
            soci::session session(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
            session.set_log_stream(&std::cout);

            string stop_word;
            soci::statement st = dynamic_cast<>(session.prepare << "select nr_mp as ID, pdf as TEXT from bi_manifestacao order by nr_mp", soci::into(stop_word));

            st.execute();

            vector<string> result;
            while (st.fetch()) {
                result.push_back(std::move(stop_word));
            }
            return result;
        }

    };

} ;

#endif //JARVIS_STOPWORDREPOSITORY_HPP
