# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lana/Desktop/reset/нетология/async_multithread/02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lana/Desktop/reset/нетология/async_multithread/02/build

# Include any dependencies generated for this target.
include CMakeFiles/thread_vecExe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/thread_vecExe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thread_vecExe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread_vecExe.dir/flags.make

CMakeFiles/thread_vecExe.dir/main.cpp.o: CMakeFiles/thread_vecExe.dir/flags.make
CMakeFiles/thread_vecExe.dir/main.cpp.o: /Users/lana/Desktop/reset/нетология/async_multithread/02/main.cpp
CMakeFiles/thread_vecExe.dir/main.cpp.o: CMakeFiles/thread_vecExe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lana/Desktop/reset/нетология/async_multithread/02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread_vecExe.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thread_vecExe.dir/main.cpp.o -MF CMakeFiles/thread_vecExe.dir/main.cpp.o.d -o CMakeFiles/thread_vecExe.dir/main.cpp.o -c /Users/lana/Desktop/reset/нетология/async_multithread/02/main.cpp

CMakeFiles/thread_vecExe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/thread_vecExe.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lana/Desktop/reset/нетология/async_multithread/02/main.cpp > CMakeFiles/thread_vecExe.dir/main.cpp.i

CMakeFiles/thread_vecExe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/thread_vecExe.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lana/Desktop/reset/нетология/async_multithread/02/main.cpp -o CMakeFiles/thread_vecExe.dir/main.cpp.s

# Object files for target thread_vecExe
thread_vecExe_OBJECTS = \
"CMakeFiles/thread_vecExe.dir/main.cpp.o"

# External object files for target thread_vecExe
thread_vecExe_EXTERNAL_OBJECTS =

thread_vecExe: CMakeFiles/thread_vecExe.dir/main.cpp.o
thread_vecExe: CMakeFiles/thread_vecExe.dir/build.make
thread_vecExe: CMakeFiles/thread_vecExe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lana/Desktop/reset/нетология/async_multithread/02/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_vecExe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_vecExe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread_vecExe.dir/build: thread_vecExe
.PHONY : CMakeFiles/thread_vecExe.dir/build

CMakeFiles/thread_vecExe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread_vecExe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread_vecExe.dir/clean

CMakeFiles/thread_vecExe.dir/depend:
	cd /Users/lana/Desktop/reset/нетология/async_multithread/02/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lana/Desktop/reset/нетология/async_multithread/02 /Users/lana/Desktop/reset/нетология/async_multithread/02 /Users/lana/Desktop/reset/нетология/async_multithread/02/build /Users/lana/Desktop/reset/нетология/async_multithread/02/build /Users/lana/Desktop/reset/нетология/async_multithread/02/build/CMakeFiles/thread_vecExe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/thread_vecExe.dir/depend

