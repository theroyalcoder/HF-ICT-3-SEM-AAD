cmake_minimum_required(VERSION 3.8)
project(graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graph.cpp graph.h graphutil.cpp)
add_executable(graph ${SOURCE_FILES})