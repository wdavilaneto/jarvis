find_package(Boost 1.59 REQUIRED COMPONENTS system thread)
find_package(Threads)

add_library(server server.cpp server.h)

target_link_libraries( server
        pthread
        cppnetlib-uri
        cppnetlib-server-parsers
        ${Boost_LIBRARIES}
        ${Boost_LIBRARIES}
)
