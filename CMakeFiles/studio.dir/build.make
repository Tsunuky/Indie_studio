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

# Include any dependencies generated for this target.
include CMakeFiles/studio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/studio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/studio.dir/flags.make

CMakeFiles/studio.dir/sources/core.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/core.cpp.o: sources/core.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/studio.dir/sources/core.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/core.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/core.cpp

CMakeFiles/studio.dir/sources/core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/core.cpp > CMakeFiles/studio.dir/sources/core.cpp.i

CMakeFiles/studio.dir/sources/core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/core.cpp -o CMakeFiles/studio.dir/sources/core.cpp.s

CMakeFiles/studio.dir/sources/main.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/main.cpp.o: sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/studio.dir/sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/main.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/main.cpp

CMakeFiles/studio.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/main.cpp > CMakeFiles/studio.dir/sources/main.cpp.i

CMakeFiles/studio.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/main.cpp -o CMakeFiles/studio.dir/sources/main.cpp.s

CMakeFiles/studio.dir/sources/parsers.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/parsers.cpp.o: sources/parsers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/studio.dir/sources/parsers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/parsers.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/parsers.cpp

CMakeFiles/studio.dir/sources/parsers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/parsers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/parsers.cpp > CMakeFiles/studio.dir/sources/parsers.cpp.i

CMakeFiles/studio.dir/sources/parsers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/parsers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/parsers.cpp -o CMakeFiles/studio.dir/sources/parsers.cpp.s

CMakeFiles/studio.dir/sources/main_menu.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/main_menu.cpp.o: sources/main_menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/studio.dir/sources/main_menu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/main_menu.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/main_menu.cpp

CMakeFiles/studio.dir/sources/main_menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/main_menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/main_menu.cpp > CMakeFiles/studio.dir/sources/main_menu.cpp.i

CMakeFiles/studio.dir/sources/main_menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/main_menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/main_menu.cpp -o CMakeFiles/studio.dir/sources/main_menu.cpp.s

CMakeFiles/studio.dir/sources/menu_local.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/menu_local.cpp.o: sources/menu_local.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/studio.dir/sources/menu_local.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/menu_local.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/menu_local.cpp

CMakeFiles/studio.dir/sources/menu_local.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/menu_local.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/menu_local.cpp > CMakeFiles/studio.dir/sources/menu_local.cpp.i

CMakeFiles/studio.dir/sources/menu_local.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/menu_local.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/menu_local.cpp -o CMakeFiles/studio.dir/sources/menu_local.cpp.s

CMakeFiles/studio.dir/sources/menu_multi.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/menu_multi.cpp.o: sources/menu_multi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/studio.dir/sources/menu_multi.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/menu_multi.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/menu_multi.cpp

CMakeFiles/studio.dir/sources/menu_multi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/menu_multi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/menu_multi.cpp > CMakeFiles/studio.dir/sources/menu_multi.cpp.i

CMakeFiles/studio.dir/sources/menu_multi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/menu_multi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/menu_multi.cpp -o CMakeFiles/studio.dir/sources/menu_multi.cpp.s

CMakeFiles/studio.dir/sources/menu_continue.cpp.o: CMakeFiles/studio.dir/flags.make
CMakeFiles/studio.dir/sources/menu_continue.cpp.o: sources/menu_continue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/studio.dir/sources/menu_continue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/studio.dir/sources/menu_continue.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/menu_continue.cpp

CMakeFiles/studio.dir/sources/menu_continue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/studio.dir/sources/menu_continue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/menu_continue.cpp > CMakeFiles/studio.dir/sources/menu_continue.cpp.i

CMakeFiles/studio.dir/sources/menu_continue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/studio.dir/sources/menu_continue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/menu_continue.cpp -o CMakeFiles/studio.dir/sources/menu_continue.cpp.s

# Object files for target studio
studio_OBJECTS = \
"CMakeFiles/studio.dir/sources/core.cpp.o" \
"CMakeFiles/studio.dir/sources/main.cpp.o" \
"CMakeFiles/studio.dir/sources/parsers.cpp.o" \
"CMakeFiles/studio.dir/sources/main_menu.cpp.o" \
"CMakeFiles/studio.dir/sources/menu_local.cpp.o" \
"CMakeFiles/studio.dir/sources/menu_multi.cpp.o" \
"CMakeFiles/studio.dir/sources/menu_continue.cpp.o"

# External object files for target studio
studio_EXTERNAL_OBJECTS =

studio: CMakeFiles/studio.dir/sources/core.cpp.o
studio: CMakeFiles/studio.dir/sources/main.cpp.o
studio: CMakeFiles/studio.dir/sources/parsers.cpp.o
studio: CMakeFiles/studio.dir/sources/main_menu.cpp.o
studio: CMakeFiles/studio.dir/sources/menu_local.cpp.o
studio: CMakeFiles/studio.dir/sources/menu_multi.cpp.o
studio: CMakeFiles/studio.dir/sources/menu_continue.cpp.o
studio: CMakeFiles/studio.dir/build.make
studio: CMakeFiles/studio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable studio"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/studio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/studio.dir/build: studio

.PHONY : CMakeFiles/studio.dir/build

CMakeFiles/studio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/studio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/studio.dir/clean

CMakeFiles/studio.dir/depend:
	cd /home/wolfyre/OOP_indie_studio_2018 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018/CMakeFiles/studio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/studio.dir/depend

