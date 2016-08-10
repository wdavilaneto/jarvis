
#include <service/TextService.hpp>
#include <repository/repository.hpp>
#include <server/server.hpp>

#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/unordered_map.hpp>

#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"


USE_SHARED_PTR
using namespace std;
using namespace Poco;
using domain::TextData;
using domain::Corpus;

using service::TextService;

int main(int arg, char *argv[]) {

    // This Application has no mains yet. It is Test Driven Development
    // Only tests are running for awhile server::RestfulServer server;
    try {
//        std::cout << "Initializing Jarvis on 8080" << std::endl;
//        return server.run(arg, argv)
        shared_ptr<Corpus> corpus = make_shared<Corpus>();

        repository::TextDataRepository textRepository;
        auto result = textRepository.findAll();

        TextService textService;
        cout << result.size() << endl;

        for (auto doc : result) {
            textService.addToCorpus(corpus, doc.original);
        }

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