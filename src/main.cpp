#include <iostream>

#include <server/server.hpp>
#include <unordered_map>
#include <fstream>


#define TEXT_FILE_PATH "../resources/test/ciencia.txt"

class TextProccessPipeline  {
public:

    void thinkAboutIt(std::string){

    }

protected:
    std::unordered_map<std::string, int> data;
};

int main(int arg, char *argv[]) {

    // This Application has no mains yet. It is Test Driven Development
    // Only tests are running for awhile server::RestfulServer server;
    try {
//        std::cout << "Initializing Jarvis on 8080" << std::endl;
//        return server.run(arg, argv);

        std::ifstream inputStream (TEXT_FILE_PATH);
        std::string text((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());

        boost::shared_ptr<TextProccessPipeline> tpp = boost::make_shared<TextProccessPipeline>();
        tpp->thinkAboutIt(text);

        return EXIT_SUCCESS;
    } catch (std::exception &ex) {
        //std::cerr << ex.what();
        return EXIT_FAILURE;
    }

};