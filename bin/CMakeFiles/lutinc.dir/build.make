# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/edouard/lutin/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edouard/lutin/bin

# Include any dependencies generated for this target.
include CMakeFiles/lutinc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lutinc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lutinc.dir/flags.make

CMakeFiles/lutinc.dir/lexer.cpp.o: CMakeFiles/lutinc.dir/flags.make
CMakeFiles/lutinc.dir/lexer.cpp.o: /home/edouard/lutin/src/lexer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/edouard/lutin/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lutinc.dir/lexer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lutinc.dir/lexer.cpp.o -c /home/edouard/lutin/src/lexer.cpp

CMakeFiles/lutinc.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lutinc.dir/lexer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/edouard/lutin/src/lexer.cpp > CMakeFiles/lutinc.dir/lexer.cpp.i

CMakeFiles/lutinc.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lutinc.dir/lexer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/edouard/lutin/src/lexer.cpp -o CMakeFiles/lutinc.dir/lexer.cpp.s

CMakeFiles/lutinc.dir/lexer.cpp.o.requires:
.PHONY : CMakeFiles/lutinc.dir/lexer.cpp.o.requires

CMakeFiles/lutinc.dir/lexer.cpp.o.provides: CMakeFiles/lutinc.dir/lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/lutinc.dir/build.make CMakeFiles/lutinc.dir/lexer.cpp.o.provides.build
.PHONY : CMakeFiles/lutinc.dir/lexer.cpp.o.provides

CMakeFiles/lutinc.dir/lexer.cpp.o.provides.build: CMakeFiles/lutinc.dir/lexer.cpp.o

CMakeFiles/lutinc.dir/states/e1.cpp.o: CMakeFiles/lutinc.dir/flags.make
CMakeFiles/lutinc.dir/states/e1.cpp.o: /home/edouard/lutin/src/states/e1.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/edouard/lutin/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lutinc.dir/states/e1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lutinc.dir/states/e1.cpp.o -c /home/edouard/lutin/src/states/e1.cpp

CMakeFiles/lutinc.dir/states/e1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lutinc.dir/states/e1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/edouard/lutin/src/states/e1.cpp > CMakeFiles/lutinc.dir/states/e1.cpp.i

CMakeFiles/lutinc.dir/states/e1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lutinc.dir/states/e1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/edouard/lutin/src/states/e1.cpp -o CMakeFiles/lutinc.dir/states/e1.cpp.s

CMakeFiles/lutinc.dir/states/e1.cpp.o.requires:
.PHONY : CMakeFiles/lutinc.dir/states/e1.cpp.o.requires

CMakeFiles/lutinc.dir/states/e1.cpp.o.provides: CMakeFiles/lutinc.dir/states/e1.cpp.o.requires
	$(MAKE) -f CMakeFiles/lutinc.dir/build.make CMakeFiles/lutinc.dir/states/e1.cpp.o.provides.build
.PHONY : CMakeFiles/lutinc.dir/states/e1.cpp.o.provides

CMakeFiles/lutinc.dir/states/e1.cpp.o.provides.build: CMakeFiles/lutinc.dir/states/e1.cpp.o

# Object files for target lutinc
lutinc_OBJECTS = \
"CMakeFiles/lutinc.dir/lexer.cpp.o" \
"CMakeFiles/lutinc.dir/states/e1.cpp.o"

# External object files for target lutinc
lutinc_EXTERNAL_OBJECTS =

lutinc: CMakeFiles/lutinc.dir/lexer.cpp.o
lutinc: CMakeFiles/lutinc.dir/states/e1.cpp.o
lutinc: CMakeFiles/lutinc.dir/build.make
lutinc: CMakeFiles/lutinc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lutinc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lutinc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lutinc.dir/build: lutinc
.PHONY : CMakeFiles/lutinc.dir/build

CMakeFiles/lutinc.dir/requires: CMakeFiles/lutinc.dir/lexer.cpp.o.requires
CMakeFiles/lutinc.dir/requires: CMakeFiles/lutinc.dir/states/e1.cpp.o.requires
.PHONY : CMakeFiles/lutinc.dir/requires

CMakeFiles/lutinc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lutinc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lutinc.dir/clean

CMakeFiles/lutinc.dir/depend:
	cd /home/edouard/lutin/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edouard/lutin/src /home/edouard/lutin/src /home/edouard/lutin/bin /home/edouard/lutin/bin /home/edouard/lutin/bin/CMakeFiles/lutinc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lutinc.dir/depend

