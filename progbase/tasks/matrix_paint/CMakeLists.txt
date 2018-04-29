cmake_minimum_required(VERSION 3.6)
project(matrix_paint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors")

set(SOURCE_FILES main.c)
set(HEADER progbase.h)
add_executable(matrix_paint ${SOURCE_FILES})
target_link_libraries(matrix_paint progbase)