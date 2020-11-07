cmake_minimum_required(VERSION 3.5.1)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

set(SRC_LIST main.cpp)

add_executable(HelloWorld ${SRC_LIST})