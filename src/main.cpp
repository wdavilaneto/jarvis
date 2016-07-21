#include <iostream>

#include <server/server.hpp>
#include <boost/iostreams/copy.hpp>
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/StringTokenizer.h"

#include "domain.hpp"

#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"

using namespace std;
using namespace Poco;
using domain::TextData;

class TextProccessPipeline {
public:

    void thinkAboutIt(string text) {
        textData.original = text;
        StringTokenizer tokenized(text, ",;.\n", StringTokenizer::TOK_TRIM | StringTokenizer::TOK_IGNORE_EMPTY);

        std::string s(cat(std::string("|"), tokenized.begin(), tokenized.end()));

        cout << s << endl;

    }

protected:
    TextData textData;

};

int main(int arg, char *argv[]) {

    // This Application has no mains yet. It is Test Driven Development
    // Only tests are running for awhile server::RestfulServer server;
    try {
//        std::cout << "Initializing Jarvis on 8080" << std::endl;
//        return server.run(arg, argv);

        string text;
        FileStream fstream(TEXT_FILE_PATH);
        StreamCopier::copyToString(fstream, text);

        boost::shared_ptr<TextProccessPipeline> tpp = boost::make_shared<TextProccessPipeline>();
        tpp->thinkAboutIt(text);

        return EXIT_SUCCESS;
    } catch (std::exception &ex) {
        //std::cerr << ex.what();
        return EXIT_FAILURE;
    }

};