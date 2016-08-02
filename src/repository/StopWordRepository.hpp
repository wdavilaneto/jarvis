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
    using soci::use;

    class StopWordRepository : core::ApplicationAware {
    public:
        StopWordRepository() {
            // TODO use connection pool
            session.open(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
            session.set_log_stream(&std::cout);
        };

        ~StopWordRepository() = default;

        vector<string> findAll() {

            string stop_word;
            soci::statement st = dynamic_cast<>(session.prepare
                    << "select nr_mp as ID, pdf as TEXT from bi_manifestacao order by nr_mp", soci::into(stop_word)
            );

            st.execute();

            vector<string> result;
            while (st.fetch()) {
                result.push_back(std::move(stop_word));
            }
            return result;
        }

        void insertAll(vector words) {
            soci::statement st = dynamic_cast<>(session.prepare
                    << "insert into stop_word (word, language) values ( :word , :language ) " << use(words)
            );
            st.execute();
            while (st.fetch()) {

            }
        }

        bool insert(const string &word) {
            soci::statement st = dynamic_cast<>(session.prepare
                    << "insert into stop_word (word, language) values ( :word , :language ) " << use(word)
            );
            return st.execute();
        }

    private:
        soci::session session;
    };

};

#endif //JARVIS_STOPWORDREPOSITORY_HPP
