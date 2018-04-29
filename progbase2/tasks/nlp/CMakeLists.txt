cmake_minimum_required(VERSION 3.6)
project(nlp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.c listP.c listP.h save.c save.h)
add_executable(nlp ${SOURCE_FILES})