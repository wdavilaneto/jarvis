#define BOOST_TEST_MODULE meta_test_suite_1

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "meta/util/aligned_alloc.h"
#include "meta/analyzers/analyzer.h"
#include "meta/analyzers/tokenizers/icu_tokenizer.h"
#include "meta/analyzers/filters/all.h"
#include "meta/analyzers/ngram/ngram_word_analyzer.h"
#include "meta/corpus/document.h"
#include "meta/io/filesystem.h"
#include "meta/parser/sr_parser.h"
#include "meta/sequence/io/ptb_parser.h"
#include "meta/sequence/perceptron.h"
#include "meta/sequence/sequence.h"
#include "meta/util/shim.h"

#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>
#include <boost/test/included/unit_test.hpp>

std::string get_content(const std::string &file, const std::string &prefix) {
    std::ifstream input{prefix + file, std::ios::binary};
    std::ostringstream oss;
    oss << input.rdbuf();
    std::string content{oss.str()};
    std::replace_if(content.begin(), content.end(), [](char ch) {
        return ch == '\n' || ch == '\t';
    }, ' ');
    return content;
}

BOOST_AUTO_TEST_SUITE(meta_test_suite_1)

    BOOST_AUTO_TEST_CASE(meta_test_case_1) {

        #define CONFIG_FILE_PATH "../../resources/meta/config.toml"

        using namespace std;
        using namespace meta;

        //boost::filesystem::path full_path(boost::filesystem::current_path());
        boost::property_tree::ptree config;
        boost::property_tree::ini_parser::read_ini(CONFIG_FILE_PATH, config);

        std::cout << "Running stemming algorithm" << std::endl;

        using namespace meta::analyzers;

        std::unique_ptr<token_stream> stream = make_unique<tokenizers::icu_tokenizer>();
        stream = make_unique<filters::lowercase_filter>(std::move(stream));
        stream = make_unique<filters::porter2_filter>(std::move(stream));
        stream = make_unique<filters::empty_sentence_filter>(std::move(stream));

        while (*stream)
        {
            auto next = stream->next();
            if (next == "<s>" || next == " ")
                continue;
            else if (next == "</s>")
                cout << " fim docmento" << std::endl;
            else
                cout << next << " ";
        }

    };

BOOST_AUTO_TEST_SUITE_END()
