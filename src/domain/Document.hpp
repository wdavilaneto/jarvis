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

namespace domain {

    using std::string;
    using boost::shared_ptr;
    using boost::make_shared;

    class KeyWord {
    public:
        string stemmed;
        size_t count = 0;
        size_t nDocs = 0;
        double tfidf = 0;
    };

    typedef std::unordered_map<string, size_t> WordCollection;

    class Document {
    public:

        Document()  = default;

        string uuid;
        size_t refId = 0; // original id (squence probably)
        std::string original;
        WordCollection words;


        virtual std::string toString() {
            std::string seed("Document@");
            seed.append(std::to_string(refId)).append("{").append(original).append("}");
            return seed;
        };

        virtual std::ostream &toStream(std::ostream &strm) {
            return strm << toString();
        };

    };

    // std::ostream &operator<<(std::ostream &o, domain::Document &b) { return b.toStream(o); }

};


#endif //JARVIS_TEXTDATA_HPP_HPP
