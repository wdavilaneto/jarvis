find_package(Boost REQUIRED COMPONENTS unit_test_framework serialization mpi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(CMAKE_C_COMPILER mpicc)
SET(CMAKE_CXX_COMPILER mpic++)
#SET(CMAKE_CXX_FLAGS_DEBUG "-O2")
#ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(NeuronsOnMPITest NeuronsOnMPITest.cpp)

target_link_libraries(
        NeuronsOnMPITest
        brain
        mpi
        ${Boost_LIBRARIES}
)
