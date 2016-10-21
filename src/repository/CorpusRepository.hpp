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

        shared_ptr<Corpus> get(const size_t &id) {
            shared_ptr<Corpus> corpus = make_shared<Corpus>();
            session << getConfig().get<string>("repository.getCorpus"), soci::into(*corpus), use(id);
            if (!session.got_data()) {
                return shared_ptr<Corpus>(nullptr);
            }
            return corpus;
        };


    };

};

#endif //JARVIS_CORPUSREPOSITORY_HPP
