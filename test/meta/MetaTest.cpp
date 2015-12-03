#define BOOST_TEST_MODULE TesteServerTestSuite

#include <iostream>
#include <boost/make_shared.hpp>
#include <boost/test/unit_test.hpp>
#include <meta/TextAnalysis.hpp>

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <iostream>


using boost::shared_ptr;
using boost::make_shared;

using namespace domain;
namespace fs = boost::filesystem;
using namespace boost::filesystem;
using std::stringstream;

std::string slurp (const char* _path ) {
    static fs::path resource_path( fs::system_complete("../../resources/meta/"));
    fs::ifstream configFile( resource_path / _path);
    return string(static_cast<stringstream const&>(stringstream() << configFile.rdbuf()).str());
}


BOOST_AUTO_TEST_CASE(MetaTest) {

    BOOST_TEST_MESSAGE("Meta toolkit tests");

    // READ CONFIG
    string config = slurp("config.toml");
    string stopwords = slurp("data/stopwords_pt.txt");

    std::cout << "********" <<  config << "config.toml" << std::endl;


};