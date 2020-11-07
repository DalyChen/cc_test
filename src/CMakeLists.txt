cmake_minimum_required(VERSION 3.5.1)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

include_directories(function)

aux_source_directory(. SRC_LIST)
aux_source_directory(function SRC_LIST)

add_executable(HelloWorld.out ${SRC_LIST})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)

INSTALL(TARGETS HelloWorld.out
    DESTINATION my_test
)