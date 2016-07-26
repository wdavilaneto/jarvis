ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS unit_test_framework log log_setup system filesystem date_time )

add_executable(TextProccessTest TextProccessTest.cpp TextProccessTest.cpp)

target_link_libraries(
        TextProccessTest
        PocoUtil
        PocoFoundation
        ${Boost_LIBRARIES}
)
