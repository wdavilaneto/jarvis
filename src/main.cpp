
#include <boost/serialization/unordered_map.hpp>
#include <service/TextService.hpp>
#include <repository/TextRepository.hpp>
#include <repository/CorpusRepository.hpp>
#include <repository/DocumentRepository.hpp>
#include <server/server.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

//#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"


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

        try
        {
            // create an instance of our web server
            server::RestfulServer server;
            server.set_listening_port(9000);
            server.start_async();
//            std::cout << "Press enter to end this program" << std::endl;
//            std::cin.get();
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

        repository::CorpusRepository corpusRepository;
        repository::TextRepository textRepository;
        repository::DocumentRepository documentRepository;

        TextService textService;

        shared_ptr<Corpus> corpus = corpusRepository.get("pareceres");

        auto result = textRepository.findAll();
        for (auto td : result) {
            shared_ptr<Document> document = textService.toDocument(corpus,td);
            documentRepository.persist(document);
        }

        for (auto doc : result) {
//            textService.addToCorpus(corpus, doc);
        }

//        std::cout << corpus->toString() << std::endl;

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