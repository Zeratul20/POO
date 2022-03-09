cmake_minimum_required(VERSION 3.19)
project(POO)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop main.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)