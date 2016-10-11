find_package(Boost 1.59 REQUIRED COMPONENTS system thread)
find_package(Threads)

add_library(server server.cpp server.hpp CorpusHandler.hpp)

target_link_libraries( server
        dlib
        pthread
        ${Boost_LIBRARIES}
)
