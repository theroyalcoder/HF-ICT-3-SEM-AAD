cmake_minimum_required(VERSION 3.8)
project(Collection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp array.h LinkedList.h Collection.h Node.h)
add_executable(Collection ${SOURCE_FILES})