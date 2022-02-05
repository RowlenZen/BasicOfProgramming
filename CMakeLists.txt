cmake_minimum_required(VERSION 3.21)
project(BasicOfProgramming C)

set(CMAKE_C_STANDARD 11)

add_executable(BasicOfProgramming main.c)

add_subdirectory(libs)
target_link_libraries(BasicOfProgramming data_structures)
target_link_libraries(BasicOfProgramming algorithms)