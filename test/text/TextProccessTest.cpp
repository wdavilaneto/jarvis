#define BOOST_TEST_MODULE TextProccessTestSuite

#include <iostream>
#include <service/TextService.hpp>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TextProccessTest_suite_1)

    BOOST_AUTO_TEST_CASE(TextProccessTest_test_case_1) {

        using namespace std;
        using domain::TextData;
        using service::TextService;

        const string text("este..., deve ser, a priori ou não '''^. um ; bom / exemplo | de texto tokenizado + de {palavras}, ");

        TextService textService;
        auto map = textService.wordCount(text);

        for (auto each : map ) {

        }
        // TODO plan some testes here
    };

BOOST_AUTO_TEST_SUITE_END()
