set(TEST_PROJECT_NAME "${PROJECT_NAME}_Test")
message(STATUS "Setting up test project ${TEST_PROJECT_NAME}")

enable_testing()

add_executable(${TEST_PROJECT_NAME} BasicTests.cpp)

target_link_libraries(${TEST_PROJECT_NAME}
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT_NAME})