#define BOOST_TEST_MODULE StopWordRepositoryTestSuite

#include <repository/repository.hpp>
#include <repository/StopWordRepository.hpp>

#include <boost/filesystem.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/tokenizer.hpp>

#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

#define TEXT_FILE_PATH "../../resources/test/stop.txt"

BOOST_AUTO_TEST_SUITE(stop_word_test_suite1)


    BOOST_AUTO_TEST_CASE(stop_word_repository_test_case_pt_BR_stop_words) {

        boost::filesystem::path full_path(boost::filesystem::current_path());
        BOOST_TEST_MESSAGE(full_path.c_str());

        using std::string;
        using repository::StopWordRepository;

        const string lanugage ("pt_BR");

        string text;
        Poco::FileStream fstream(TEXT_FILE_PATH);
        if (!fstream) {
            throw errno;
        }
        Poco::StreamCopier::copyToString(fstream, text);
        fstream.close();

        StopWordRepository repository;
        repository.remove(lanugage);
        repository.insert(lanugage, text);
        auto result = repository.get(lanugage);

        string example("teríamos");
        bool found = false;
        boost::tokenizer<> tokenizer(result);
        for (auto each : tokenizer) {
            std::cout << each << std::endl;
            if (each == example) {
                found = true;
                break;
            }
        }
        BOOST_REQUIRE_EQUAL(found, true);
    };


BOOST_AUTO_TEST_SUITE_END()
