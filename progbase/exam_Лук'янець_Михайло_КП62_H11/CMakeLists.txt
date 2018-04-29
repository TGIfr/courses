cmake_minimum_required(VERSION 3.6)
project(exam____62_H11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(HEADER progbase.h math.h)

set(SOURCE_FILES main.c)
add_executable(exam____62_H11 ${SOURCE_FILES})

target_link_libraries(exam____62_H11 progbase math)