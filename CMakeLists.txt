cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Shoot2Kill)

SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

####  Practical 1 ####
file(GLOB_RECURSE  SOURCES  practical_1/*.cpp  practical_1/*.h)
add_executable(PRACTICAL_1 ${SOURCES})
target_include_directories(PRACTICAL_1 PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_1 sfml-graphics)

#### Space invaders ####
file(GLOB_RECURSE SOURCES practical_2/*.cpp practical_2/*.h)
add_executable(PRACTICAL_2_INVADERS ${SOURCES} )
set_target_properties(PRACTICAL_2_INVADERS PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))
#### add_custom_target(copy_resources  ALL  COMMAND ${CMAKE_COMMAND} ####
	#### -E copy_directory ####
	#### "${PROJECT_SOURCE_DIR}/res" ####
	#### ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res) ####
#### add_dependencies(PRACTICAL_2_INVADERS copy_resources) ####
target_include_directories(PRACTICAL_2_INVADERS SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_2_INVADERS sfml-graphics)

## Maths  lib
add_library(lib_maths INTERFACE)
target_sources(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths/maths.h")
target_include_directories(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths" SYSTEM INTERFACE ${SFML_INCS})

#### The Tile loader lib ####
file(GLOB_RECURSE SOURCE_FILES lib_tile_level_loader/*.cpp  lib_tile_level_loader/*.h)
add_library(lib_tile_level_loader STATIC ${SOURCE_FILES})
target_include_directories(lib_tile_level_loader INTERFACE
		"${CMAKE_SOURCE_DIR}/lib_tile_level_loader/" )
target_link_libraries(lib_tile_level_loader lib_maths sfml-graphics)

#### Maze Game ####
file(GLOB_RECURSE SOURCES practical_3/*.cpp practical_3/*.h)
add_executable(PRACTICAL_3_MAZE_GAME ${SOURCES} )
set_target_properties(PRACTICAL_3_MAZE_GAME PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))
add_dependencies(PRACTICAL_3_MAZE_GAME copy_resources)
target_include_directories(PRACTICAL_3_MAZE_GAME SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_3_MAZE_GAME lib_tile_level_loader sfml-graphics)

#### The ECM lib ####
file(GLOB_RECURSE SOURCE_FILES lib_ecm/*.cpp  lib_ecm/*.h)
add_library(lib_ecm STATIC ${SOURCE_FILES})
target_include_directories(lib_ecm INTERFACE
		"${CMAKE_SOURCE_DIR}/lib_ecm" )
target_link_libraries(lib_ecm PRIVATE lib_maths)

#### Pacman Game ####
file(GLOB_RECURSE SOURCES practical_4/*.cpp practical_4/*.h)
add_executable(PRACTICAL_4_PACMAN ${SOURCES} )
set_target_properties(PRACTICAL_4_PACMAN PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))
add_dependencies(PRACTICAL_4_PACMAN copy_resources)
target_include_directories(PRACTICAL_4_PACMAN SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_4_PACMAN sfml-graphics lib_ecm)


#### Shoot2Kill Game ####
file(GLOB_RECURSE SOURCES shoot2kill/*.cpp shoot2kill/*.h)
add_executable(SHOOT2KILL ${SOURCES})
set_target_properties(SHOOT2KILL PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration))
add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND}
	-E copy_directory
	"${PROJECT_SOURCE_DIR}/res"
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res)
add_dependencies(SHOOT2KILL copy_resources)
target_include_directories(SHOOT2KILL SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(SHOOT2KILL sfml-graphics)
