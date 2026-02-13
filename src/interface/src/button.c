/**
 * @file   button.c
 *
 * @brief  implementation file for a ncurse button system 
 *
 * @author VoidScientist
 *
 */

#include <string.h>
#include "button.h"
#include "ncolors.h"


#define BUTTON_PREFIX          "[ "
#define BUTTON_SUFFIX          " ]"

#define BUTTON_FMT_UNSELECTED  "%s%s%s"
#define BUTTON_FMT_SELECTED    "%s %s %s"


const short BUTTON_PREFIX_LEN        = strlen(BUTTON_PREFIX);
const short BUTTON_SUFFIX_LEN        = strlen(BUTTON_SUFFIX);
const short BUTTON_SELECTED_DELTAW   = strlen(BUTTON_FMT_SELECTED) - strlen(BUTTON_FMT_UNSELECTED);


int initButton(button_t *button, char *label, int id, button_t *prev, button_t *next) {

	button->pLabel     = label;
	button->id         = id;
	button->isSelected = 0;
	button->width      = strlen(label) + BUTTON_PREFIX_LEN + BUTTON_SUFFIX_LEN;
	button->pPrev      = prev;
	button->pNext      = next;

	return 1;

}



int drawButton(button_t button, int y, int x, nPair_t colorPair) {

	char *fmt = button.isSelected ? BUTTON_FMT_SELECTED : BUTTON_FMT_UNSELECTED;

	if (button.isSelected) {

		setPair(colorPair);

	}
	
	mvprintw(y, x, fmt, BUTTON_PREFIX, button.pLabel, BUTTON_SUFFIX);

	if (button.isSelected) {

		unsetPair(colorPair);

	}

	return 1;

}


int drawButtonCentered(button_t button, int y, int x, nPair_t colorPair) {

	int realw = button.width + (button.isSelected ? BUTTON_SELECTED_DELTAW : 0);

	return drawButton(button, y, x - realw / 2, colorPair);

}


int selectNextButton(button_t **ppCurrent) {

		button_t *pCurrent   = *ppCurrent;
		button_t *pNext 	 = pCurrent->pNext;

		if (pNext == NULL) return 0;

		pCurrent->isSelected = 0;
		*ppCurrent           = pNext;

		pNext->isSelected    = 1;

		return 1;

}


int selectPrevButton(button_t **ppCurrent) {

		button_t *pCurrent   = *ppCurrent;
		button_t *pPrev 	 = pCurrent->pPrev;

		if (pPrev == NULL) return 0;

		pCurrent->isSelected = 0;
		*ppCurrent           = pPrev;

		pPrev->isSelected    = 1;

		return 1;

}
