cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

project(advent-of-code-2022)

# Make Googletest available to the project
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850 # release v1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_subdirectory(utils)
add_subdirectory(test)
add_subdirectory(day-1)
add_subdirectory(day-2)
add_subdirectory(day-3)
add_subdirectory(day-4)
add_subdirectory(day-5)