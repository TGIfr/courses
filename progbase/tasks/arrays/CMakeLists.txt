cmake_minimum_required(VERSION 3.6)
project(arrays)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89 -Werror -pedantic-errors")

set(SOURCE_FILES
    main.c
        )
set(HEADER
        progbase.h
        )

add_executable(arrays ${SOURCE_FILES})

target_link_libraries(arrays progbase)
