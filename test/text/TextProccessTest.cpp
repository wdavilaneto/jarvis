#define BOOST_TEST_MODULE TextProccessTestSuite

#include <service/TextService.hpp>
#include <iostream>
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

#include <boost/test/included/unit_test.hpp>

#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"

BOOST_AUTO_TEST_SUITE(TextProccessTest_suite_1)

    BOOST_AUTO_TEST_CASE(TextProccessTest_test_case_1) {

        using namespace std;
        using namespace Poco;
        using domain::TextData;
        using service::TextService;

        string text;
        FileStream fstream(TEXT_FILE_PATH);
        if (!fstream){
            throw errno;
        }
        StreamCopier::copyToString(fstream, text);

        TextService textService;
        auto map = textService.wordCount(text);

        for (auto each : map ){
            cout << "['" << each.first << "' , "<<  each.second <<" ]" << endl;
        }

        // TODO plan some testes here

    };

BOOST_AUTO_TEST_SUITE_END()
