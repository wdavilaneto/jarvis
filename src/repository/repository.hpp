//
// Created by walter on 16/05/16.
//

#ifndef JARVIS_REPOSITORY_HPP
#define JARVIS_REPOSITORY_HPP

#define CONFIG_FILE_PATH "../../resources/application.cfg"

#include <core/Application.hpp>
#include <domain.hpp>
#include <soci/soci.h>
#include "soci/sqlite3/soci-sqlite3.h"
#include <boost/property_tree/ini_parser.hpp>

namespace soci {
    using domain::TextData;

    template<>
    struct type_conversion<TextData> {
        typedef values base_type;

        static void from_base(values const &v, indicator /* ind */, TextData &p) {
            p.id = atoll(v.get<string>("ID").c_str());
            if (v.get_indicator("TEXT") == soci::i_ok) {
                p.original = v.get<std::string>("TEXT");
            }
        }

        static void to_base(const TextData &p, values &v, indicator &ind) {
            v.set("ID", p.id);
            v.set("TEXT", p.original);
        }
    };

}

namespace repository {

    using domain::TextData;

    class TextDataRepository : public core::ApplicationAware {
    public:

        TextDataRepository();

        virtual ~TextDataRepository();

        std::vector<TextData> findAll();

        TextData get(size_t id);

    };

};

#endif //JARVIS_REPOSITORY_HPP
