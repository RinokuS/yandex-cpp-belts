# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rinokus/CLionProjects/Black/Week1/PartI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PartI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PartI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PartI.dir/flags.make

CMakeFiles/PartI.dir/main.cpp.o: CMakeFiles/PartI.dir/flags.make
CMakeFiles/PartI.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PartI.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PartI.dir/main.cpp.o -c /Users/rinokus/CLionProjects/Black/Week1/PartI/main.cpp

CMakeFiles/PartI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PartI.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week1/PartI/main.cpp > CMakeFiles/PartI.dir/main.cpp.i

CMakeFiles/PartI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PartI.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week1/PartI/main.cpp -o CMakeFiles/PartI.dir/main.cpp.s

# Object files for target PartI
PartI_OBJECTS = \
"CMakeFiles/PartI.dir/main.cpp.o"

# External object files for target PartI
PartI_EXTERNAL_OBJECTS =

PartI: CMakeFiles/PartI.dir/main.cpp.o
PartI: CMakeFiles/PartI.dir/build.make
PartI: CMakeFiles/PartI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PartI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PartI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PartI.dir/build: PartI

.PHONY : CMakeFiles/PartI.dir/build

CMakeFiles/PartI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PartI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PartI.dir/clean

CMakeFiles/PartI.dir/depend:
	cd /Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rinokus/CLionProjects/Black/Week1/PartI /Users/rinokus/CLionProjects/Black/Week1/PartI /Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug /Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug /Users/rinokus/CLionProjects/Black/Week1/PartI/cmake-build-debug/CMakeFiles/PartI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PartI.dir/depend

