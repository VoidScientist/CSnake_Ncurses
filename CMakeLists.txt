########################################################

cmake_minimum_required(VERSION 3.31.0 FATAL_ERROR)

project(CSnakeGame VERSION 0.1.0 LANGUAGES C)

set(SRC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory("${SRC}/datastructs")
add_subdirectory("${SRC}/interface")
add_subdirectory("${SRC}/game")

########################################################

add_custom_target(copy_resources ALL cp -r "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${CMAKE_CURRENT_SOURCE_DIR}/builds/resources")

########################################################


add_executable(game "${SRC}/app.c")

target_link_libraries(game PRIVATE voidcurses)

add_dependencies(game copy_resources)


########################################################

