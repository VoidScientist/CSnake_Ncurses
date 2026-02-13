/**
 *	\file		ncolors.h
 *	\brief		Header for utility functions to work with colors
 *	\author		VoidScientist
 *	\version	1.0
 */
#ifndef VOID_NCOLORS
#define VOID_NCOLORS

#include <ncurses.h>


typedef struct {

	NCURSES_PAIRS_T 	id;
	NCURSES_COLOR_T 	fg;
	NCURSES_COLOR_T 	bg;

} nPair_t;



int initPair(nPair_t *pPair, NCURSES_COLOR_T fg, NCURSES_COLOR_T bg);

int setPair(nPair_t pPair);

int unsetPair(nPair_t pPair);


#endif /* VOID_NCOLORS */
