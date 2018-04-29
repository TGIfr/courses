cmake_minimum_required(VERSION 3.6)
project(task1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(task1 ${SOURCE_FILES})
target_link_libraries(task1 progbase-cpp progbase curl)