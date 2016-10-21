//
// Created by walter on 14/09/16.
//

#ifndef JARVIS_TEXTDOCUMENT_HPP
#define JARVIS_TEXTDOCUMENT_HPP

#include <iostream>

namespace domain {

    using std::string;

    struct TextDocument {
        size_t id = 0;
        std::string text;
    };

};

#endif //JARVIS_TEXTDOCUMENT_HPP

