//
// Created by walter on 11/08/16.
//

#ifndef JARVIS_CORPUSREPOSITORY_HPP
#define JARVIS_CORPUSREPOSITORY_HPP

#include <core/Application.hpp>
#include <soci/soci.h>
#include <domain.hpp>
#include <boost/tokenizer.hpp>

namespace repository {

    USE_SHARED_PTR
    using namespace domain;
    using std::string;
    using std::vector;
    using soci::use;

    class CorpusRepository : core::ApplicationAware {
    public:

        CorpusRepository() {
            // TODO use connection pool
            session.open(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
            session.set_log_stream(&std::cout);
        };

        ~CorpusRepository() = default;

        shared_ptr<Corpus> get(const string &name) {
            shared_ptr<Corpus> corpus = make_shared<Corpus>();
            string stop_words;
            session
                    << "select corpus.id, corpus.name, corpus.language , words from corpus left join stop_word on corpus.language = stop_word.language where corpus.name = :name",
                    soci::into(corpus->id), soci::into(corpus->name), soci::into(corpus->language), soci::into(stop_words)
                    , use(name);

            if (!session.got_data()) {
                return shared_ptr<Corpus>(nullptr);
            }

            boost::tokenizer<> tokenizer(stop_words);
            for (auto word : tokenizer) {
                corpus->stopWords.insert(word);
            }
            return corpus;
        };

    private:
        soci::session session;

    };

};

#endif //JARVIS_CORPUSREPOSITORY_HPP
