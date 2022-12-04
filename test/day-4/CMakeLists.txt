add_executable(day-4-test test.cpp)

target_link_libraries(day-4-test PRIVATE day-4 gtest_main)
target_compile_definitions(day-4-test PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

gtest_discover_tests(day-4-test)
