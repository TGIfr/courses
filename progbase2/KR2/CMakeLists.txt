cmake_minimum_required(VERSION 3.6)
project(remote)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES   include/Remote.h include/json.hpp src/Sender.cpp include/Sender.h src/Composition.cpp include/Composition.h )

# compiles code files from ./src folder
file(GLOB SOURCES "src/*.c" "src/*.cpp")

# to build static lib
add_library(remotelib STATIC ${SOURCES})

# install library headers
install(
        DIRECTORY include/     DESTINATION /usr/local/include
        FILES_MATCHING PATTERN "*.h"
)

#Set the location for library installation -- i.e., /usr/local/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS remotelib DESTINATION /usr/local/lib)

add_executable(server server.cpp )
target_link_libraries(server remotelib progbase-cpp progbase)

add_executable(client client.cpp src/Remote.cpp )
target_link_libraries(client remotelib progbase-cpp progbase)