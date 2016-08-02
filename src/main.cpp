
#include <service/TextService.hpp>
#include <repository/repository.hpp>
#include <server/server.hpp>

#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/unordered_map.hpp>

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
//        return server.run(arg, argv)
        std::unordered_map<string, size_t> corpus;

        repository::TextDataRepository textRepository;
        auto result = textRepository.findAll();

        TextService textService;

        cout << result.size() << endl;
        for (auto doc : result) {
            doc.wordCount = textService.wordCount(doc.original);
            for (auto each : doc.wordCount) {
                if (corpus.count(each.first)) {
                    corpus[each.first] += each.second;
                } else {
                    corpus[each.first] = 1;
                }
            }
        }
        cout << corpus.size() << endl;

//        std::ofstream ofs("corpus.dat");
//        boost::archive::binary_oarchive objectArchive(ofs);
//        objectArchive << corpus;
//
//        std::ifstream ifs("corpus.dat");
//        boost::archive::binary_iarchive ia(ifs);
//        std::unordered_map<string, size_t> corpus2;
//        ia >> corpus2;
//
//        for(auto each : corpus2) {
//            cout << "{'"<< each.first<< "': "<< each.second<<"},\n" ;
//        }

        return EXIT_SUCCESS;
    } catch (std::exception &ex) {
        std::cerr << ex.what();
        throw errno;
    }

};