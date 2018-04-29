cmake_minimum_required(VERSION 3.6)
project(extra_console_game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(HEADER progbase.h)

set(SOURCE_FILES main.c settings.c settings.h interface.c interface.h tetris.c tetris.h save.c save.h snake.c snake.h tetrisnake.h tetrisnake.c)
add_executable(extra_console_game ${SOURCE_FILES})
target_link_libraries(extra_console_game progbase)