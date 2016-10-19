
#include <boost/serialization/unordered_map.hpp>
#include <service/TextService.hpp>
#include <repository/TextRepository.hpp>
#include <repository/CorpusRepository.hpp>
#include <repository/DocumentRepository.hpp>
#include <server/server.hpp>
#include <server/CorpusHandler.hpp>
//#define TEXT_FILE_PATH "../../resources/test/ciencia.txt"


USE_SHARED_PTR
using std::string;
using domain::Document;
using domain::Corpus;
using service::TextService;

using namespace server;

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
            shared_ptr<IRequestHandler> handler = make_shared<CorpusHandler>();
            server.addHandler(handler);
            //handler = make_shared<DocumentHandler>();
            server.addHandler(handler);

            server.start_async();
            BOOST_LOG_TRIVIAL(info) << "Press enter to end this program" ;
            std::cin.get();
            return 0;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }


        return EXIT_SUCCESS;
    } catch (std::exception &ex) {
        std::cerr << ex.what();
        throw errno;
    }

};