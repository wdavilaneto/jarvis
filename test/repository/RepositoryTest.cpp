#define BOOST_TEST_MODULE RepositoryTestSuite

#include <repository/repository.hpp>

#include "soci/soci.h"
#include "soci/sqlite3/soci-sqlite3.h"
#include "soci/postgresql/soci-postgresql.h"
#include <boost/property_tree/ini_parser.hpp>

#include <iostream>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite1)

    BOOST_AUTO_TEST_CASE(repository_test_case_1) {

        #define CONFIG_FILE_PATH "../../resources/application.cfg"

        using namespace std;
        BOOST_TEST_MESSAGE("Repository toolkit tests");

        try {

            boost::property_tree::ptree config;
            boost::property_tree::ini_parser::read_ini(CONFIG_FILE_PATH, config);
            soci::session session(config.get<string>("database.dbname"), config.get<string>("database.connection"));

            dto::text_data text_data;
            // BI_MANIFESTACAO ( nr_mp , tipo_movimento , destino, movimento , pdf )
            session << "select pdf from bi_manifestacao where nr_mp = :1", soci::into(text_data.text), soci::use(
                201100742214);
            //BOOST_CHECK_GT(total, 0);
            cout << text_data.text << '\n';

        } catch (exception const &e) {
            std::cerr << "Error: " << e.what() << '\n';
        }

    };

BOOST_AUTO_TEST_SUITE_END()
