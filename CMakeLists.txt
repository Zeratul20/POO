cmake_minimum_required(VERSION 3.19)
project(oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(oop main.cpp Student.cpp Student.h Profesor.cpp Profesor.h Secretariat.cpp Secretariat.h Facultate.cpp Facultate.h Exceptie.cpp Exceptie.h)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)