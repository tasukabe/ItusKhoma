# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build"

# Include any dependencies generated for this target.
include CMakeFiles/ItusKhoma.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ItusKhoma.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ItusKhoma.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ItusKhoma.dir/flags.make

CMakeFiles/ItusKhoma.dir/Main.cpp.o: CMakeFiles/ItusKhoma.dir/flags.make
CMakeFiles/ItusKhoma.dir/Main.cpp.o: ../Main.cpp
CMakeFiles/ItusKhoma.dir/Main.cpp.o: CMakeFiles/ItusKhoma.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ItusKhoma.dir/Main.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ItusKhoma.dir/Main.cpp.o -MF CMakeFiles/ItusKhoma.dir/Main.cpp.o.d -o CMakeFiles/ItusKhoma.dir/Main.cpp.o -c "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/Main.cpp"

CMakeFiles/ItusKhoma.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ItusKhoma.dir/Main.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/Main.cpp" > CMakeFiles/ItusKhoma.dir/Main.cpp.i

CMakeFiles/ItusKhoma.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ItusKhoma.dir/Main.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/Main.cpp" -o CMakeFiles/ItusKhoma.dir/Main.cpp.s

CMakeFiles/ItusKhoma.dir/Render.cpp.o: CMakeFiles/ItusKhoma.dir/flags.make
CMakeFiles/ItusKhoma.dir/Render.cpp.o: ../Render.cpp
CMakeFiles/ItusKhoma.dir/Render.cpp.o: CMakeFiles/ItusKhoma.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ItusKhoma.dir/Render.cpp.o"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ItusKhoma.dir/Render.cpp.o -MF CMakeFiles/ItusKhoma.dir/Render.cpp.o.d -o CMakeFiles/ItusKhoma.dir/Render.cpp.o -c "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/Render.cpp"

CMakeFiles/ItusKhoma.dir/Render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ItusKhoma.dir/Render.cpp.i"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/Render.cpp" > CMakeFiles/ItusKhoma.dir/Render.cpp.i

CMakeFiles/ItusKhoma.dir/Render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ItusKhoma.dir/Render.cpp.s"
	/usr/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/Render.cpp" -o CMakeFiles/ItusKhoma.dir/Render.cpp.s

# Object files for target ItusKhoma
ItusKhoma_OBJECTS = \
"CMakeFiles/ItusKhoma.dir/Main.cpp.o" \
"CMakeFiles/ItusKhoma.dir/Render.cpp.o"

# External object files for target ItusKhoma
ItusKhoma_EXTERNAL_OBJECTS =

ItusKhoma: CMakeFiles/ItusKhoma.dir/Main.cpp.o
ItusKhoma: CMakeFiles/ItusKhoma.dir/Render.cpp.o
ItusKhoma: CMakeFiles/ItusKhoma.dir/build.make
ItusKhoma: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
ItusKhoma: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
ItusKhoma: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
ItusKhoma: CMakeFiles/ItusKhoma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ItusKhoma"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ItusKhoma.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ItusKhoma.dir/build: ItusKhoma
.PHONY : CMakeFiles/ItusKhoma.dir/build

CMakeFiles/ItusKhoma.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ItusKhoma.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ItusKhoma.dir/clean

CMakeFiles/ItusKhoma.dir/depend:
	cd "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma" "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma" "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build" "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build" "/home/tasukabe/Codes/cpp/Experiment/Itu's Khoma/build/CMakeFiles/ItusKhoma.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ItusKhoma.dir/depend

