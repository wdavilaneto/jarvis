find_package(Boost REQUIRED COMPONENTS unit_test_framework log log_setup system filesystem date_time)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

find_library(SQLITE3_LIBRARY sqlite3 static)
find_library(soci_core static)
find_library(soci_sqlite static)

#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_library(repository ${DOMAIN} repository.hpp repository.cpp)

target_link_libraries(repository
        soci_core
        soci_sqlite3
        ${Boost_LIBRARIES}
)

