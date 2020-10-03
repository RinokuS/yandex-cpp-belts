cmake_minimum_required(VERSION 3.17)
project(PartA)

set(CMAKE_CXX_STANDARD 20)

add_executable(PartA main.cpp transport_guide_manager.h transport_guide_manager.cpp routes_database.h routes_database.cpp stops_database.h stops_database.cpp transport_guide_tests.h transport_guide_tests.cpp bus_stops_tests.h bus_stops_tests.cpp routes_database_tests.h routes_database_tests.cpp transport_guide_manager_tests.h transport_guide_manager_tests.cpp UnitTestsFramework.h UnitTestsFramework.cpp)