//
// Created by walter on 26/07/16.
//

#ifndef JARVIS_TEXTSERVICE_HPP
#define JARVIS_TEXTSERVICE_HPP

#include <domain.hpp>
#include <core/Application.hpp>
#include <core/identifiable.hpp>
#include <vector>
#include <string>
#include <domain/Document.hpp>
#include <boost/tokenizer.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <dlib/unicode.h>
#include <dlib/string.h>

namespace service {

    USE_SHARED_PTR
    using namespace domain;
    using std::unordered_map;
    using std::vector;
    using std::string;

    class TextService {
    public:
        TextService() = default;

        ~TextService() = default;

        /**
         * Todo implement some kind of stemming algorithm
         * @param original
         * @return stemmed text
         */
        std::string getStemmedWord(const string &original) {
            return string(original);
        };


        /**
         * Add a new text to the Corpus.. This method will create a new document
         * add to corpus and update all statistis tf-idf etc...It's is importa no to add the
         * same text twice.. to update text to a corpus uses method thata recieves a document
         * with existent and valid uuid on storage
         * @param corpus
         * @param text
         * @return the new document created, added and processed
         */
        shared_ptr<Document> addToCorpus(shared_ptr<Corpus> corpus, string &text) {

            shared_ptr<Document> document = create(text);
            corpus->documents[document->uuid] = document;

            auto word_collection = tokenizeit(document);

            for (auto word : word_collection) {
                string lcaseWord = dlib::tolower(word);
                if (!corpus->hasStopWord(lcaseWord)) {
                    proccessWord(corpus, document, lcaseWord);
                }
            }

            // TODO persist this new document on storage
            return document;
        };

        /**
         * Simple factory mathod to create an TextData
         * @param text
         * @return
         */
        shared_ptr<Document> create(string &text) {
            shared_ptr<Document> document = make_shared<Document>();
            document->uuid = core::Identifiable::Generate();
            document->original = std::move(text); // TODO can I make that here ??
            return document;
        }

    private:

        void proccessWord(shared_ptr<Corpus> corpus, shared_ptr<Document> document, const auto &word) {

            string stemmedWord = getStemmedWord(word);
            shared_ptr<KeyWord> keyword(nullptr);

            // if this is the first appearence of this word on corpus, we create an new
            // key word with initial values
            if (!corpus->hasKeyWord(stemmedWord)) {
                { // TODO synzchroneize this area...
                    keyword = make_shared<KeyWord>();
                    keyword->stemmed = stemmedWord;
                    keyword->nDocs = 1;
                    keyword->tfidf = log(corpus->totalDocuments / (1));
                    corpus->words[stemmedWord] = keyword;
                }
            } else {
                // if exists, get the reference to the keyword from
                keyword = corpus->words[stemmedWord];
            }

            // if this is the first appearence on document ?
            if (document->words.count(keyword->stemmed) == 0) {
                document->words[keyword->stemmed] = 1; // set value on document  to first apearence
                keyword->nDocs += 1;// add to corpus contabilization of an new first apearence on document
            } else {
                document->words[keyword->stemmed] += 1;
            }
        };

        shared_ptr<KeyWord> getKeyWordFromCorpus(shared_ptr<Corpus> corpus, auto &word) {

            // result key word (remeber each keyword should be unique*  )
            shared_ptr<KeyWord> keyword(nullptr);

            // already has an occurency of this word on the corpus return it
            if (corpus->words.count(word)) {
                return corpus->words[word];
            }
        }

        boost::tokenizer<> tokenizeit(shared_ptr<Document> document) {
            boost::tokenizer<> tokenizer(document->original);
            return tokenizer;
        }


    };
}

#endif //JARVIS_TEXTSERVICE_HPP
