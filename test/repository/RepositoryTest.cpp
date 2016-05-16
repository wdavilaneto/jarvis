#define BOOST_TEST_MODULE RepositoryTestSuite

#include "soci/soci.h"
//#include "soci/sqlite3/soci-sqlite3.h"
//#include "soci/postgresql/soci-postgresql.h"
#include <iostream>

#include <boost/test/unit_test.hpp>



BOOST_AUTO_TEST_CASE(RepositoryTest) {

    using namespace std;

    BOOST_TEST_MESSAGE("Repository toolkit tests");

    try {
        //session sql(sqlite3, "../../resources/database/fann.database");
        //string name;
        //sql << "select name from neural_network where id = :id ", into(name), use(1);


    } catch (exception const &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

};