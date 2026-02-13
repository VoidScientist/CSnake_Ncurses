/**
 *	\file		sprite.c
 *	\brief		Implementation file for sprites handling
 *	\author		VoidScientist
 *	\date		30 january 2026
 *	\version	1.0
 */
#include <stdlib.h>
#include <ncurses.h>
#include "sprite.h"


#define INITIAL_BUFFER_SIZE 128


int measureSprite(sprite_t *sprite);
int cacheSprite(sprite_t *);



int measureSprite(sprite_t *sprite) {

	char  p;

	int   i         = 0;
	short lineWidth = 0;
	short width     = 0;
	short height    = 0;


	while ( ( p = sprite->data[i++] ) != '\0') {

		if (p == '\n') {
			lineWidth = 0;
			height++;
			continue;
		}

		lineWidth++;

		if (lineWidth > width) {
				width = lineWidth;
		}

	}

	sprite->width = width;
	sprite->height = height;

	return 0;

}


int cacheSprite(sprite_t *sprite) {

	FILE *pFd;
	int   current;

	int   written   = 0;
	int   buffSize = INITIAL_BUFFER_SIZE;
	char *pBuffer   = malloc(INITIAL_BUFFER_SIZE);
	

	if ( ( pFd = fopen(sprite->fp, "r") ) == NULL) {
		perror("fopen()");
		return -1;
	}


	while ( ( current = fgetc(pFd) ) != EOF ) {

		if (written >= buffSize) {

			buffSize *= 2;
			pBuffer   = realloc(pBuffer, buffSize); 

		}
		
		pBuffer[written++] = current;

	}

	fclose(pFd);

	pBuffer              = realloc(pBuffer, written + 1);
	pBuffer[written] = '\0';		

	sprite->data         = pBuffer;


	return written;

}


int initSprite(sprite_t *sprite, char *fp) {

	sprite->fp = fp;

	if (cacheSprite(sprite) == 0)
		return -1;

	if (measureSprite(sprite) == -1) 
		return -1;

	return 0;

}


void wdrawSprite(WINDOW *win, sprite_t sprite, int y, int x, int flag) {

	char current;
	int  startX, currentY, currentX;

	int  i = 0;

	switch (flag) {


		case VO_RIGHT:
			startX = x;
			break;

		case VO_CENTER:
			startX = x - (sprite.width) / 2;
			break;

		case VO_LEFT:
		default:
			startX = x - sprite.width;
			break;

	}

	if (startX < 0) 
		startX = 0;

	currentY   = y;
	currentX = startX;

	while ( ( current = sprite.data[i++] ) != '\0') { 

		if (current == '\n') {
			currentX = startX;
			currentY++;
			continue;
		}

		mvwaddch(win, currentY, currentX++, current);
	
	}
	

}


void drawSprite(sprite_t sprite, int y, int x, int flag) {

		wdrawSprite(stdscr, sprite, y, x, flag);

}


void drawSpriteColored(sprite_t sprite, int y, int x, int flag, nPair_t colorPair) {

	setPair(colorPair);

	drawSprite(sprite, y, x, flag);

	unsetPair(colorPair);

}



void freeSprite(sprite_t *pSprite) {

	free(pSprite->data);

}
