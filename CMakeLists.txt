cmake_minimum_required(VERSION 3.22)

# Project settings
project(
        CMakeAppTemplate
        VERSION 1.0.0
        DESCRIPTION ""
        LANGUAGES CXX C
)

# Set project options
# Setup a test project with gtest dependencies
option(BUILD_TESTS "Build the tests" ON)
#set(GFXLIB_BACKEND "blarg")

# CMake scripts
include(cmake/project_defaults.cmake) # Default project settings
include(cmake/project_dependencies.cmake) # Project dependencies

# App framework and app stub
add_subdirectory(app)

# Optionally add tests if they are requested
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()