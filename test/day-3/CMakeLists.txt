add_executable(day-3-test test.cpp)

target_link_libraries(day-3-test PRIVATE day-3 gtest_main)
target_compile_definitions(day-3-test PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

gtest_discover_tests(day-3-test)
