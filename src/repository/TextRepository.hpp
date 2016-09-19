//
// Created by walter on 19/09/16.
//

#ifndef JARVIS_TEXTREPOSITORY_HPP
#define JARVIS_TEXTREPOSITORY_HPP

#include <core/Application.hpp>
#include <domain.hpp>
#include <soci/soci.h>

#define CONFIG_FILE_PATH "../../resources/application.cfg"

namespace soci {
    using std::string;
    using domain::Document;
    using domain::TextDocument;


    template<>
    struct type_conversion<TextDocument> {
        typedef values base_type;

        static void from_base(values const &v, indicator /* ind */, TextDocument &p) {
            p.id = atoll(v.get<string>("ID").c_str());
            if (v.get_indicator("TEXT") == soci::i_ok) {
                p.text = v.get<std::string>("TEXT");
            }
        }

        static void to_base(const TextDocument &p, values &v, indicator &ind) {
            v.set("ID", p.id);
            v.set("TEXT", p.text);
        }
    };

}

namespace repository {

    using std::string;
    using domain::Document;
    using domain::TextDocument;

    class TextRepository : public core::ApplicationAware {
    public:

        TextRepository() {
        };

        virtual ~TextRepository() {

        };

        std::vector<TextDocument> findAll() {

            std::vector<TextDocument> result;
            TextDocument doc;

            soci::session session(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
            session.set_log_stream(&std::cout);

            soci::statement st = (
                    session.prepare << getConfig().get<string>("repository.findAllTexts"), soci::into(doc)
            );
            st.execute();

            while (st.fetch()) {
                result.push_back(doc);
            }
            return result;
        };

        TextDocument get(size_t id) {
            domain::TextDocument doc;

            soci::session session(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
            session.set_log_stream(&std::cout);

            session << "select nr_mp as ID, pdf as TEXT  from bi_manifestacao where nr_mp = :1", soci::into(doc), soci::use(id);

            return doc;
        };


    };

};

#endif //JARVIS_TEXTREPOSITORY_HPP
