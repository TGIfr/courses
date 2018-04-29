cmake_minimum_required(VERSION 3.6)
project(udp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  src/IpAddressClass.cpp include/IpAddressClass.h
        src/NetMessageClass.cpp include/NetMessageClass.h src/UdpClientClass.cpp
        include/UdpClientClass.h src/TcpListenerClass.cpp include/TcpListenerClass.h
        src/TcpClientClass.cpp include/TcpClientClass.h )
add_executable(Server Server.cpp ${SOURCE_FILES})
target_link_libraries(Server progbase)

add_executable(Client Client.cpp ${SOURCE_FILES} )
target_link_libraries(Client progbase)