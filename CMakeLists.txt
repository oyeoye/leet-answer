project(Qt_test1)
cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "-std=c++11") # Add c++11 functionality
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})


