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
include CMakeFiles/Bomberman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bomberman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bomberman.dir/flags.make

CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.o: sources/Game/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/Game.cpp

CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/Game.cpp > CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/Game.cpp -o CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.o: sources/Game/bot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/bot.cpp

CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/bot.cpp > CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/bot.cpp -o CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.o: sources/Game/botDump.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/botDump.cpp

CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/botDump.cpp > CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/botDump.cpp -o CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.o: sources/Game/botGetters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/botGetters.cpp

CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/botGetters.cpp > CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/botGetters.cpp -o CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.o: sources/Game/botMoves.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/botMoves.cpp

CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/botMoves.cpp > CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/botMoves.cpp -o CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.o: sources/Game/placeDump.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/placeDump.cpp

CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/placeDump.cpp > CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/placeDump.cpp -o CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.o: sources/Game/placeFinding.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/placeFinding.cpp

CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/placeFinding.cpp > CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/placeFinding.cpp -o CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.o: sources/Game/placement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/placement.cpp

CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/placement.cpp > CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/placement.cpp -o CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.o: sources/Game/placePlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/placePlayer.cpp

CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/placePlayer.cpp > CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/placePlayer.cpp -o CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.o: sources/Game/System/System_Ctor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/System_Ctor.cpp

CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/System_Ctor.cpp > CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/System_Ctor.cpp -o CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.o: sources/Game/System/PoseBombSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/PoseBombSystem.cpp

CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/PoseBombSystem.cpp > CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/PoseBombSystem.cpp -o CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.o: sources/Game/System/ExplosionCountDownSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/ExplosionCountDownSystem.cpp

CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/ExplosionCountDownSystem.cpp > CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/ExplosionCountDownSystem.cpp -o CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.o: sources/Game/System/BombCountDownSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/BombCountDownSystem.cpp

CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/BombCountDownSystem.cpp > CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/BombCountDownSystem.cpp -o CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.s

CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.o: CMakeFiles/Bomberman.dir/flags.make
CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.o: sources/Game/System/CollidingSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.o -c /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/CollidingSystem.cpp

CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/CollidingSystem.cpp > CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.i

CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wolfyre/OOP_indie_studio_2018/sources/Game/System/CollidingSystem.cpp -o CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.s

# Object files for target Bomberman
Bomberman_OBJECTS = \
"CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.o" \
"CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.o"

# External object files for target Bomberman
Bomberman_EXTERNAL_OBJECTS =

lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/Game.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/bot.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/botDump.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/botGetters.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/botMoves.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/placeDump.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/placeFinding.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/placement.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/placePlayer.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/System/System_Ctor.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/System/PoseBombSystem.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/System/ExplosionCountDownSystem.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/System/BombCountDownSystem.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/sources/Game/System/CollidingSystem.cpp.o
lib/libBomberman.so: CMakeFiles/Bomberman.dir/build.make
lib/libBomberman.so: CMakeFiles/Bomberman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wolfyre/OOP_indie_studio_2018/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX shared library lib/libBomberman.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bomberman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bomberman.dir/build: lib/libBomberman.so

.PHONY : CMakeFiles/Bomberman.dir/build

CMakeFiles/Bomberman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bomberman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bomberman.dir/clean

CMakeFiles/Bomberman.dir/depend:
	cd /home/wolfyre/OOP_indie_studio_2018 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018 /home/wolfyre/OOP_indie_studio_2018/CMakeFiles/Bomberman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bomberman.dir/depend

