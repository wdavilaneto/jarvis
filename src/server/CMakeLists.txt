find_package(Boost 1.59 REQUIRED COMPONENTS system thread)
find_package(Threads)

add_library(server server.cpp server.hpp MainRequestHandler.hpp TrainingDataService.hpp FannHandler.hpp)

target_link_libraries( server
        dlib
#        PocoNet
#        PocoUtil
#        PocoFoundation
        pthread
        ${Boost_LIBRARIES}
)
