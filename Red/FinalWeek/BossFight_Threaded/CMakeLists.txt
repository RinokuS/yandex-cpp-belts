cmake_minimum_required(VERSION 3.16)
project(BossFight_Threaded)

set(CMAKE_CXX_STANDARD 20)

add_executable(BossFight_Threaded main.cpp parse.cpp search_server.cpp synchronized.h synchronized.cpp)