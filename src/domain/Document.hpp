//
// Created by walter on 21/07/16.
//

#ifndef JARVIS_TEXTDATA_HPP_HPP
#define JARVIS_TEXTDATA_HPP_HPP

#include <iostream>
#include <unordered_map>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <map>


namespace domain {

    using std::string;
    using boost::shared_ptr;
    using boost::make_shared;

    typedef std::unordered_map<string, size_t> WordCollection;

    class Document {
    public:

        Document() = default;

        string uuid;
        size_t refId = 0; // original id (sequence probably)
        std::string original;
        WordCollection words;

        bool hasKeyWord(string &word) {
            return words.count(word) > 0;
        };


        void addKeyWord(string &word) {
            if (!hasKeyWord(word)) {
                words[word] = 1;
            } else {
                words[word] = words[word] +1;
            }
        }

        virtual std::string toString() {
            // TODO implement Cache...
            boost::property_tree::ptree out;
            out.put("uuid", uuid);
            out.put("id", refId);

            boost::property_tree::ptree words_node;
            for (auto each : words) {
                boost::property_tree::ptree word_node;
                word_node.put("name", each.first);
                word_node.put("count", each.second);
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

    };

    /**
     * Each Instance of this class should be an Unique instance
     * with it Steemd version as "unique id"
     */
    class KeyWord {
    public:
        string stemmed;
        string language;
        size_t count = 0;
        size_t nDocs = 0;
        double tfidf = 0.0;

        bool hasAppereadOnDocument(shared_ptr<Document> d) {
            return docs.count(d->uuid);
        };

        bool addDocument(shared_ptr<Document> d) {
            docs[d->uuid] = d;
            nDocs++;
        }

    private:
        std::map<string, shared_ptr<Document> > docs;
    };

    // std::ostream &operator<<(std::ostream &o, domain::Document &b) { return b.toStream(o); }

};


#endif //JARVIS_TEXTDATA_HPP_HPP
