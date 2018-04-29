cmake_minimum_required(VERSION 3.6)
project(dyn_mem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(SOURCE_FILES main.c)
set(HEADER progbase.h)

add_executable(dyn_mem.out ${SOURCE_FILES})
target_link_libraries(dyn_mem.out progbase)