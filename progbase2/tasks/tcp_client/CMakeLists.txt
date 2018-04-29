cmake_minimum_required(VERSION 3.6)
project(tcp_client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cpp_part/CMakeFiles/3.5.1/CompilerIdC/CMakeCCompilerId.c
    cpp_part/CMakeFiles/3.5.1/CompilerIdCXX/CMakeCXXCompilerId.cpp
    cpp_part/CMakeFiles/feature_tests.c
    cpp_part/CMakeFiles/feature_tests.cxx
    cpp_part/include/request.h
    cpp_part/src/request.c
    cpp_part/client.cpp
    cpp_part/handlers.c
    cpp_part/server.c
    main.cpp
    tcp_client.pro
    tcp_client.pro.user)

add_executable(tcp_client ${SOURCE_FILES})