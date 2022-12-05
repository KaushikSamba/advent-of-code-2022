add_executable(day-N-test test.cpp)

target_link_libraries(day-N-test PRIVATE day-N gtest_main)
target_compile_definitions(day-N-test PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

gtest_discover_tests(day-N-test)
