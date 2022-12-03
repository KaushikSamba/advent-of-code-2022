# Create solution library
add_library(day-3 day-3-rucksack-reorganization.cpp)
target_link_libraries(day-3 PUBLIC file-utils)
target_include_directories(day-3 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create solution executable.
add_executable(day-3-solution main.cpp)
target_compile_definitions(day-3-solution PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(day-3-solution PRIVATE day-3)