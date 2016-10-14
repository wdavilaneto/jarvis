#define BOOST_TEST_MODULE TextProccessTestSuite

#include <iostream>
#include <service/TextService.hpp>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TextProccessTest_suite_1)

    BOOST_AUTO_TEST_CASE(TextProccessTest_test_case_1) {

        USE_SHARED_PTR
        using std::string;
        using std::cout;
        using std::vector;
        using namespace domain;
        using service::TextService;

        TextDocument text;
        text.text = "este..., deve ?/ou nao deve, nao sei, ser, a priori, ou não '''^. um ; bom / exemplo | de texto tokenizado + de {palavras}, o.00 eco...eco...eco";

        shared_ptr<Corpus> corpus = make_shared<Corpus>();
        TextService textService;

        shared_ptr<Document> doc = textService.toDocument(corpus, text);

        BOOST_LOG_TRIVIAL(info) << doc->toString();

        bool b1, b2, b3 = false;

        // search for expeted words to be found ..
        for (auto keyword : doc->words) {
            if (keyword.first == "palavras") {
                b1 = true;
            }
            if (keyword.first == "eco") {
                b2 = true;
            }
            if (keyword.first == "bom") {
                b3 = true;
            }
        }
        BOOST_CHECK( b1 == b2 == b3);

    };

BOOST_AUTO_TEST_SUITE_END()
