/**
 *	\file		game.h
 *	\brief		Snake Game logic header file
 *	\author		VoidScientist
 *	\version	1.0
 */

#ifndef VOID_SNAKE_H
#define VOID_SNAKE_H

#include <sllist.h>

#define SNAKE_OK 			0
#define SNAKE_CANNOT_START 	-1

typedef struct {

	int width;
	int height;
	int appleAmount;

} gameParams_t;



int 	startGame	(gameParams_t *pParams);

int 	nextFrame	();

int 	handleInput	(int keycode);

int 	endGame		();


SLList_t *getSnake	();

SLList_t *getApples	();


#endif /* VOID_SNAKE */
