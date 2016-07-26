#define BOOST_TEST_MODULE RepositoryTestSuite

#include <repository/repository.hpp>

#include <boost/filesystem.hpp>
#include <iostream>
#include <boost/property_tree/ini_parser.hpp>

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite1)

    BOOST_AUTO_TEST_CASE(repository_test_case_1) {

        boost::filesystem::path full_path(boost::filesystem::current_path());
        BOOST_TEST_MESSAGE(string() << full_path);

        using std::string;
        using repository::TextDataRepository;

        TextDataRepository textRepository;

        auto result = textRepository.findAll();
        BOOST_CHECK_GT(result.size() , 0);

        auto doc = textRepository.get(201100742214);
        BOOST_CHECK_EQUAL(doc.id , 201100742214);

    };

BOOST_AUTO_TEST_SUITE_END()
