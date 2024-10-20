cmake_minimum_required(VERSION 3.0)
project(quick_sort)

set(CMAKE_CXX_STANDARD 11)
add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})