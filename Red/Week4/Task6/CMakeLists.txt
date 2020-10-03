cmake_minimum_required(VERSION 3.16)
project(Task6)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task6 main.cpp http_request.h stats.h stats.cpp)