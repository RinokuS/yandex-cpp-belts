# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rinokus/CLionProjects/Red/Week5/Task5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task5.dir/flags.make

CMakeFiles/Task5.dir/main.cpp.o: CMakeFiles/Task5.dir/flags.make
CMakeFiles/Task5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task5.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task5.dir/main.cpp.o -c /Users/rinokus/CLionProjects/Red/Week5/Task5/main.cpp

CMakeFiles/Task5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task5.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Red/Week5/Task5/main.cpp > CMakeFiles/Task5.dir/main.cpp.i

CMakeFiles/Task5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task5.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Red/Week5/Task5/main.cpp -o CMakeFiles/Task5.dir/main.cpp.s

CMakeFiles/Task5.dir/simple_vector_2.cpp.o: CMakeFiles/Task5.dir/flags.make
CMakeFiles/Task5.dir/simple_vector_2.cpp.o: ../simple_vector_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Task5.dir/simple_vector_2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task5.dir/simple_vector_2.cpp.o -c /Users/rinokus/CLionProjects/Red/Week5/Task5/simple_vector_2.cpp

CMakeFiles/Task5.dir/simple_vector_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task5.dir/simple_vector_2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Red/Week5/Task5/simple_vector_2.cpp > CMakeFiles/Task5.dir/simple_vector_2.cpp.i

CMakeFiles/Task5.dir/simple_vector_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task5.dir/simple_vector_2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Red/Week5/Task5/simple_vector_2.cpp -o CMakeFiles/Task5.dir/simple_vector_2.cpp.s

# Object files for target Task5
Task5_OBJECTS = \
"CMakeFiles/Task5.dir/main.cpp.o" \
"CMakeFiles/Task5.dir/simple_vector_2.cpp.o"

# External object files for target Task5
Task5_EXTERNAL_OBJECTS =

Task5: CMakeFiles/Task5.dir/main.cpp.o
Task5: CMakeFiles/Task5.dir/simple_vector_2.cpp.o
Task5: CMakeFiles/Task5.dir/build.make
Task5: CMakeFiles/Task5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Task5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task5.dir/build: Task5

.PHONY : CMakeFiles/Task5.dir/build

CMakeFiles/Task5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task5.dir/clean

CMakeFiles/Task5.dir/depend:
	cd /Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rinokus/CLionProjects/Red/Week5/Task5 /Users/rinokus/CLionProjects/Red/Week5/Task5 /Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug /Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug /Users/rinokus/CLionProjects/Red/Week5/Task5/cmake-build-debug/CMakeFiles/Task5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task5.dir/depend

