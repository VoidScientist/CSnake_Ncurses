/**
 *	\file		game.c
 *	\brief		Snake Game main file
 *	\author		VoidScientist
 *	\version	1.0
 */
#include <ncurses.h>
#include <ncolors.h>
#include <interface.h>


int SNAKE_COLOR = 1;


void initNcurses() {

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	

}



int main(void) {

	menuResult_t action;


	initNcurses();
	

	action = startPlayerMenu();


	endwin();


	printf("Chosen action: %d\n", action);

	return 0;
	
}
