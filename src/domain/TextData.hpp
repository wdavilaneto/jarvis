//
// Created by walter on 21/07/16.
//

#ifndef JARVIS_TEXTDATA_HPP_HPP
#define JARVIS_TEXTDATA_HPP_HPP

#include <string>
#include <unordered_map>
#include <Poco/StringTokenizer.h>
#include <boost/shared_ptr.hpp>

using std::string;

namespace domain {

    class TextData {
    public:
        TextData() {};

        std::string original;
        std::unordered_map<string, string> data;
        std::vector<string> words;
        std::vector<string> labels;

    };

};

#endif //JARVIS_TEXTDATA_HPP_HPP
