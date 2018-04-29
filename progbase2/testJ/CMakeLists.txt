cmake_minimum_required(VERSION 3.6)
project(testJ)
set(HEADER jansson.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(testJ ${SOURCE_FILES})
target_link_libraries(testJ jansson)