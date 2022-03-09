cmake_minimum_required(VERSION 3.19)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)