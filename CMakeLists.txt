cmake_minimum_required(VERSION 2.8)
project(jarvis)

#SET(CMAKE_CXX_COMPILER mpic++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
##set(CMAKE_CXX_FLAGS_DEBUG "-O2")

find_package(Threads)
#find_package(Boost 1.59 REQUIRED COMPONENTS unit_test_framework serialization mpi log log_setup thread system filesystem date_time)
find_package(Boost 1.59 REQUIRED COMPONENTS system thread)

## Checking BOOST dependency block
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

include_directories(
        "${PROJECT_SOURCE_DIR}/src"
)

add_subdirectory(src/brain)
add_subdirectory(src/server)
add_subdirectory(test)

add_executable(jarvis src/main.cpp)

target_link_libraries( jarvis
        server
        ${Boost_LIBRARIES}
)

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