/**
 *	\file		interface.c	
 *	\brief		Implementation of interfaces 
 *	\author		VoidScientist
 *	\version	1.0
 */
#include <ncurses.h>
#include "interface.h"
#include "sprite.h"
#include "button.h"


#define START_ACTION  1
#define QUIT_ACTION   2


typedef enum {QUIT_MENU, MAIN_MENU} menu_t;


int mainSubMenu(menu_t *pState, menuResult_t *pResult);


menuResult_t startPlayerMenu(void) {
	
	menu_t        state   = MAIN_MENU;
	menuResult_t  result  = NONE;
	
	int           running = 1;

	while (running) {

		switch(state) {

			case MAIN_MENU: 
					mainSubMenu(&state, &result); 
					break; 
	
			case QUIT_MENU:
			default: 	
				running = 0;
			   	break;

		}

	}

	return result;

}



int mainSubMenu(menu_t *pState, menuResult_t *pResult) {

	sprite_t 	logo;
	button_t    start, quit;
	button_t    *pCurrent;
	nPair_t     logoColor;
	nPair_t     selectedColor;
	
	int 		pressedKey;

	int			running     = 1;

	int 		action      = 0;


	initSprite(&logo, "./resources/logo.txt");

	initPair(&logoColor, COLOR_GREEN, COLOR_BLACK);
	initPair(&selectedColor, COLOR_BLUE, COLOR_BLACK);

	initButton(&start, "Start Game", START_ACTION, NULL, &quit);
	initButton(&quit, "Quit  Game", QUIT_ACTION, &start, NULL);

	pCurrent              = &start;
	pCurrent->isSelected  = 1;
	
	
	while (running) {

		clear();

		drawSpriteColored(logo, 0.1 * LINES, COLS / 2, VO_CENTER, logoColor);

		drawButtonCentered(start, LINES / 2 - 2, COLS / 2, selectedColor);

		drawButtonCentered(quit, LINES / 2 + 2, COLS / 2, selectedColor);

		refresh();


		pressedKey = getch();
        

		switch (pressedKey) {

			case KEY_UP: 
				selectPrevButton(&pCurrent);
				break;

			case KEY_DOWN: 
				selectNextButton(&pCurrent);
				break;

			case '\n':
			case KEY_ENTER:
				action  = pCurrent->id;
				running = 0;
				break;	

			default: 
				break;

		}


	}

	freeSprite(&logo);

	switch (action) {

		case START_ACTION:
				*pResult = START_GAME;
				*pState  = QUIT_MENU;
				break;

		case QUIT_ACTION:
				*pResult = QUIT_GAME;
				*pState  = QUIT_MENU;
				break;

	}

	return 0;

}
