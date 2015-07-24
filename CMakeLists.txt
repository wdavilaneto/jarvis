cmake_minimum_required(VERSION 2.8)
project(jarvis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Threads)
find_package(Boost 1.54 REQUIRED thread system)
find_package(CURL)

## Checking BOOST dependency block
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

include_directories(/usr/include/curl)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(jarvis ${SOURCE_FILES} brain/NeuronCore.cpp brain/NeuronCore.h voice/Voice.cpp voice/Voice.h)

target_link_libraries( jarvis
    pthread
    ${Boost_LIBRARIES}
    curl
)