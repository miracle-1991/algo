cmake_minimum_required(VERSION 3.25)
project(algo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(algo
        linearList.cpp
        linearList.h
        main.cpp)
