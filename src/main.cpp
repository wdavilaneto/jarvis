
#include <service/TextService.hpp>
#include <repository/repository.hpp>
#include <server/server.hpp>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <repository/CorpusRepository.hpp>

#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"


USE_SHARED_PTR
using std::string;
using domain::Document;
using domain::Corpus;

using service::TextService;

int main(int arg, char *argv[]) {

    // This Application has no mains yet. It is Test Driven Development
    // Only tests are running for awhile server::RestfulServer server;
    try {
//        std::cout << "Initializing Jarvis on 8080" << std::endl;
//        return server.run(arg, argv)

        repository::CorpusRepository corpusRepository;
        shared_ptr<Corpus> corpus = corpusRepository.get("pareceres");

        repository::TextDataRepository textRepository;
        auto result = textRepository.findAll();

        TextService textService;
        std::cout << result.size() << std::endl;

        for (auto doc : result) {
            textService.addToCorpus(corpus, doc.original);
        }

        std::cout << &corpus;

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