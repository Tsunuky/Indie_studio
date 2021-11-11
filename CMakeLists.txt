cmake_minimum_required (VERSION 3.11)
project (Indie_Studio)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-g -O0 -shared-libgcc -Wfatal-errors")

##set (EXECUTABLE_OUTPUT_PATH")
##set (LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/game")

find_package (Threads REQUIRED)
find_package(Boost REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

##set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

##find_package(SFML 2 REQUIRED system window graphics network audio)

##if(SFML_FOUND)
##        include_directories(${SFML_INCLUDE_DIR})
##        target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
##endif()


set (SRC_GRAPH
        sources/Graph/Graph.cpp
        )

set (SRC_CORE
        sources/core.cpp
        sources/main.cpp
        sources/parsers.cpp
        sources/main_menu.cpp
        sources/menu_local.cpp
        sources/menu_multi.cpp
        sources/menu_continue.cpp
        )

set (GAME_SRC
        sources/Game/Game.cpp
        sources/Game/bot.cpp
        sources/Game/botDump.cpp
        sources/Game/botGetters.cpp
        sources/Game/botMoves.cpp
        sources/Game/placeDump.cpp
        sources/Game/placeFinding.cpp
        sources/Game/placement.cpp
        sources/Game/placePlayer.cpp
        sources/Game/System/System_Ctor.cpp
        sources/Game/System/PoseBombSystem.cpp
        sources/Game/System/ExplosionCountDownSystem.cpp
        sources/Game/System/BombCountDownSystem.cpp
        sources/Game/System/CollidingSystem.cpp
        )

set(LD_FLAGS
        -rdynamic
        -lsfml-audio
        )

set(LD_FLAGS_LIB
        -lXxf86vm
        -lX11
        -lXcursor
        -lsfml-audio
        )

if (UNIX)

add_custom_target("Irrlicht")
add_custom_command(TARGET Irrlicht
  COMMAND make sharedlib ##&& ln -s ../../lib/Linux/libIrrlicht.so.1.8.4 ../../lib/Linux/libIrrlicht.so.1.8 && ln -s ../../lib/Linux/libIrrlicht.so.1.8 ../../lib/Linux/libIrrlicht.so
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/irrlicht-1.8.4/source/Irrlicht"
                   )

 set(IRR_FLAGS
        -lIrrlicht
	-Wl,-rpath=./../irrlicht-1.8.4/lib/Linux/

   )
elseif (WIN32)

add_custom_target("Irrlicht")
add_custom_command(TARGET Irrlicht
  COMMAND make sharedlib_win32 && make install
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/irrlicht-1.8.4/source/Irrlicht
                   )

 set(IRR_FLAGS
        -lIrrlicht
	-Wl,-rpath=./../irrlicht-1.8.4/lib/Win64-visualStudio/

   )
endif (UNIX)


add_executable(studio ${SRC_CORE})
target_link_libraries (studio ${LD_FLAGS} ${CMAKE_DL_LIBS} )

add_library(Bomberman SHARED ${GAME_SRC})
target_link_libraries (Bomberman ${CMAKE_THREAD_LIBS_INIT} ${LD_FLAGS})

set (LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")

add_library(MyIrrlicht SHARED ${SRC_GRAPH})
target_link_libraries (MyIrrlicht ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${LD_FLAGS_LIB} ${IRR_FLAGS})
add_dependencies(MyIrrlicht Irrlicht)

target_include_directories(studio PUBLIC
        includes
        irrlicht-1.8.4/include
        )

target_include_directories(Bomberman PUBLIC
        includes
        )

target_include_directories(MyIrrlicht PUBLIC
        includes
        irrlicht-1.8.4/include
        ${OPENGL_INCLUDE_DIRS}
        ${GLUT_INCLUDE_DIRS}
        )
