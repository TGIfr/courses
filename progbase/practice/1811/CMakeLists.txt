cmake_minimum_required(VERSION 3.6)
project(1811)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(HEADER progbase.h)

set(SOURCE_FILES main.c)
add_executable(1811 ${SOURCE_FILES})
target_link_libraries(1811 progbase)