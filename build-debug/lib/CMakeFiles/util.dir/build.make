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
include lib/CMakeFiles/util.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/util.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/util.dir/flags.make

lib/CMakeFiles/util.dir/util.cpp.o: lib/CMakeFiles/util.dir/flags.make
lib/CMakeFiles/util.dir/util.cpp.o: ../lib/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/songl/OneDrive/TLE-analyzer/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/util.dir/util.cpp.o"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/util.dir/util.cpp.o -c /Users/songl/OneDrive/TLE-analyzer/lib/util.cpp

lib/CMakeFiles/util.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/util.dir/util.cpp.i"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/songl/OneDrive/TLE-analyzer/lib/util.cpp > CMakeFiles/util.dir/util.cpp.i

lib/CMakeFiles/util.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/util.dir/util.cpp.s"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/songl/OneDrive/TLE-analyzer/lib/util.cpp -o CMakeFiles/util.dir/util.cpp.s

# Object files for target util
util_OBJECTS = \
"CMakeFiles/util.dir/util.cpp.o"

# External object files for target util
util_EXTERNAL_OBJECTS =

lib/libutil.dylib: lib/CMakeFiles/util.dir/util.cpp.o
lib/libutil.dylib: lib/CMakeFiles/util.dir/build.make
lib/libutil.dylib: lib/CMakeFiles/util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/songl/OneDrive/TLE-analyzer/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libutil.dylib"
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/util.dir/build: lib/libutil.dylib

.PHONY : lib/CMakeFiles/util.dir/build

lib/CMakeFiles/util.dir/clean:
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug/lib && $(CMAKE_COMMAND) -P CMakeFiles/util.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/util.dir/clean

lib/CMakeFiles/util.dir/depend:
	cd /Users/songl/OneDrive/TLE-analyzer/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/songl/OneDrive/TLE-analyzer /Users/songl/OneDrive/TLE-analyzer/lib /Users/songl/OneDrive/TLE-analyzer/build-debug /Users/songl/OneDrive/TLE-analyzer/build-debug/lib /Users/songl/OneDrive/TLE-analyzer/build-debug/lib/CMakeFiles/util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/util.dir/depend

