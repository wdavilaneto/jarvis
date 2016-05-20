#define BOOST_TEST_MODULE RepositoryTestSuite

#include <repository/repository.hpp>

#include "soci/soci.h"
//#include "soci/sqlite3/soci-sqlite3.h"?
#include "soci/postgresql/soci-postgresql.h"
#include <boost/property_tree/ini_parser.hpp>

#include <iostream>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(RepositoryTest) {

    using namespace std;

    BOOST_TEST_MESSAGE("Repository toolkit tests");

    try {
        boost::property_tree::ptree pt;
        boost::property_tree::ini_parser::read_ini("../../resources/application.cfg", pt);

        string conn = " hostaddr=" + pt.get<std::string>("database.host");
        conn += " user=" + pt.get<std::string>("database.usename");
        conn += " password=" + pt.get<std::string>("database.password");

        //session sql(sqlite3, "../../resources/database/fann.database");
        //string name;
        //sql << "select name from neural_network where id = :id ", into(name), use(1);

        soci::session session(soci::postgresql, conn);

        dto::text_data text_data;
        long total =0 ;
        session << "select count(*) from bi_manifestacao ", soci::into(total);
        cout << total  << '\n';

        BOOST_CHECK_GT( total , 0 );

    } catch (exception const &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

};