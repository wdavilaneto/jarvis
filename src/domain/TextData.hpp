//
// Created by walter on 21/07/16.
//

#ifndef JARVIS_TEXTDATA_HPP_HPP
#define JARVIS_TEXTDATA_HPP_HPP

#include <string>
#include <unordered_map>

using std::string;

namespace domain {

    struct TextData {
        std::string original;
        std::unordered_map<string,string> data;
    };

};

#endif //JARVIS_TEXTDATA_HPP_HPP