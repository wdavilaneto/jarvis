//
// Created by walter on 16/05/16.
//

#ifndef JARVIS_REPOSITORY_HPP
#define JARVIS_REPOSITORY_HPP

#include <soci/soci.h>

struct text_dto {
    // nr_mp , destino , movimento , tipo_movimento

    std::vector<std::string> classifications;
    soci::blob pdf;

};

#endif //JARVIS_REPOSITORY_HPP
