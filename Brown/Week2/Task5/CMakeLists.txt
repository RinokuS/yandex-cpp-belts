cmake_minimum_required(VERSION 3.16)
project(Task5)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task5 main.cpp stats_aggregator.h stats_aggregator.cpp stats_aggregator_test.cpp)