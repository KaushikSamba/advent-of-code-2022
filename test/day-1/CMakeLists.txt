add_executable(day-1-test test.cpp)

target_link_libraries(day-1-test PRIVATE day-1 gtest_main)
target_compile_definitions(day-1-test PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

gtest_discover_tests(day-1-test)
