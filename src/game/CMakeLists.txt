###############################################

cmake_minimum_required(VERSION 3.31.0 FATAL_ERROR)

project(SnakeGame VERSION 0.1.0 LANGUAGES C)

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")

###############################################

add_library(

	voidsnake
	
	"${SRC}/game.c"
	"${SRC}/vector2.c"

)

target_include_directories(voidsnake PUBLIC "${SRC}/include")

###############################################
