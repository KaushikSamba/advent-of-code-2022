# Create solution library
add_library(day-N day-N.cpp)
target_link_libraries(day-N PUBLIC file-utils)
target_include_directories(day-N INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create solution executable.
add_executable(day-N-solution main.cpp)
target_compile_definitions(day-N-solution PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(day-N-solution PRIVATE day-N)