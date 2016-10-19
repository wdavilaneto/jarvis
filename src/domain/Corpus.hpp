//
// Created by walter on 11/08/16.
//

#ifndef JARVIS_CORPUS_HPP_HPP
#define JARVIS_CORPUS_HPP_HPP

#include <domain/Document.hpp>
#include <cmath>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#define ZERO_OCURRENCY_ON_COLLECTION 0
#define GREATEST_STEMMED_WORD_LENGHT 60
#define SMALLEST_STEMMED_WORD_LENGHT 3

namespace domain {

    using std::string;
    using boost::shared_ptr;
    using boost::make_shared;


    typedef std::unordered_map<string, shared_ptr<KeyWord> > KeyWordCollection;
    typedef std::unordered_map<string, shared_ptr<Document> > DocumentCollection; //(uuid , Document)
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
        // map of unique reference of keywords of all corpus should be always on memory
        KeyWordCollection words;
        // set o all known stop words should be always on memory too
        StopWordCollection stopWords;
        // collection of Docuemnts or at leas all uuids with unloaded (nullptr) document
        DocumentCollection documents;

        bool hasStopWord(const string &word) {
            return ((word.length() > GREATEST_STEMMED_WORD_LENGHT) || (word.length() <= SMALLEST_STEMMED_WORD_LENGHT) || (stopWords.count(word) > ZERO_OCURRENCY_ON_COLLECTION) || is_number(word.c_str()));
        }

        bool hasKeyWord(const string &word) {
            return (words.count(word) > ZERO_OCURRENCY_ON_COLLECTION);
        }

        size_t getTotalDocuments(){
            //return documents.size();
            return totalDocuments;
        }

        bool hasDocument(const Document &document) {
            return (documents.count(document.uuid));
        }

        void addDocument(shared_ptr<Document> document) {
            // FIXME TODO this should be Threadsafe (atomic)
            totalDocuments++;
            documents[document->uuid] = document;
        }

        // TODO refafctor this to a json library for json output format...
        virtual std::string toString() {
            boost::property_tree::ptree out;
            out.put("id", id);
            out.put("language", language);
            out.put("name", name);
            out.put("totalDocuments", totalDocuments);

            boost::property_tree::ptree words_node;
            for (auto each : words) {
                boost::property_tree::ptree word_node;
                word_node.put("word.name", each.first);
                word_node.put("word.count", each.second->count);
                word_node.put("word.nDocs", each.second->nDocs);
                word_node.put("word.tfidf", each.second->tfidf);
                words_node.push_back(std::make_pair("", word_node));
            }
            out.add_child("words", words_node);

            std::ostringstream oss;
            boost::property_tree::write_json(oss, out, false);
            return oss.str();
        };

        virtual std::ostream &toStream(std::ostream &strm) {
            return strm << toString();
        };

    private:
        // Stored total of documents ( redundant with uuid's counts )
        size_t totalDocuments = 0;

        bool is_number(const std::string &s) {
            return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
        }

    };

};

#endif //JARVIS_CORPUS_HPP_HPP
