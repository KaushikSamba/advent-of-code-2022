# Create solution library
add_library(day-2 day-2-rock-paper-scissors.cpp)

target_link_libraries(day-2 PUBLIC file-utils)

target_include_directories(day-2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create solution executable.
add_executable(day-2-solution main.cpp)
target_compile_definitions(day-2-solution PRIVATE -DCURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(day-2-solution PRIVATE day-2)