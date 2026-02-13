/**
 *	\file		ncolors.c
 *	\brief		Implementation of utility functions to work with colors
 *	\author		VoidScientist
 *	\version	1.0
 */

#include <ncurses.h>
#include "ncolors.h"


static int pairCount = 1;



int initPair(nPair_t *pPair, NCURSES_COLOR_T fg, NCURSES_COLOR_T bg) {

	if (init_pair(pairCount, fg, bg) == ERR) {
		return -1;
	}


	pPair->id = pairCount++;
	pPair->fg = fg;
	pPair->bg = bg;


	return 1;

}



int setPair(nPair_t pPair) {

	return attron(COLOR_PAIR(pPair.id));

}



int unsetPair(nPair_t pPair) {

	return attroff(COLOR_PAIR(pPair.id));

}
