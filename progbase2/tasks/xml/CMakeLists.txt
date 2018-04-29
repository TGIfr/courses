cmake_minimum_required(VERSION 3.6)
project(xml)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(HEADER xml2.h check.h)

set(SOURCE_FILES tests.c list.c XmlLoader.c XmlLoader.h)
add_executable(xml ${SOURCE_FILES})
target_link_libraries(xml xml2 check)