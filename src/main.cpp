#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/make_shared.hpp>

#include <client/JarvisApplication.h>

int main(int argc, char *argv[]) {

    using namespace boost;
    using namespace std;

    cout << "Initializing Jarvis..." << endl;

    JarvisApplication jarvisApplication;
    try {
        jarvisApplication.go();
    } catch (Ogre::Exception &e) {
        std::cerr << "An exception has occured: " << e.getFullDescription().c_str() << std::endl;
    }



    return 0;
}
