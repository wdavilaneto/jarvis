#define BOOST_TEST_MODULE RepositoryTestSuite

#include <repository/repository.hpp>

#include "soci/sqlite3/soci-sqlite3.h"

#include <boost/filesystem.hpp>
#include <iostream>
#include <boost/property_tree/ini_parser.hpp>

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite1)

    BOOST_AUTO_TEST_CASE(repository_test_case_1) {

        #define CONFIG_FILE_PATH "../../resources/application.cfg"

        using namespace std;

        boost::filesystem::path full_path(boost::filesystem::current_path());
        BOOST_TEST_MESSAGE(string() << full_path);

        try {

            boost::property_tree::ptree config;
            boost::property_tree::ini_parser::read_ini(CONFIG_FILE_PATH, config);
            soci::session session(config.get<string>("database.dbname"), config.get<string>("database.connection"));
            session.set_log_stream(&std::cout);

            domain::TextData doc;
            // BI_MANIFESTACAO ( nr_mp , tipo_movimento , destino, movimento , pdf )
            //session << "select nr_mp, pdf from bi_manifestacao ", soci::into(doc.id) , soci::into(doc.original);

            soci::statement st = (session.prepare << "select nr_mp as ID, pdf as TEXT from bi_manifestacao order by nr_mp", soci::into(doc));
            //BOOST_CHECK_GT(total, 0);
            st.execute();
            while (st.fetch())
            {
                cout << doc.id << '\n';
            }


        } catch (exception const &e) {
            std::cerr << "Error: " << e.what() << '\n';
        }

    };

BOOST_AUTO_TEST_SUITE_END()
