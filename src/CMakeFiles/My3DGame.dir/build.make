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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ricky/coding/GccGame-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ricky/coding/GccGame-main/src

# Include any dependencies generated for this target.
include CMakeFiles/My3DGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/My3DGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/My3DGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/My3DGame.dir/flags.make

CMakeFiles/My3DGame.dir/main.cpp.o: CMakeFiles/My3DGame.dir/flags.make
CMakeFiles/My3DGame.dir/main.cpp.o: main.cpp
CMakeFiles/My3DGame.dir/main.cpp.o: CMakeFiles/My3DGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricky/coding/GccGame-main/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/My3DGame.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/My3DGame.dir/main.cpp.o -MF CMakeFiles/My3DGame.dir/main.cpp.o.d -o CMakeFiles/My3DGame.dir/main.cpp.o -c /home/ricky/coding/GccGame-main/src/main.cpp

CMakeFiles/My3DGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/My3DGame.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricky/coding/GccGame-main/src/main.cpp > CMakeFiles/My3DGame.dir/main.cpp.i

CMakeFiles/My3DGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/My3DGame.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricky/coding/GccGame-main/src/main.cpp -o CMakeFiles/My3DGame.dir/main.cpp.s

CMakeFiles/My3DGame.dir/movement.cpp.o: CMakeFiles/My3DGame.dir/flags.make
CMakeFiles/My3DGame.dir/movement.cpp.o: movement.cpp
CMakeFiles/My3DGame.dir/movement.cpp.o: CMakeFiles/My3DGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricky/coding/GccGame-main/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/My3DGame.dir/movement.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/My3DGame.dir/movement.cpp.o -MF CMakeFiles/My3DGame.dir/movement.cpp.o.d -o CMakeFiles/My3DGame.dir/movement.cpp.o -c /home/ricky/coding/GccGame-main/src/movement.cpp

CMakeFiles/My3DGame.dir/movement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/My3DGame.dir/movement.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricky/coding/GccGame-main/src/movement.cpp > CMakeFiles/My3DGame.dir/movement.cpp.i

CMakeFiles/My3DGame.dir/movement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/My3DGame.dir/movement.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricky/coding/GccGame-main/src/movement.cpp -o CMakeFiles/My3DGame.dir/movement.cpp.s

CMakeFiles/My3DGame.dir/renderer.cpp.o: CMakeFiles/My3DGame.dir/flags.make
CMakeFiles/My3DGame.dir/renderer.cpp.o: renderer.cpp
CMakeFiles/My3DGame.dir/renderer.cpp.o: CMakeFiles/My3DGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ricky/coding/GccGame-main/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/My3DGame.dir/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/My3DGame.dir/renderer.cpp.o -MF CMakeFiles/My3DGame.dir/renderer.cpp.o.d -o CMakeFiles/My3DGame.dir/renderer.cpp.o -c /home/ricky/coding/GccGame-main/src/renderer.cpp

CMakeFiles/My3DGame.dir/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/My3DGame.dir/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricky/coding/GccGame-main/src/renderer.cpp > CMakeFiles/My3DGame.dir/renderer.cpp.i

CMakeFiles/My3DGame.dir/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/My3DGame.dir/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricky/coding/GccGame-main/src/renderer.cpp -o CMakeFiles/My3DGame.dir/renderer.cpp.s

# Object files for target My3DGame
My3DGame_OBJECTS = \
"CMakeFiles/My3DGame.dir/main.cpp.o" \
"CMakeFiles/My3DGame.dir/movement.cpp.o" \
"CMakeFiles/My3DGame.dir/renderer.cpp.o"

# External object files for target My3DGame
My3DGame_EXTERNAL_OBJECTS =

My3DGame: CMakeFiles/My3DGame.dir/main.cpp.o
My3DGame: CMakeFiles/My3DGame.dir/movement.cpp.o
My3DGame: CMakeFiles/My3DGame.dir/renderer.cpp.o
My3DGame: CMakeFiles/My3DGame.dir/build.make
My3DGame: /usr/lib/libGL.so
My3DGame: /usr/lib/libGLU.so
My3DGame: /usr/lib/libGLEW.so
My3DGame: /usr/lib/libglfw.so.3.4
My3DGame: CMakeFiles/My3DGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ricky/coding/GccGame-main/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable My3DGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/My3DGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/My3DGame.dir/build: My3DGame
.PHONY : CMakeFiles/My3DGame.dir/build

CMakeFiles/My3DGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/My3DGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/My3DGame.dir/clean

CMakeFiles/My3DGame.dir/depend:
	cd /home/ricky/coding/GccGame-main/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ricky/coding/GccGame-main /home/ricky/coding/GccGame-main /home/ricky/coding/GccGame-main/src /home/ricky/coding/GccGame-main/src /home/ricky/coding/GccGame-main/src/CMakeFiles/My3DGame.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/My3DGame.dir/depend

