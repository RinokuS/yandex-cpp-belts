cmake_minimum_required(VERSION 3.16)
project(BossFight)

set(CMAKE_CXX_STANDARD 20)

add_executable(BossFight main.cpp parse.cpp search_server.cpp)