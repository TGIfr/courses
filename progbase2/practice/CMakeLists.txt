cmake_minimum_required(VERSION 3.6)
project(practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.cpp src/csv.c include/csv.h)
add_executable(practice ${SOURCE_FILES})

# add_executable(proj main.c)

# adds ./include to compiler include directories
include_directories(include)

# uncomment to use libxml2 XML headers
# include_directories(/usr/include/libxml2)

# compiles code files from ./src folder
file(GLOB SOURCES "src/*.c")

# to build static lib
add_library(practice STATIC ${SOURCES})

# install library headers
install(
        DIRECTORY include/     DESTINATION /usr/local/include
        FILES_MATCHING PATTERN "*.h"
)

#Set the location for library installation -- i.e., /usr/local/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS mycsv DESTINATION /usr/local/lib)

# uncomment this to link libxml2 XML library
# target_link_libraries(proj libxml2.so)

# uncomment this to link jansson JSON library
# target_link_libraries(proj libjansson.so)