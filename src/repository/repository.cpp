//
// Created by walter on 26/07/16.
//
#include "repository.hpp"

namespace repository {

    using std::string;
    using soci::session;
    using domain::Document;

    TextDataRepository::TextDataRepository() {
        boost::property_tree::ini_parser::read_ini(CONFIG_FILE_PATH, getConfig());
    };

    TextDataRepository::~TextDataRepository() {

    };

    std::vector<Document> TextDataRepository::findAll() {

        soci::session session(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
        session.set_log_stream(&std::cout);

        domain::Document doc;

        soci::statement st = (
                session.prepare << "select nr_mp as ID, pdf as TEXT from bi_manifestacao order by nr_mp", soci::into(doc)
        );
        st.execute();

        std::vector<Document> result;
        while (st.fetch()) {
            result.push_back(doc);
        }
        return result;
    };

    Document TextDataRepository::get(size_t id) {

        soci::session session(getConfig().get<string>("database.dbname"), getConfig().get<string>("database.connection"));
        session.set_log_stream(&std::cout);

        domain::Document doc;
        session << "select nr_mp as ID, pdf as TEXT  from bi_manifestacao where nr_mp = :1", soci::into(doc), soci::use(id);

        return doc;
    };

};


