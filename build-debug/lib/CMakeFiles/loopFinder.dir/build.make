# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "/Users/songl/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/songl/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/songl/OneDrive/TLE-analyzer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/songl/OneDrive/TLE-analyzer/build-debug

# Include any dependencies generated for this target.
include lib/CMakeFiles/loopFinder.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/loopFinder.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/loopFinder.dir/flags.make

lib/CMakeFiles/loopFinder.dir/loopFinder.cpp.o: lib/CMakeFiles/loopFinder.dir/flags.make
lib/CMakeFiles/loopFinder.dir/loopFinder.cpp.o: ../lib/loopFinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/songl/OneDrive/TLE-analyzer/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/loopFinder.dir/loopFinder.cpp.o"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/loopFinder.dir/loopFinder.cpp.o -c /Users/songl/OneDrive/TLE-analyzer/lib/loopFinder.cpp

lib/CMakeFiles/loopFinder.dir/loopFinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loopFinder.dir/loopFinder.cpp.i"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/songl/OneDrive/TLE-analyzer/lib/loopFinder.cpp > CMakeFiles/loopFinder.dir/loopFinder.cpp.i

lib/CMakeFiles/loopFinder.dir/loopFinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loopFinder.dir/loopFinder.cpp.s"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/songl/OneDrive/TLE-analyzer/lib/loopFinder.cpp -o CMakeFiles/loopFinder.dir/loopFinder.cpp.s

# Object files for target loopFinder
loopFinder_OBJECTS = \
"CMakeFiles/loopFinder.dir/loopFinder.cpp.o"

# External object files for target loopFinder
loopFinder_EXTERNAL_OBJECTS =

lib/libloopFinder.dylib: lib/CMakeFiles/loopFinder.dir/loopFinder.cpp.o
lib/libloopFinder.dylib: lib/CMakeFiles/loopFinder.dir/build.make
lib/libloopFinder.dylib: lib/libutil.dylib
lib/libloopFinder.dylib: lib/CMakeFiles/loopFinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/songl/OneDrive/TLE-analyzer/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libloopFinder.dylib"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/loopFinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/loopFinder.dir/build: lib/libloopFinder.dylib

.PHONY : lib/CMakeFiles/loopFinder.dir/build

lib/CMakeFiles/loopFinder.dir/clean:
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/loopFinder.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/loopFinder.dir/clean

lib/CMakeFiles/loopFinder.dir/depend:
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/songl/OneDrive/TLE-analyzer /Users/songl/OneDrive/TLE-analyzer/lib /Users/songl/OneDrive/TLE-analyzer/build-debug /Users/songl/OneDrive/TLE-analyzer/build-debug/lib /Users/songl/OneDrive/TLE-analyzer/build-debug/lib/CMakeFiles/loopFinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/loopFinder.dir/depend

