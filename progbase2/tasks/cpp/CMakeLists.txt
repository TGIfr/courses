cmake_minimum_required(VERSION 3.6)
project(cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Circle.cpp Circle.h)
add_executable(cpp ${SOURCE_FILES})