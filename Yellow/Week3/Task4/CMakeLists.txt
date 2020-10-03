cmake_minimum_required(VERSION 3.16)
project(Task4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task4 main.cpp query.h query.cpp responses.h responses.cpp bus_manager.h bus_manager.cpp)