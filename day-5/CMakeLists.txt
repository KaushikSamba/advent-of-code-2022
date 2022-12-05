# Create solution library
add_library(day-5 day-5.cpp)
target_link_libraries(day-5 PUBLIC file-utils)
target_include_directories(day-5 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create solution executable.
add_executable(day-5-solution main.cpp)
target_compile_definitions(day-5-solution PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(day-5-solution PRIVATE day-5)