cmake_minimum_required(VERSION 3.8)
project(6xGraph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graph.h graph.cpp graphutil.h graphutil.cpp)
add_executable(6xGraph ${SOURCE_FILES})