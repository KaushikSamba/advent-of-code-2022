# Create solution library
add_library(day-4 day-4-camp-cleanup.cpp)
target_link_libraries(day-4 PUBLIC file-utils)
target_include_directories(day-4 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create solution executable.
add_executable(day-4-solution main.cpp)
target_compile_definitions(day-4-solution PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(day-4-solution PRIVATE day-4)