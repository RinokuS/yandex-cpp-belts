# CMake generated Testfile for 
# Source directory: /Users/rinokus/CLionProjects/Black/Week3/partJ
# Build directory: /Users/rinokus/CLionProjects/Black/Week3/partJ/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(transport_catalog_tests "/Users/rinokus/CLionProjects/Black/Week3/partJ/cmake-build-debug/transport_catalog/tests/transport_catalog_tests")
set_tests_properties(transport_catalog_tests PROPERTIES  _BACKTRACE_TRIPLES "/Users/rinokus/CLionProjects/Black/Week3/partJ/CMakeLists.txt;86;add_test;/Users/rinokus/CLionProjects/Black/Week3/partJ/CMakeLists.txt;0;")
add_test(transport "transport")
set_tests_properties(transport PROPERTIES  _BACKTRACE_TRIPLES "/Users/rinokus/CLionProjects/Black/Week3/partJ/CMakeLists.txt;88;add_test;/Users/rinokus/CLionProjects/Black/Week3/partJ/CMakeLists.txt;0;")
subdirs("json")
subdirs("transport_catalog")
subdirs("yellow_pages")
