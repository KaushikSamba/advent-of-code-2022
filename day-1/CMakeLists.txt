# Create solution library
add_library(day-1
    day-1-calorie-counting.cpp
)

target_link_libraries(day-1 PUBLIC file-utils)

target_include_directories(day-1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create solution executable.
add_executable(day-1-solution main.cpp)
target_compile_definitions(day-1-solution PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(day-1-solution PRIVATE day-1)