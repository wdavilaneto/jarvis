ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS unit_test_framework log)

add_executable(TextProccessTest TextProccessTest.cpp)
target_link_libraries(
        TextProccessTest
        dlib
        pthread
        ${Boost_LIBRARIES}
)

add_executable(TextServiceSuite TextServiceSuite.cpp)
target_link_libraries(
        TextServiceSuite
        dlib
        pthread
        soci_core
        soci_sqlite3
        ${Boost_LIBRARIES}
)
