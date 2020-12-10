cmake_minimum_required(VERSION 3.5.1)
project(HelloWorld)

add_compile_options(-std=c++11)
find_package(Boost REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")

include_directories(./include)
include_directories(./include/pizza)

aux_source_directory(. SRC_LIST)
aux_source_directory(src SRC_LIST)
aux_source_directory(src/pizza SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
