############################################

cmake_minimum_required(VERSION 3.31.0 FATAL_ERROR)

project (VoidNcurses VERSION 0.1.0 LANGUAGES C)

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")

############################################

find_library(NCURSES ncurses REQUIRED)

########################################################

add_library(

	voidcurses

	"${SRC}/ncolors.c"
	"${SRC}/sprite.c"
	"${SRC}/interface.c"
	"${SRC}/button.c"

)

target_include_directories(voidcurses PUBLIC "${SRC}/include")
target_link_libraries(voidcurses PUBLIC ${NCURSES})

########################################################
