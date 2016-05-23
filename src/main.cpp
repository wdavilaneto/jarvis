#include <iostream>

#include <server/server.hpp>


int main(int arg, char *argv[]) {

    std::cout << "Initializing Jarvis on 8080" << std::endl;

    // This Application has no mains yet.
    // It is Test Driven Development
    // Only tests are running for awhile
    server::RestfulServer server;

    try {
        return server.run(arg, argv);
    } catch (std::exception &ex) {
        //std::cerr << ex.what();
        return EXIT_FAILURE;
    }

};