cmake_minimum_required(VERSION 3.5.1)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

# set(SRC_LIST main.cpp display.cpp)
aux_source_directory(. SRC_LIST)

add_executable(HelloWorld.out ${SRC_LIST})