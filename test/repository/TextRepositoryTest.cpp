#define BOOST_TEST_MODULE RepositoryTestSuite

#include <repository/TextRepository.hpp>

#include <boost/filesystem.hpp>
#include <iostream>
#include <boost/property_tree/ini_parser.hpp>

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite1)

    BOOST_AUTO_TEST_CASE(repository_test_case_1) {

        using std::string;
        using repository::TextRepository;

        TextRepository textRepository;

        auto result = textRepository.findAll();
        BOOST_CHECK_GT(result.size() , 0);

        auto doc = textRepository.get(201100742214);
        BOOST_CHECK_EQUAL(doc.id , 201100742214);

    };

BOOST_AUTO_TEST_SUITE_END()
