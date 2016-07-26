//
// Created by walter on 16/05/16.
//

#ifndef JARVIS_REPOSITORY_HPP
#define JARVIS_REPOSITORY_HPP

#include <domain.hpp>
#include <soci/soci.h>
#include <iostream>


namespace soci
{
    using domain::TextData;

    template<>
    struct type_conversion<TextData>
    {
        typedef values base_type;

        static void from_base(values const & v, indicator /* ind */, TextData & p)
        {
            std::cout << "->" ;
            p.id = atoll( v.get<string>("ID").c_str());
            p.original = v.get<std::string>("TEXT");
        }

        static void to_base(const TextData & p, values & v, indicator & ind)
        {
            v.set("ID", p.id);
            v.set("TEXT", p.original);
        }
    };
}

#endif //JARVIS_REPOSITORY_HPP
