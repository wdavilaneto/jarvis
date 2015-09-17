cmake_minimum_required(VERSION 2.8)
project(jarvis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if (WIN32)
    set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
    set(OGRE_SAMPLES_INCLUDEPATH
            $ENV{OGRE_HOME}/Samples/include
    )
endif (WIN32)

if (UNIX)
    if (EXISTS "/usr/local/lib/OGRE/cmake")

        set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
        set(OGRE_SAMPLES_INCLUDEPATH "/usr/local/share/OGRE/samples/Common/include/") # We could just *assume* that developers uses this basepath : /usr/local

    elseif(EXISTS "/usr/lib/OGRE/cmake")

        set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
        set(OGRE_SAMPLES_INCLUDEPATH "/usr/share/OGRE/samples/Common/include/") # Otherwise, this one

    else ()
        message(SEND_ERROR "Failed to find module path.")
    endif (EXISTS "/usr/local/lib/OGRE/cmake")
endif (UNIX)


find_package(Threads)
find_package(Boost 1.54 REQUIRED thread system)
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)

## Checking BOOST dependency block
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/dist")

include_directories(
    "${PROJECT_SOURCE_DIR}/src"
)

add_subdirectory(src/client)
add_subdirectory(src/brain)

add_executable(jarvis src/main.cpp)

target_link_libraries(jarvis
        jarvisApp
        brain
        pthread
        ${Boost_LIBRARIES}
)

## POSTMAKE
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/bin)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dist/media)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist/bin)

install(TARGETS jarvis
    RUNTIME DESTINATION bin
    CONFIGURATIONS All)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/media
    DESTINATION ./
    CONFIGURATIONS Release RelWithDebInfo Debug
)

install(FILES ${CMAKE_SOURCE_DIR}/resources/bin/plugins.cfg
    ${CMAKE_SOURCE_DIR}/dist/bin/resources.cfg
    DESTINATION bin
    CONFIGURATIONS Release RelWithDebInfo Debug
)

