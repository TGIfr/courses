cmake_minimum_required(VERSION 3.6)
project(checkTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(HEADER check.h)


set(SOURCE_FILES main.c)
add_executable(checkTest ${SOURCE_FILES})

target_link_libraries(checkTest check )