# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jackson/code/qt/QtServer/QtServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jackson/code/qt/QtServer/QtServer-build

# Include any dependencies generated for this target.
include CMakeFiles/QtServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QtServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QtServer.dir/flags.make

CMakeFiles/QtServer.dir/main.cpp.o: CMakeFiles/QtServer.dir/flags.make
CMakeFiles/QtServer.dir/main.cpp.o: /home/jackson/code/qt/QtServer/QtServer/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jackson/code/qt/QtServer/QtServer-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/QtServer.dir/main.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/QtServer.dir/main.cpp.o -c /home/jackson/code/qt/QtServer/QtServer/main.cpp

CMakeFiles/QtServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtServer.dir/main.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jackson/code/qt/QtServer/QtServer/main.cpp > CMakeFiles/QtServer.dir/main.cpp.i

CMakeFiles/QtServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtServer.dir/main.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jackson/code/qt/QtServer/QtServer/main.cpp -o CMakeFiles/QtServer.dir/main.cpp.s

CMakeFiles/QtServer.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/QtServer.dir/main.cpp.o.requires

CMakeFiles/QtServer.dir/main.cpp.o.provides: CMakeFiles/QtServer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/QtServer.dir/build.make CMakeFiles/QtServer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/QtServer.dir/main.cpp.o.provides

CMakeFiles/QtServer.dir/main.cpp.o.provides.build: CMakeFiles/QtServer.dir/main.cpp.o

# Object files for target QtServer
QtServer_OBJECTS = \
"CMakeFiles/QtServer.dir/main.cpp.o"

# External object files for target QtServer
QtServer_EXTERNAL_OBJECTS =

QtServer: CMakeFiles/QtServer.dir/main.cpp.o
QtServer: CMakeFiles/QtServer.dir/build.make
QtServer: CMakeFiles/QtServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable QtServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QtServer.dir/build: QtServer
.PHONY : CMakeFiles/QtServer.dir/build

CMakeFiles/QtServer.dir/requires: CMakeFiles/QtServer.dir/main.cpp.o.requires
.PHONY : CMakeFiles/QtServer.dir/requires

CMakeFiles/QtServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtServer.dir/clean

CMakeFiles/QtServer.dir/depend:
	cd /home/jackson/code/qt/QtServer/QtServer-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jackson/code/qt/QtServer/QtServer /home/jackson/code/qt/QtServer/QtServer /home/jackson/code/qt/QtServer/QtServer-build /home/jackson/code/qt/QtServer/QtServer-build /home/jackson/code/qt/QtServer/QtServer-build/CMakeFiles/QtServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtServer.dir/depend

