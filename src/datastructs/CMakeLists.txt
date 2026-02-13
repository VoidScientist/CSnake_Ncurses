##########################################

cmake_minimum_required(VERSION 3.31.0 FATAL_ERROR)

project(VoidStructs VERSION 0.1.0 LANGUAGES C)

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")

###########################################

add_library(

	voidstructs

	"${SRC}/sllist.c"

)

target_include_directories(voidstructs PUBLIC "${SRC}/include")

###########################################

