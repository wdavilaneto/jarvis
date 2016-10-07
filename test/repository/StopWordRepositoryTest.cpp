#define BOOST_TEST_MODULE StopWordRepositoryTestSuite

#include <repository/StopWordRepository.hpp>

#include <boost/filesystem.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/tokenizer.hpp>


#define TEXT_FILE_PATH "../../resources/test/stop.txt"

BOOST_AUTO_TEST_SUITE(stop_word_test_suite1)


    BOOST_AUTO_TEST_CASE(stop_word_repository_test_case_pt_BR_stop_words) {

        boost::filesystem::path full_path(boost::filesystem::current_path());
        BOOST_TEST_MESSAGE(full_path.c_str());

        using std::string;
        using repository::StopWordRepository;

        const string lanugage("pt_BR");

        std::fstream fstream(TEXT_FILE_PATH);
        if (!fstream) {
            throw errno;
        }
        std::stringstream strStream;
        strStream << fstream.rdbuf();   //read the file
        string text = strStream.str();  //str holds the content of the file
        fstream.close();

        StopWordRepository repository;

        repository.remove(lanugage);
        auto result1 = repository.get(lanugage);
        BOOST_REQUIRE_EQUAL(result1.empty(), true);

        repository.insert(lanugage, text);
        auto result2 = repository.get(lanugage);

        BOOST_REQUIRE_EQUAL(result2.empty(), false);

        string example("do");
        bool found = false;
        boost::tokenizer<> tokenizer(result2);
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
