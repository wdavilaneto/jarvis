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
    using std::string;
    using domain::Document;

    template<>
    struct type_conversion<Document> {
        typedef values base_type;

        static void from_base(values const &v, indicator /* ind */, Document &p) {
            p.id = atoll(v.get<string>("ID").c_str());
            if (v.get_indicator("TEXT") == soci::i_ok) {
                p.original = v.get<std::string>("TEXT");
            }
        }

        static void to_base(const Document &p, values &v, indicator &ind) {
            v.set("ID", p.id);
            v.set("TEXT", p.original);
        }
    };

}

namespace repository {

    using domain::Document;

    class TextDataRepository : public core::ApplicationAware {
    public:

        TextDataRepository();

        virtual ~TextDataRepository();

        std::vector<Document> findAll();

        Document get(size_t id);

    };

};

#endif //JARVIS_REPOSITORY_HPP
