cmake_minimum_required(VERSION 3.26)
project(SmartSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(SmartSort main.cpp
        bubble_sort.cpp
        io_array.cpp
)
