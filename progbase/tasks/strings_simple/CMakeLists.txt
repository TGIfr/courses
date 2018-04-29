cmake_minimum_required(VERSION 3.6)
project(strings_simple)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")
set(HEADER progbase.h)

set(SOURCE_FILES main.c)
add_executable(strings_simple ${SOURCE_FILES})
target_link_libraries(strings_simple progbase)