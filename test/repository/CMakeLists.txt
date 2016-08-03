find_package(Boost REQUIRED COMPONENTS log log_setup thread system filesystem)

#find_library(SQLITE3_LIBRARY sqlite3 static)
#find_library(soci_core static)
#find_library(soci_sqlite static)

#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

add_executable(RepositoryTest RepositoryTest.cpp)
add_executable(StopWordRepositoryTest StopWordRepositoryTest.cpp)


target_link_libraries(
        RepositoryTest
        repository
        ${Boost_LIBRARIES}
)

target_link_libraries(
        StopWordRepositoryTest
        repository
        PocoNet
        PocoUtil
        PocoFoundation
        ${Boost_LIBRARIES}
)
