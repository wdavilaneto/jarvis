find_package(Boost REQUIRED COMPONENTS unit_test_framework serialization log log_setup thread system filesystem date_time)
find_package(Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

set(Boost_USE_MULTITHREADED ON)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(RepositoryTest RepositoryTest.cpp)

target_link_libraries(
    RepositoryTest
    ${Boost_LIBRARIES}
)
