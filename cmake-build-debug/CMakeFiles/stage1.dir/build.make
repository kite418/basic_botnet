# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macos/CLionProjects/basic_botnet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macos/CLionProjects/basic_botnet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stage1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/stage1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stage1.dir/flags.make

CMakeFiles/stage1.dir/server.cpp.o: CMakeFiles/stage1.dir/flags.make
CMakeFiles/stage1.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macos/CLionProjects/basic_botnet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stage1.dir/server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stage1.dir/server.cpp.o -c /Users/macos/CLionProjects/basic_botnet/server.cpp

CMakeFiles/stage1.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stage1.dir/server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macos/CLionProjects/basic_botnet/server.cpp > CMakeFiles/stage1.dir/server.cpp.i

CMakeFiles/stage1.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stage1.dir/server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macos/CLionProjects/basic_botnet/server.cpp -o CMakeFiles/stage1.dir/server.cpp.s

# Object files for target stage1
stage1_OBJECTS = \
"CMakeFiles/stage1.dir/server.cpp.o"

# External object files for target stage1
stage1_EXTERNAL_OBJECTS =

stage1: CMakeFiles/stage1.dir/server.cpp.o
stage1: CMakeFiles/stage1.dir/build.make
stage1: CMakeFiles/stage1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/macos/CLionProjects/basic_botnet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stage1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stage1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stage1.dir/build: stage1
.PHONY : CMakeFiles/stage1.dir/build

CMakeFiles/stage1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stage1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stage1.dir/clean

CMakeFiles/stage1.dir/depend:
	cd /Users/macos/CLionProjects/basic_botnet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macos/CLionProjects/basic_botnet /Users/macos/CLionProjects/basic_botnet /Users/macos/CLionProjects/basic_botnet/cmake-build-debug /Users/macos/CLionProjects/basic_botnet/cmake-build-debug /Users/macos/CLionProjects/basic_botnet/cmake-build-debug/CMakeFiles/stage1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stage1.dir/depend

