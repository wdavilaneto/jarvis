find_package(Boost REQUIRED COMPONENTS unit_test_framework )
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(NeuronTest NeuronTest.cpp)

target_link_libraries(
    NeuronTest
    brain
    ${Boost_LIBRARIES}
)

