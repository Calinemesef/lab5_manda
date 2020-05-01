cmake_minimum_required(VERSION 3.15)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp Film.h Film.cpp admin.h admin.cpp user.h user.cpp Controller.h Controller.cpp UI.cpp UI.h Tests.h Tests.cpp)