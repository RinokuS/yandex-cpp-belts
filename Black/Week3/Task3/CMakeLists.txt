cmake_minimum_required(VERSION 3.17)
project(Task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Task3 mython.cpp comparators.h comparators.cpp object_holder.h object_holder.cpp object.h object.cpp parse.h parse.cpp lexer.h lexer.cpp statement.h statement.cpp statement_test.cpp parse_test.cpp object_test.cpp object_holder_test.cpp)