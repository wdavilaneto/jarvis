cmake_minimum_required(VERSION 2.8)
project(jarvis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")

find_package (Threads)
find_package(Boost 1.54 REQUIRED thread system)
#find_package(OGRE REQUIRED)
#find_package(OIS REQUIRED)

## Checking BOOST dependency block
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

include_directories(${Boost_INCLUDE_DIR})
#include_directories(
#    ${OIS_INCLUDE_DIRS}
#	${OGRE_INCLUDE_DIRS}cpp
#	${OGRE_SAMPLES_INCLUDEPATH}
#	${OGRE_Overlay_INCLUDE_DIRS}
#)

set(SOURCE_FILES src/main/cpp/main.cpp)
add_executable(jarvis ${SOURCE_FILES} src/main/cpp/NeuronCore.cpp src/main/headers/NeuronCore.h src/main/headers/identifiable.h)

target_link_libraries( jarvis
    pthread
    ${Boost_LIBRARIES}
#    ${OGRE_LIBRARIES}
#    ${OIS_LIBRARIES}
#    ${OGRE_Overlay_LIBRARIES}
)