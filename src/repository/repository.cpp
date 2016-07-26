//
// Created by walter on 26/07/16.
//
#include "repository.hpp"

namespace repository {

    using soci::session;
    using domain::TextData;

    TextDataRepository::TextDataRepository() {
        boost::property_tree::ini_parser::read_ini(CONFIG_FILE_PATH, config);
    };

    TextDataRepository::~TextDataRepository() {

    };

    std::vector<TextData> TextDataRepository::findAll() {

        soci::session session(config.get<string>("database.dbname"), config.get<string>("database.connection"));
        session.set_log_stream(&std::cout);

        domain::TextData doc;

        soci::statement st = (session.prepare << "select nr_mp as ID, pdf as TEXT from bi_manifestacao order by nr_mp", soci::into(doc));

        st.execute();

        std::vector<TextData> result;
        while (st.fetch()) {
            result.push_back(doc);
        }
        return result;
    };

    TextData TextDataRepository::get(size_t id) {

        soci::session session(config.get<string>("database.dbname"), config.get<string>("database.connection"));
        session.set_log_stream(&std::cout);

        domain::TextData doc;
        session << "select nr_mp as ID, pdf as TEXT  from bi_manifestacao where nr_mp = :1", soci::into(doc), soci::use(id);

        return doc;
    };

};


