cmake_minimum_required(VERSION 2.8)
project(jarvis)

#SET(CMAKE_CXX_COMPILER mpic++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## ************************************
## Conan managed Dependencies
## ************************************
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake) #Clion, with conanbuildinfo.cmake in build folder
    include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
else()
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Not CLion
endif()
conan_basic_setup()


find_package(Threads)

## Checking BOOST dependency block
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

include_directories("${PROJECT_SOURCE_DIR}/src")

add_subdirectory(src/brain)
add_subdirectory(src/server)
add_subdirectory(test)

add_executable(jarvis src/main.cpp)

target_link_libraries( jarvis
        server
        ${CONAN_LIBS}
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