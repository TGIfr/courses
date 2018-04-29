cmake_minimum_required(VERSION 3.6)
project(lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -Werror -pedantic-errors")

set(SOURCE_FILES main.c)
set(HEADER
        progbase.h
        )

add_executable(lab2 ${SOURCE_FILES})

target_link_libraries(lab2 progbase)
