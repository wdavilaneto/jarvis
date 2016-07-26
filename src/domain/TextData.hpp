//
// Created by walter on 21/07/16.
//

#ifndef JARVIS_TEXTDATA_HPP_HPP
#define JARVIS_TEXTDATA_HPP_HPP

#include <string>
#include <unordered_map>
#include <Poco/StringTokenizer.h>
#include <boost/shared_ptr.hpp>
#include <bits/unordered_set.h>

using std::string;

namespace domain {

    class TextData {
    public:
        TextData() {};

        size_t id;
        std::string original;
        std::unordered_map<string,size_t> wordCount;
        std::vector<string> labels;

    };

};

#endif //JARVIS_TEXTDATA_HPP_HPP
