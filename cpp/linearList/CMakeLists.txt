cmake_minimum_required(VERSION 3.25)
project(arrayListTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(arrayListTest main.cpp arrayList.cpp)

target_include_directories(arrayListTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
