cmake_minimum_required(VERSION 3.19)
project(OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP main.cpp Haina.cpp Haina.h Pantof.cpp Pantof.h Sifonier.cpp Sifonier.h)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)