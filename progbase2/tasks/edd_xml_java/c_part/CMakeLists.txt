cmake_minimum_required(VERSION 2.8.9)
project (c_part)

# add_executable(proj main.c)

# adds ./include to compiler include directories
include_directories(include)

# uncomment to use libxml2 XML headers
include_directories(/usr/include/libxml2)

# compiles code files from ./src folder
file(GLOB SOURCES "src/*.c")

# to build static lib
# add_library(mycsv STATIC ${SOURCES})
add_executable(${CMAKE_PROJECT_NAME} "main.c" ${SOURCES} src/events.c include/events.h src/list.c include/list.h src/dataManagement.c include/dataManagement.h)
target_link_libraries(${CMAKE_PROJECT_NAME} progbase xml2 )
SET(CMAKE_C_FLAGS "-std=c11 -g -fms-extensions")