# Create library for users
add_library(file-utils
    filehandler.cpp
    input_parser.cpp
)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
target_include_directories(file-utils INTERFACE ${PARENT_DIR})
