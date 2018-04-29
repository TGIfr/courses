cmake_minimum_required(VERSION 3.6)
project(threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/graphics.cpp include/graphics.h)
add_executable(threads ${SOURCE_FILES})
target_link_libraries(threads pthread progbase-cpp progbase )