cmake_minimum_required(VERSION 2.8)
project(jarvis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads)
find_package(Boost 1.59 REQUIRED COMPONENTS system thread)

## Checking BOOST dependency block
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

include_directories(
        "${PROJECT_SOURCE_DIR}/src"
        "/usr/include/postgresql"
)

add_subdirectory(src/brain)
add_subdirectory(src/server)
add_subdirectory(test)

add_executable(jarvis src/main.cpp)

target_link_libraries( jarvis
        server
        pthread
        ${Boost_LIBRARIES}
)


## ****************
## Install Block
## ****************
install(TARGETS jarvis
        RUNTIME
        DESTINATION bin
        CONFIGURATIONS All
)

install(DIRECTORY
        ${CMAKE_SOURCE_DIR}/resources/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

install(DIRECTORY
        ${CMAKE_SOURCE_DIR}/resources/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug
)