# Create library for users
add_library(file-utils
    filehandler.cpp
    input_parser.cpp
)

target_include_directories(file-utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
