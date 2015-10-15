find_package(Boost REQUIRED COMPONENTS unit_test_framework serialization mpi)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#SET(CMAKE_CXX_FLAGS_DEBUG "-O2")

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(NeuronTest NeuronTest.cpp)

target_link_libraries(
    NeuronTest
    brain
    ${Boost_LIBRARIES}
)

add_subdirectory(mpi)