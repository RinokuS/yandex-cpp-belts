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
CMAKE_SOURCE_DIR = /Users/rinokus/CLionProjects/Black/Week2/Task4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task4.dir/flags.make

address.pb.h: ../protos/address.proto
address.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cpp protocol buffer compiler on protos/address.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/address.proto

address.pb.cc: address.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate address.pb.cc

company.pb.h: ../protos/company.proto
company.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Running cpp protocol buffer compiler on protos/company.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/company.proto

company.pb.cc: company.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate company.pb.cc

name.pb.h: ../protos/name.proto
name.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Running cpp protocol buffer compiler on protos/name.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/name.proto

name.pb.cc: name.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate name.pb.cc

phone.pb.h: ../protos/phone.proto
phone.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Running cpp protocol buffer compiler on protos/phone.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/phone.proto

phone.pb.cc: phone.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate phone.pb.cc

provider.pb.h: ../protos/provider.proto
provider.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Running cpp protocol buffer compiler on protos/provider.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/provider.proto

provider.pb.cc: provider.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate provider.pb.cc

signal.pb.h: ../protos/signal.proto
signal.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Running cpp protocol buffer compiler on protos/signal.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/signal.proto

signal.pb.cc: signal.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate signal.pb.cc

url.pb.h: ../protos/url.proto
url.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Running cpp protocol buffer compiler on protos/url.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/url.proto

url.pb.cc: url.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate url.pb.cc

working_time.pb.h: ../protos/working_time.proto
working_time.pb.h: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Running cpp protocol buffer compiler on protos/working_time.proto"
	/usr/local/bin/protoc --cpp_out /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug -I /Users/rinokus/CLionProjects/Black/Week2/Task4/protos /Users/rinokus/CLionProjects/Black/Week2/Task4/protos/working_time.proto

working_time.pb.cc: working_time.pb.h
	@$(CMAKE_COMMAND) -E touch_nocreate working_time.pb.cc

CMakeFiles/Task4.dir/address.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/address.pb.cc.o: address.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Task4.dir/address.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/address.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/address.pb.cc

CMakeFiles/Task4.dir/address.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/address.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/address.pb.cc > CMakeFiles/Task4.dir/address.pb.cc.i

CMakeFiles/Task4.dir/address.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/address.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/address.pb.cc -o CMakeFiles/Task4.dir/address.pb.cc.s

CMakeFiles/Task4.dir/company.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/company.pb.cc.o: company.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Task4.dir/company.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/company.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/company.pb.cc

CMakeFiles/Task4.dir/company.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/company.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/company.pb.cc > CMakeFiles/Task4.dir/company.pb.cc.i

CMakeFiles/Task4.dir/company.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/company.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/company.pb.cc -o CMakeFiles/Task4.dir/company.pb.cc.s

CMakeFiles/Task4.dir/name.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/name.pb.cc.o: name.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Task4.dir/name.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/name.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/name.pb.cc

CMakeFiles/Task4.dir/name.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/name.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/name.pb.cc > CMakeFiles/Task4.dir/name.pb.cc.i

CMakeFiles/Task4.dir/name.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/name.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/name.pb.cc -o CMakeFiles/Task4.dir/name.pb.cc.s

CMakeFiles/Task4.dir/phone.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/phone.pb.cc.o: phone.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Task4.dir/phone.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/phone.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/phone.pb.cc

CMakeFiles/Task4.dir/phone.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/phone.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/phone.pb.cc > CMakeFiles/Task4.dir/phone.pb.cc.i

CMakeFiles/Task4.dir/phone.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/phone.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/phone.pb.cc -o CMakeFiles/Task4.dir/phone.pb.cc.s

CMakeFiles/Task4.dir/provider.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/provider.pb.cc.o: provider.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Task4.dir/provider.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/provider.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/provider.pb.cc

CMakeFiles/Task4.dir/provider.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/provider.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/provider.pb.cc > CMakeFiles/Task4.dir/provider.pb.cc.i

CMakeFiles/Task4.dir/provider.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/provider.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/provider.pb.cc -o CMakeFiles/Task4.dir/provider.pb.cc.s

CMakeFiles/Task4.dir/signal.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/signal.pb.cc.o: signal.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Task4.dir/signal.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/signal.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/signal.pb.cc

CMakeFiles/Task4.dir/signal.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/signal.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/signal.pb.cc > CMakeFiles/Task4.dir/signal.pb.cc.i

CMakeFiles/Task4.dir/signal.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/signal.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/signal.pb.cc -o CMakeFiles/Task4.dir/signal.pb.cc.s

CMakeFiles/Task4.dir/url.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/url.pb.cc.o: url.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Task4.dir/url.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/url.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/url.pb.cc

CMakeFiles/Task4.dir/url.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/url.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/url.pb.cc > CMakeFiles/Task4.dir/url.pb.cc.i

