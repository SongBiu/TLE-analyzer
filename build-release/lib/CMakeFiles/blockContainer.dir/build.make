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
CMAKE_BINARY_DIR = /Users/songl/OneDrive/TLE-analyzer/build-release

# Include any dependencies generated for this target.
include lib/CMakeFiles/blockContainer.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/blockContainer.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/blockContainer.dir/flags.make

lib/CMakeFiles/blockContainer.dir/blockManager.cpp.o: lib/CMakeFiles/blockContainer.dir/flags.make
lib/CMakeFiles/blockContainer.dir/blockManager.cpp.o: ../lib/blockManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/songl/OneDrive/TLE-analyzer/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/blockContainer.dir/blockManager.cpp.o"
	cd /Users/songl/OneDrive/TLE-analyzer/build-release/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blockContainer.dir/blockManager.cpp.o -c /Users/songl/OneDrive/TLE-analyzer/lib/blockManager.cpp

lib/CMakeFiles/blockContainer.dir/blockManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blockContainer.dir/blockManager.cpp.i"
	cd /Users/songl/OneDrive/TLE-analyzer/build-release/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/songl/OneDrive/TLE-analyzer/lib/blockManager.cpp > CMakeFiles/blockContainer.dir/blockManager.cpp.i

lib/CMakeFiles/blockContainer.dir/blockManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blockContainer.dir/blockManager.cpp.s"
	cd /Users/songl/OneDrive/TLE-analyzer/build-release/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/songl/OneDrive/TLE-analyzer/lib/blockManager.cpp -o CMakeFiles/blockContainer.dir/blockManager.cpp.s

# Object files for target blockContainer
blockContainer_OBJECTS = \
"CMakeFiles/blockContainer.dir/blockManager.cpp.o"

# External object files for target blockContainer
blockContainer_EXTERNAL_OBJECTS =

lib/libblockContainer.dylib: lib/CMakeFiles/blockContainer.dir/blockManager.cpp.o
lib/libblockContainer.dylib: lib/CMakeFiles/blockContainer.dir/build.make
lib/libblockContainer.dylib: lib/CMakeFiles/blockContainer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/songl/OneDrive/TLE-analyzer/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libblockContainer.dylib"
	cd /Users/songl/OneDrive/TLE-analyzer/build-release/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blockContainer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/blockContainer.dir/build: lib/libblockContainer.dylib

.PHONY : lib/CMakeFiles/blockContainer.dir/build

lib/CMakeFiles/blockContainer.dir/clean:
	cd /Users/songl/OneDrive/TLE-analyzer/build-release/lib && $(CMAKE_COMMAND) -P CMakeFiles/blockContainer.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/blockContainer.dir/clean

lib/CMakeFiles/blockContainer.dir/depend:
	cd /Users/songl/OneDrive/TLE-analyzer/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/songl/OneDrive/TLE-analyzer /Users/songl/OneDrive/TLE-analyzer/lib /Users/songl/OneDrive/TLE-analyzer/build-release /Users/songl/OneDrive/TLE-analyzer/build-release/lib /Users/songl/OneDrive/TLE-analyzer/build-release/lib/CMakeFiles/blockContainer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/blockContainer.dir/depend

