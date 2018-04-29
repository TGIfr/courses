cmake_minimum_required(VERSION 2.8.7)

include_directories(include)





project (client)
add_executable(${CMAKE_PROJECT_NAME} ${LIB_SOURCES} client.cpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99)
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase jansson Qt5::Core Qt5::Widgets)




