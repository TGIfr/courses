cmake_minimum_required(VERSION 3.6)
project(json)
set(HEADER jansson.h check.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tests.c list.c JsonLoader.c)
add_executable(json ${SOURCE_FILES})
target_link_libraries(json jansson check)