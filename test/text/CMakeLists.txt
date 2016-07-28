ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(TextProccessTest TextProccessTest.cpp TextProccessTest.cpp)

target_link_libraries(
        TextProccessTest
        ${Boost_LIBRARIES}
)
