//
// Created by walter on 16/05/16.
//

#ifndef JARVIS_REPOSITORY_HPP
#define JARVIS_REPOSITORY_HPP

#include <soci/soci.h>

namespace dto {

    struct text_data {
        // nr_mp , destino , movimento , tipo_movimento

        std::vector<std::string> classifications;
        std::vector<double> values;
        std::string text;

    };
};

#endif //JARVIS_REPOSITORY_HPP
