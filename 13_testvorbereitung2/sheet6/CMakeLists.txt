cmake_minimum_required(VERSION 3.8)
project(sheet6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graphutil.cpp graphutil.h graph.cpp graph.h)
add_executable(sheet6 ${SOURCE_FILES})