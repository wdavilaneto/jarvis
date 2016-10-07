find_package(Boost REQUIRED COMPONENTS log log_setup thread system filesystem)

#find_library(SQLITE3_LIBRARY sqlite3 static)
#find_library(soci_core static)
#find_library(soci_sqlite static)

#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

add_executable(TextRepositoryTest TextRepositoryTest.cpp)
target_link_libraries(
        TextRepositoryTest
        soci_core
        soci_sqlite3
        ${Boost_LIBRARIES}
)

add_executable(StopWordRepositoryTest StopWordRepositoryTest.cpp)
target_link_libraries(
        StopWordRepositoryTest
        soci_core
        soci_sqlite3
        ${Boost_LIBRARIES}
)

add_executable(DocumentRepositoryTest DocumentRepositoryTest.cpp)
target_link_libraries(
        DocumentRepositoryTest
        soci_core
        soci_sqlite3
        ${Boost_LIBRARIES}
)