CMakeFiles/Task4.dir/url.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/url.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/url.pb.cc -o CMakeFiles/Task4.dir/url.pb.cc.s

CMakeFiles/Task4.dir/working_time.pb.cc.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/working_time.pb.cc.o: working_time.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Task4.dir/working_time.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/working_time.pb.cc.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/working_time.pb.cc

CMakeFiles/Task4.dir/working_time.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/working_time.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/working_time.pb.cc > CMakeFiles/Task4.dir/working_time.pb.cc.i

CMakeFiles/Task4.dir/working_time.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/working_time.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/working_time.pb.cc -o CMakeFiles/Task4.dir/working_time.pb.cc.s

CMakeFiles/Task4.dir/main.cpp.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Task4.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/main.cpp.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/main.cpp

CMakeFiles/Task4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/main.cpp > CMakeFiles/Task4.dir/main.cpp.i

CMakeFiles/Task4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/main.cpp -o CMakeFiles/Task4.dir/main.cpp.s

CMakeFiles/Task4.dir/merge.cpp.o: CMakeFiles/Task4.dir/flags.make
CMakeFiles/Task4.dir/merge.cpp.o: ../merge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/Task4.dir/merge.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task4.dir/merge.cpp.o -c /Users/rinokus/CLionProjects/Black/Week2/Task4/merge.cpp

CMakeFiles/Task4.dir/merge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task4.dir/merge.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/CLionProjects/Black/Week2/Task4/merge.cpp > CMakeFiles/Task4.dir/merge.cpp.i

CMakeFiles/Task4.dir/merge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task4.dir/merge.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/CLionProjects/Black/Week2/Task4/merge.cpp -o CMakeFiles/Task4.dir/merge.cpp.s

# Object files for target Task4
Task4_OBJECTS = \
"CMakeFiles/Task4.dir/address.pb.cc.o" \
"CMakeFiles/Task4.dir/company.pb.cc.o" \
"CMakeFiles/Task4.dir/name.pb.cc.o" \
"CMakeFiles/Task4.dir/phone.pb.cc.o" \
"CMakeFiles/Task4.dir/provider.pb.cc.o" \
"CMakeFiles/Task4.dir/signal.pb.cc.o" \
"CMakeFiles/Task4.dir/url.pb.cc.o" \
"CMakeFiles/Task4.dir/working_time.pb.cc.o" \
"CMakeFiles/Task4.dir/main.cpp.o" \
"CMakeFiles/Task4.dir/merge.cpp.o"

# External object files for target Task4
Task4_EXTERNAL_OBJECTS =

Task4: CMakeFiles/Task4.dir/address.pb.cc.o
Task4: CMakeFiles/Task4.dir/company.pb.cc.o
Task4: CMakeFiles/Task4.dir/name.pb.cc.o
Task4: CMakeFiles/Task4.dir/phone.pb.cc.o
Task4: CMakeFiles/Task4.dir/provider.pb.cc.o
Task4: CMakeFiles/Task4.dir/signal.pb.cc.o
Task4: CMakeFiles/Task4.dir/url.pb.cc.o
Task4: CMakeFiles/Task4.dir/working_time.pb.cc.o
Task4: CMakeFiles/Task4.dir/main.cpp.o
Task4: CMakeFiles/Task4.dir/merge.cpp.o
Task4: CMakeFiles/Task4.dir/build.make
Task4: /usr/local/lib/libprotobuf.dylib
Task4: CMakeFiles/Task4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable Task4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task4.dir/build: Task4

.PHONY : CMakeFiles/Task4.dir/build

CMakeFiles/Task4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task4.dir/clean

CMakeFiles/Task4.dir/depend: address.pb.h
CMakeFiles/Task4.dir/depend: address.pb.cc
CMakeFiles/Task4.dir/depend: company.pb.h
CMakeFiles/Task4.dir/depend: company.pb.cc
CMakeFiles/Task4.dir/depend: name.pb.h
CMakeFiles/Task4.dir/depend: name.pb.cc
CMakeFiles/Task4.dir/depend: phone.pb.h
CMakeFiles/Task4.dir/depend: phone.pb.cc
CMakeFiles/Task4.dir/depend: provider.pb.h
CMakeFiles/Task4.dir/depend: provider.pb.cc
CMakeFiles/Task4.dir/depend: signal.pb.h
CMakeFiles/Task4.dir/depend: signal.pb.cc
CMakeFiles/Task4.dir/depend: url.pb.h
CMakeFiles/Task4.dir/depend: url.pb.cc
CMakeFiles/Task4.dir/depend: working_time.pb.h
CMakeFiles/Task4.dir/depend: working_time.pb.cc
	cd /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rinokus/CLionProjects/Black/Week2/Task4 /Users/rinokus/CLionProjects/Black/Week2/Task4 /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug /Users/rinokus/CLionProjects/Black/Week2/Task4/cmake-build-debug/CMakeFiles/Task4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task4.dir/depend

