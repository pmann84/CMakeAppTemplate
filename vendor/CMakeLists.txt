# Tests: setup a test project with gtest dependencies
if(BUILD_TESTS)
    add_subdirectory(googletest)
endif()

add_subdirectory(gfxlib)