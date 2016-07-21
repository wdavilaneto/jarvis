ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS unit_test_framework log log_setup system filesystem date_time)
find_library(SQLITE3_LIBRARY sqlite3 static)
find_library(soci_core static)
find_library(soci_sqlite static)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(RepositoryTest RepositoryTest.cpp)

target_link_libraries(
        RepositoryTest
        soci_core
        soci_sqlite3
        soci_postgresql
        pq
        dl
        ${Boost_LIBRARIES}
)
