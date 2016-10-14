//
// Created by walter on 11/08/16.
//

#ifndef JARVIS_CORPUSREPOSITORY_HPP
#define JARVIS_CORPUSREPOSITORY_HPP

#include <repository/BaseRepository.hpp>
#include <domain.hpp>
#include <boost/tokenizer.hpp>

namespace repository {

    USE_SHARED_PTR
    using namespace domain;
    using std::string;
    using std::vector;
    using soci::use;

    class CorpusRepository : BaseRepository {
    public:

        CorpusRepository() {
        };

        virtual ~CorpusRepository() = default;

        shared_ptr<Corpus> get(const string &name) {

            string stop_words;
            shared_ptr<Corpus> corpus = make_shared<Corpus>();
            string query = getConfig().get<string>("repository.getCorpus", "");

            session << query, soci::into(corpus->id), soci::into(corpus->name), soci::into(corpus->language), soci::into(stop_words), use(name);
            if (!session.got_data()) {
                return shared_ptr<Corpus>(nullptr);
            }

            boost::tokenizer<> tokenizer(stop_words);
            for (auto word : tokenizer) {
                corpus->stopWords.insert(word);
            }
            return corpus;
        };


    };

};

#endif //JARVIS_CORPUSREPOSITORY_HPP
