add_executable(day-2-test test.cpp)

target_link_libraries(day-2-test PRIVATE day-2 gtest_main)
target_compile_definitions(day-2-test PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

gtest_discover_tests(day-2-test)
