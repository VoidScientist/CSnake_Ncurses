/**
 * @file   button.h
 * 
 * @brief  header file for a ncurse button system
 *
 * @author VoidScientist
 *
 */

#ifndef VOID_BUTTONS
#define VOID_BUTTONS

#include "ncolors.h"

typedef struct button {

	char           *pLabel;
	int            id; 
	int            width;
	int            isSelected;
	struct button  *pPrev;
	struct button  *pNext;
	
} button_t;


int initButton(button_t *button, char *label, int id, button_t *prev, button_t *next);


int drawButton(button_t button, int y, int x, nPair_t colorPair);


int drawButtonCentered(button_t button, int y, int x, nPair_t colorPair);


int selectNextButton(button_t **ppCurrent);

int selectPrevButton(button_t **ppCurrent);


#endif /* VOID_BUTTONS */
