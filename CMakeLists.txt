cmake_minimum_required(VERSION 2.8)
project(jarvis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package(Threads)
find_package(Boost 1.59 REQUIRED COMPONENTS system thread log)

## Checking BOOST dependency block
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

include_directories(
        "${PROJECT_SOURCE_DIR}/src"
        "/usr/include/postgresql"
)

add_subdirectory(src/brain)
#add_subdirectory(src/repository)
add_subdirectory(src/server)
add_subdirectory(test)

set(CORE src/core/Application.hpp src/core/identifiable.hpp)
set(REPOSITORY src/repository/TextRepository.hpp src/repository/CorpusRepository.hpp src/repository/DocumentRepository.hpp src/repository/BaseRepository.hpp src/repository/pagination/Page.hpp src/repository/WordRepository.hpp src/repository/pagination/Pageable.hpp)
set(DOMAIN src/domain.hpp src/domain/Document.hpp src/service/TextService.hpp src/domain/Corpus.hpp src/domain/TextDocument.hpp src/domain/Word.hpp)

add_executable(jarvis ${CORE} ${DOMAIN} ${REPOSITORY} src/main.cpp)

target_link_libraries(jarvis
        dlib
        server
        pthread
        soci_core
        soci_sqlite3
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