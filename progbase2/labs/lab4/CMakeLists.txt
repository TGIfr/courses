cmake_minimum_required(VERSION 3.6)
project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(HEADER progbase.h check.h)

set(SOURCE_FILES main.c dino.c saves.c totest.c interface.c list.c list.h)


add_executable(lab4 ${SOURCE_FILES})
target_link_libraries(lab4 progbase check)