# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wolfyre/OOP_indie_studio_2018

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wolfyre/OOP_indie_studio_2018

# Utility rule file for Irrlicht.

# Include the progress variables for this target.
include CMakeFiles/Irrlicht.dir/progress.make

Irrlicht: CMakeFiles/Irrlicht.dir/build.make
	cd /home/wolfyre/OOP_indie_studio_2018/irrlicht-1.8.4/source/Irrlicht && make sharedlib
.PHONY : Irrlicht

# Rule to build all files generated by this target.
CMakeFiles/Irrlicht.dir/build: Irrlicht

.PHONY : CMakeFiles/Irrlicht.dir/build

CMakeFiles/Irrlicht.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Irrlicht.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Irrlicht.dir/clean

CMakeFiles/Irrlicht.dir/depend:
	cd /home/wolfyre/OOP_indie_studio_2018 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018/CMakeFiles/Irrlicht.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Irrlicht.dir/depend
