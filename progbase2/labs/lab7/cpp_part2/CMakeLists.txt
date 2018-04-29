cmake_minimum_required(VERSION 3.6)
project(cpp_part2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cpp_part2 ${SOURCE_FILES})
target_link_libraries(cpp_part2 curlpp curl )