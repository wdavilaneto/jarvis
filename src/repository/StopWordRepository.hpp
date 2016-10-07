//
// Created by walter on 28/07/16.
//

#ifndef JARVIS_STOPWORDREPOSITORY_HPP
#define JARVIS_STOPWORDREPOSITORY_HPP


#include <repository/BaseRepository.hpp>

namespace repository {

    using std::string;
    using std::vector;
    using soci::use;

    class StopWordRepository : BaseRepository {
    public:
        StopWordRepository() {
            // TODO use connection pool
        };

        virtual ~StopWordRepository() = default;

        string get(const string& language_id) {
            string stop_word;
            session << getConfig().get<string>("repository.getStopWords"), soci::into(stop_word), use(language_id);
            return stop_word;
        };

        void insert( const string &language, const string &stop_words) {
            session << getConfig().get<string>("repository.insertStopWords"),  use(language), use(stop_words);
        };

        void remove ( const string &language) {
            session << getConfig().get<string>("repository.deleteStopWords"), use(language);
        };
    };

};

#endif //JARVIS_STOPWORDREPOSITORY_HPP
