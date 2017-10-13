cmake_minimum_required(VERSION 3.7)
project(Array_xy_comp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        array.cpp
        array.h
        main.cpp)

add_executable(Array_xy_comp ${SOURCE_FILES})