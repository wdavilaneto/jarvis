#include <domain.hpp>

#include <iostream>
#include <server/server.hpp>

#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"
#include <dlib/svm.h>
#include <dlib/data_io.h>
#include <boost/tokenizer.hpp>

#include <mitie.h>

#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"

using namespace std;
using namespace Poco;
using domain::TextData;


class TextProccessPipeline {
public:
    TextProccessPipeline() {};

    ~TextProccessPipeline() {

    };

    void thinkAboutIt(string text) {
        // save the original text
        data.original = Poco::replace(text, "\n\n", "\n");

        boost::tokenizer<> tokenizer(data.original);
        for (boost::tokenizer<>::iterator beg = tokenizer.begin(); beg != tokenizer.end(); ++beg) {
            data.words.push_back(std::move(*beg));
        }

        string str(cat(std::string("\n"), data.words.begin(), data.words.end()));
        cout << str << endl;

    }

protected:
    TextData data;
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