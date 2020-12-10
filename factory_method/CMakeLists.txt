cmake_minimum_required(VERSION 3.5.1)
project(HelloWorld)

add_compile_options(-std=c++11)
find_package(Boost REQUIRED COMPONENTS system)


# set(CMAKE_CXX_STANDARD 11)
# find_package(Boost REQUIRED COMPONENTS system)
# message("test")
# if(NOT Boost_FOUND)
#     message("Not found Boost")
# endif()

include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")

include_directories(./include)
aux_source_directory(. SRC_LIST)
aux_source_directory(src SRC_LIST)

add_executable(HelloWorld ${SRC_LIST})
target_link_libraries(HelloWorld ${Boost_LIBRARIES})
