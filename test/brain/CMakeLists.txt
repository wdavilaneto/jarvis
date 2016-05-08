find_package(Boost REQUIRED COMPONENTS unit_test_framework serialization mpi log log_setup thread system filesystem date_time)
find_package(Threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DBOOST_LOG_DYN_LINK")

set(Boost_USE_MULTITHREADED ON)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(NeuronTest NeuronTest.cpp)
add_executable(NeuronBuilderTest NeuronBuilderTest.cpp)

target_link_libraries(
    NeuronTest
    brain
    ${Boost_LIBRARIES}
)

target_link_libraries(
        NeuronBuilderTest
        brain
        ${Boost_LIBRARIES}
)
