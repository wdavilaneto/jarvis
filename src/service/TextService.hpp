//
// Created by walter on 26/07/16.
//

#ifndef JARVIS_TEXTSERVICE_HPP
#define JARVIS_TEXTSERVICE_HPP

#include <domain.hpp>
#include <core/identifiable.hpp>
#include <vector>
#include <string>
#include <domain/TextData.hpp>
#include <boost/tokenizer.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace service {

    using namespace domain;
    using std::vector;
    using std::string;

    class TextService {
    public:
        TextService() = default;

        ~TextService() = default;

        std::unordered_map<string, size_t> wordCount(const string &text) {
            std::unordered_map<string, size_t> map;

            // Tokenize to words only
            boost::tokenizer<> tokenizer(text);
            for (auto word : tokenizer) {
                if (map.count(word)) {
                    map[word] += 1;
                } else {
                    map[word] = 1;
                }
            }
            return map;
        }


        /**
         * Todo implement some kind of stemming algorithm
         * @param original
         * @return stemmed text
         */
        std::string getStemmedWord(const string &original) {
            return string(original);
        };

        std::string removeStopWords(const string &original) {
            return string(original);
        };

        boost::shared_ptr<Corpus> addToCorpus(boost::shared_ptr<Corpus> corpus, string &text) {

            TextData textData;
            textData.uuid = core::Identifiable::Generate();
            textData.original = std::move(text);

            boost::tokenizer<> tokenizer(textData.original);
            for (auto word : tokenizer) {
                // ignoring stop words
                if (!corpus->hasStopWord(word)) {
                    string stemmedWord = getStemmedWord(word);
                    if (textData.words.count(stemmedWord)) {
                        textData.words[stemmedWord].count += 1;
                    } else {
                        textData.words[stemmedWord] = KeyWord();
                        textData.words[stemmedWord].tfidf = corpus->getTFIDF(stemmedWord);
                    }
                }
            }
        };

    };
}

#endif //JARVIS_TEXTSERVICE_HPP
