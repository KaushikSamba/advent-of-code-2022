add_executable(day-5-test test.cpp)

target_link_libraries(day-5-test PRIVATE day-5 gtest_main)
target_compile_definitions(day-5-test PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

gtest_discover_tests(day-5-test)
