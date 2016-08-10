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
#include <domain/TextData.hpp>
#include <boost/tokenizer.hpp>
#include <boost/log/sources/record_ostream.hpp>

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

        shared_ptr<Corpus> addToCorpus(shared_ptr<Corpus> corpus, string &text) {

            shared_ptr<TextData> textData = create(text);
            boost::tokenizer<> tokenizer(textData->original);
            for (auto word : tokenizer) {
                // TODO: Share this proccess on threads/processes
                proccessWord(corpus, textData, word);
            }
            return corpus;
        };

        /**
         * Simple factory mathod to create an TextData
         * @param text
         * @return
         */
        shared_ptr<TextData> create(string &text) {
            shared_ptr<TextData> textData = make_shared<TextData>();
            textData->uuid = core::Identifiable::Generate();
            textData->original = std::move(text); // TODO can I make that here ??
            return textData;
        }

    private:

        // TODO test this shared_ptr as reference, becouse this can be a problem on multithreaded proccess
        void proccessWord(const shared_ptr<Corpus> &corpus,const shared_ptr<TextData> &textData ,const auto &word) {
            if (!corpus->hasStopWord(word)) {
                string stemmedWord = getStemmedWord(word);
                if (textData->words.count(stemmedWord) > 0) {
                    textData->words[stemmedWord].count += 1;
                } else {
                    textData->words[stemmedWord] = KeyWord();
                    textData->words[stemmedWord].tfidf = corpus->getTFIDF(stemmedWord);
                }
                if (corpus->words.count(word)){
                    textData->words[stemmedWord].count +=1;
                }
            }
        };

    };
}

#endif //JARVIS_TEXTSERVICE_HPP
