find_package(Boost REQUIRED COMPONENTS unit_test_framework log log_setup thread system filesystem date_time)
find_package(Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(FannTest fann_test.cpp)

target_link_libraries(FannTest
    pthread
    fann
    ${Boost_LIBRARIES}
)

