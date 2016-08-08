//
// Created by walter on 21/07/16.
//

#ifndef JARVIS_TEXTDATA_HPP_HPP
#define JARVIS_TEXTDATA_HPP_HPP

#include <iostream>
#include <unordered_map>
#include <Poco/StringTokenizer.h>
#include <boost/shared_ptr.hpp>
#include <bits/unordered_set.h>
#include <set>

using std::string;

namespace domain {

    class KeyWord {
    public:
        string stemmed;
        size_t count;
        size_t tfidf;
        size_t nDocs;
    };

    typedef std::unordered_map<string, KeyWord> WordCollection;
    typedef std::set<std::string> StopWordCollection;

    class TextData {
    public:
        TextData() {};

        string uuid;
        size_t id = 0;
        std::string original;
        WordCollection words;
        std::vector<string> labels;

        virtual std::string toString() {
            std::string seed("TextData@");
            seed.append(std::to_string(id)).append("{").append(original).append("}");
            return seed;
        };

        virtual std::ostream &toStream(std::ostream &strm) {
            return strm << toString();
        };

    };


    class Corpus {
    public:
        WordCollection words; // Replicated Data
        StopWordCollection stopWords;
        WordCollection documents;

        bool hasStopWord(const string &word) {
            return stopWords.count(word) > 0;
        }

        size_t getTFIDF(const string& word) {
            return words[word].tfidf;
        }
    };

    // std::ostream &operator<<(std::ostream &o, domain::TextData &b) { return b.toStream(o); }

};


#endif //JARVIS_TEXTDATA_HPP_HPP
