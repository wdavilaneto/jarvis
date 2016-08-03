//
// Created by walter on 28/07/16.
//

#ifndef JARVIS_STOPWORDREPOSITORY_HPP
#define JARVIS_STOPWORDREPOSITORY_HPP


#include <core/Application.hpp>
#include <soci/soci.h>

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

        string get(const string& language_id) {
            string stop_word;
            session << "select words from stop_word where language = :language ", soci::into(stop_word), use(language_id);
            return stop_word;
        };

        void insert( const string &language, const string &stop_words) {
            session << "insert into stop_word (language , words) values ( :language , :words ) ",  use(language), use(stop_words);
        };

        void remove ( const string &language) {
            session << "delete from stop_word where language = :language", use(language);
        };



    private:
        soci::session session;
    };

};

#endif //JARVIS_STOPWORDREPOSITORY_HPP
