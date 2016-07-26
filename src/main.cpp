
#include <service/TextService.hpp>

#include <server/server.hpp>

#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"


#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"

using namespace std;
using namespace Poco;
using domain::TextData;
using service::TextService;


class TextProccessPipeline {
public:
    TextProccessPipeline() {};

    ~TextProccessPipeline() {

    };

    void thinkAboutIt(string text) {

        // save the original text
        data.original = Poco::replace(text, "\n\n", "\n");

        TextService textService;
        data.wordCount = textService.wordCount(data.original);

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
        if (!fstream){
            throw errno;
        }
        StreamCopier::copyToString(fstream, text);

        boost::shared_ptr<TextProccessPipeline> tpp = boost::make_shared<TextProccessPipeline>();
        tpp->thinkAboutIt(text);



        return EXIT_SUCCESS;
    } catch (std::exception &ex) {
        //std::cerr << ex.what();
        return EXIT_FAILURE;
    }

};