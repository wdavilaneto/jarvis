#define BOOST_TEST_MODULE RepositoryTestSuite

#include "soci/soci.h"
//#include "soci/sqlite3/soci-sqlite3.h"?
#include "soci/postgresql/soci-postgresql.h"
#include <iostream>

#include <boost/test/unit_test.hpp>



BOOST_AUTO_TEST_CASE(RepositoryTest) {

    using namespace std;

    BOOST_TEST_MESSAGE("Repository toolkit tests");

    try {
        //session sql(sqlite3, "../../resources/database/fann.database");
        //string name;
        //sql << "select name from neural_network where id = :id ", into(name), use(1);

        soci::session session (soci::postgresql , "dbname=//10.0.252.52 user=bi password=bi");

        int total;
        session << "select count(*) from bi_manifestacao ", soci::into(total);

        cout << "result: " << total;

    } catch (exception const &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

};