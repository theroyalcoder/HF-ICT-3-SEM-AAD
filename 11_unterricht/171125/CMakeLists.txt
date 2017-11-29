cmake_minimum_required(VERSION 3.8)
project(171125)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp graphutil.cpp graphutil.h graph.cpp graph.h graphgen.h graphgen.cpp)
add_executable(171125 ${SOURCE_FILES})