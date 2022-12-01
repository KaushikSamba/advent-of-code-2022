add_executable(file-utils-test
    test.cpp
)
target_link_libraries(file-utils-test PRIVATE
    file-utils
    gtest_main
)

gtest_discover_tests(file-utils-test)
