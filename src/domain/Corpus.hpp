//
// Created by walter on 11/08/16.
//

#ifndef JARVIS_CORPUS_HPP_HPP
#define JARVIS_CORPUS_HPP_HPP

#include <domain/Document.hpp>
#include <cmath>

#define ZERO_OCURRENCY_ON_COLLECTION 0
#define GREATEST_STEMMED_WORD_LENGHT 60

namespace domain {

    using std::string;
    using boost::shared_ptr;
    using boost::make_shared;


    typedef std::unordered_map<string, shared_ptr<KeyWord> > KeyWordCollection;
    typedef std::unordered_map<string, shared_ptr<Document> > DocumentCollection;
    typedef std::set<std::string> StopWordCollection;


    /**
     *  A Corpus is a collection of written texts, esp. the entire works of a particular subject or author
     *  1) This "DTO" assumes that once readed from Database, it MUST come with all its Keyword, stopWords, and uuids from its documents
     *  even if the value on given collection still points to a nullptr (shared_ptr)
     */
    class Corpus {
    public:

        size_t id;
        string language;
        string name;
        // Stored total of documents ( redundant with uuid's counts )
        size_t totalDocuments = 0;
        // map of unique reference of keywords of all corpus should be always on memory
        KeyWordCollection words;
        // set o all known stop words should be always on memory too
        StopWordCollection stopWords;
        // collection of Docuemnts or at leas all uuids with unloaded (nullptr) document
        DocumentCollection documents;

        bool hasStopWord(const string &word) {
            return ((word.length() > GREATEST_STEMMED_WORD_LENGHT) ||
                    (stopWords.count(word) > ZERO_OCURRENCY_ON_COLLECTION) || is_number(word.c_str()));
        }

        bool hasKeyWord(const string &word) {
            return (words.count(word) > ZERO_OCURRENCY_ON_COLLECTION);
        }

        // TODO refafctor this to a json library for json output format...
        virtual std::string toString() {
            std::string seed("Document@{totalDocuments:");
            seed.append(std::to_string(totalDocuments)).append(", keywords: [");
            for (auto each : words) {
                seed.append(each.first).append(",\n");
            }
            seed.append("]");
            return seed;
        };

        virtual std::ostream &toStream(std::ostream &strm) {
            return strm << toString();
        };

    private:

        bool is_number(const std::string &s) {
            return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
        }

    };

};

#endif //JARVIS_CORPUS_HPP_HPP
