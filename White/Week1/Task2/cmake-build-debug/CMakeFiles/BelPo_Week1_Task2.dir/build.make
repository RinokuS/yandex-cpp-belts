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
CMAKE_SOURCE_DIR = /Users/rinokus/CLionProjects/BelPo_Week1_Task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BelPo_Week1_Task2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BelPo_Week1_Task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BelPo_Week1_Task2.dir/flags.make

CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.o: CMakeFiles/BelPo_Week1_Task2.dir/flags.make
CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.o -c /Users/rinokus/CLionProjects/BelPo_Week1_Task2/main.cpp

CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/BelPo_Week1_Task2/main.cpp > CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.i

CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/BelPo_Week1_Task2/main.cpp -o CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.s

# Object files for target BelPo_Week1_Task2
BelPo_Week1_Task2_OBJECTS = \
"CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.o"

# External object files for target BelPo_Week1_Task2
BelPo_Week1_Task2_EXTERNAL_OBJECTS =

BelPo_Week1_Task2: CMakeFiles/BelPo_Week1_Task2.dir/main.cpp.o
BelPo_Week1_Task2: CMakeFiles/BelPo_Week1_Task2.dir/build.make
BelPo_Week1_Task2: CMakeFiles/BelPo_Week1_Task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BelPo_Week1_Task2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BelPo_Week1_Task2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BelPo_Week1_Task2.dir/build: BelPo_Week1_Task2

.PHONY : CMakeFiles/BelPo_Week1_Task2.dir/build

CMakeFiles/BelPo_Week1_Task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BelPo_Week1_Task2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BelPo_Week1_Task2.dir/clean

CMakeFiles/BelPo_Week1_Task2.dir/depend:
	cd /Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rinokus/CLionProjects/BelPo_Week1_Task2 /Users/rinokus/CLionProjects/BelPo_Week1_Task2 /Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug /Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug /Users/rinokus/CLionProjects/BelPo_Week1_Task2/cmake-build-debug/CMakeFiles/BelPo_Week1_Task2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BelPo_Week1_Task2.dir/depend

