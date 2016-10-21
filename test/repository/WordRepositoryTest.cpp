//
// Created by walter on 06/10/16.
//

#define BOOST_TEST_MODULE WordRepositorySuite

#include <repository/TextRepository.hpp>
#include <repository/CorpusRepository.hpp>
#include <repository/WordRepository.hpp>

#include <boost/test/included/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(WordRepositorySuite)

    BOOST_AUTO_TEST_CASE(WordRepositoryTest_1) {

        USE_SHARED_PTR;

        using std::string;
        using namespace domain;
        using namespace repository;

        CorpusRepository corpusRepository;
        WordRepository wordRepository;

        shared_ptr<Corpus> corpus = corpusRepository.get(1);

        shared_ptr<Word> plumbastromperis = make_shared<Word>();
        plumbastromperis->name = "plumbastromperis";

        wordRepository.insert(plumbastromperis);

        auto word = wordRepository.get("plumbastromperis");

        BOOST_CHECK_EQUAL(!word , true);
        auto words = wordRepository.findAllWords(1);

        BOOST_CHECK(words.size() > 0);

        wordRepository.remove(word->id);

        auto word2 = wordRepository.get("plumbastromperis");

        BOOST_CHECK_EQUAL(!word2 , false);
        // TODO plan some testes here
    };

BOOST_AUTO_TEST_SUITE_END()
