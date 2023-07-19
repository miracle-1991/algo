cmake_minimum_required(VERSION 3.0)
project(linearList)

# 设置C++标准为C++11
set(CMAKE_CXX_STANDARD 11)

# 添加编译目标
add_executable(main main.cpp)

# 添加头文件的搜索路径，这样就可以在源代码中使用 #include "linearlist.h" 和 #include "arraylist.h"
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
