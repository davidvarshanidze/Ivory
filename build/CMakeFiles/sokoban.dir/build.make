# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sasha/Ivory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sasha/Ivory/build

# Include any dependencies generated for this target.
include CMakeFiles/sokoban.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sokoban.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sokoban.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sokoban.dir/flags.make

CMakeFiles/sokoban.dir/codegen:
.PHONY : CMakeFiles/sokoban.dir/codegen

CMakeFiles/sokoban.dir/src/main.cpp.o: CMakeFiles/sokoban.dir/flags.make
CMakeFiles/sokoban.dir/src/main.cpp.o: /Users/sasha/Ivory/src/main.cpp
CMakeFiles/sokoban.dir/src/main.cpp.o: CMakeFiles/sokoban.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/sasha/Ivory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sokoban.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sokoban.dir/src/main.cpp.o -MF CMakeFiles/sokoban.dir/src/main.cpp.o.d -o CMakeFiles/sokoban.dir/src/main.cpp.o -c /Users/sasha/Ivory/src/main.cpp

CMakeFiles/sokoban.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/sokoban.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sasha/Ivory/src/main.cpp > CMakeFiles/sokoban.dir/src/main.cpp.i

CMakeFiles/sokoban.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/sokoban.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sasha/Ivory/src/main.cpp -o CMakeFiles/sokoban.dir/src/main.cpp.s

# Object files for target sokoban
sokoban_OBJECTS = \
"CMakeFiles/sokoban.dir/src/main.cpp.o"

# External object files for target sokoban
sokoban_EXTERNAL_OBJECTS =

sokoban: CMakeFiles/sokoban.dir/src/main.cpp.o
sokoban: CMakeFiles/sokoban.dir/build.make
sokoban: CMakeFiles/sokoban.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/sasha/Ivory/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sokoban"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sokoban.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sokoban.dir/build: sokoban
.PHONY : CMakeFiles/sokoban.dir/build

CMakeFiles/sokoban.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sokoban.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sokoban.dir/clean

CMakeFiles/sokoban.dir/depend:
	cd /Users/sasha/Ivory/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sasha/Ivory /Users/sasha/Ivory /Users/sasha/Ivory/build /Users/sasha/Ivory/build /Users/sasha/Ivory/build/CMakeFiles/sokoban.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sokoban.dir/depend

