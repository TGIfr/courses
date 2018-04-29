cmake_minimum_required(VERSION 3.6)
project(recursion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(HEADER progbase.h)
set(SOURCE_FILES main.c)
add_executable(recursion ${SOURCE_FILES})
target_link_libraries(recursion progbase)