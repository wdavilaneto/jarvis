//
// Created by walter on 14/10/16.
//

#ifndef JARVIS_WORD_HPP_HPP
#define JARVIS_WORD_HPP_HPP

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

namespace domain {

    using std::string;
    using boost::shared_ptr;
    using boost::make_shared;

    /**Forward Declaration */
    class Corpus;
    /**
     * Each Instance of this class should be an Unique instance
     * with it Steemd version as "unique id"
     */
    class Word {
    public:
        size_t id;
        string name;
        size_t total = 0;
        size_t hitsOnDocuments = 0;

        bool isStop = false;
        double tfidf = 0.0;

        shared_ptr<Corpus> corpus;

        bool hasAppereadOnDocument(shared_ptr<Document> d) {
            return docs.count(d->uuid);
        };

        bool addDocument(shared_ptr<Document> d) {
            docs[d->uuid] = d;
        }

    private:
        std::map<string, shared_ptr<Document> > docs;
    };

}

#endif //JARVIS_WORD_HPP_HPP
