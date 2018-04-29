cmake_minimum_required(VERSION 3.6)
project(kr_task2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(HEADER progbase.h)

set(SOURCE_FILES main.c)
add_executable(kr_task2 ${SOURCE_FILES})
target_link_libraries(kr_task2 progbase)