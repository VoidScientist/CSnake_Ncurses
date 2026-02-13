/**
 *	\file		game.c
 *	\brief		Snake Game logic implementation file
 *	\author		VoidScientist
 *	\version	1.0
 */

#include <sllist.h>

#include "game.h"
#include "vector2.h"

typedef struct {

	SLList 		*pSnake;
	SLList 		*pApples;

	int			width;
	int 		height;
	int     	appleAmount;	

	vector2_t	direction;

} gameInfo_t;



static gameInfo_t 	gameData;
static int 			started = 0;



int startGame(gameParams_t *pParams) {

	vector2_t startPosition;

	if (started) return SNAKE_CANNOT_START;

	gameData.width			= pParams->width;
	gameData.height			= pParams->height;

	startPosition 			= createVector2(gameData.width / 2, gameData.height / 2);

	gameData.appleAmount 	= pParams->appleAmount;

	gameData.direction		= createVector2(0, 0);

	SLList_create(&gameData.pSnake, sizeof(vector2_t));
	SLList_create(&gameData.pApples, sizeof(vector2_t));

	SLList_add(gameData.pSnake, &startPosition);

	// SHOULD BE SPAWNING APPLE HERE => DO A HELPER FUNCTION

	started = 1;

	return SNAKE_OK; 

}


int nextFrame() {
	
	vector2_t headPosition = 
	vector2_t nextPosition = addVector2(&headPosition, &gameData.direction);

		


}
