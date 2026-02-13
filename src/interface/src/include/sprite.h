/**
 *	\file		sprite.h
 *	\brief		Header file for sprites handling
 *	\author		VoidScientist
 *	\date		30 january 2026
 *	\version	1.0
 */
#ifndef VOID_SPRITE_H
#define VOID_SPRITE_H

#include <stdio.h>
#include <ncurses.h>
#include "ncolors.h"


#define MAX_SPRITE_WIDTH 512

#ifndef RESOURCE_DIR
#define RESOURCE_DIR "./resources"
#endif

#define VO_LEFT 0
#define VO_CENTER 1
#define VO_RIGHT 2


typedef struct {

	char  *fp;
	char  *data;
	short height;
	short width;

} sprite_t;


int initSprite(sprite_t *sprite, char *fp);

void wdrawSprite(WINDOW *win, sprite_t sprite, int y, int x, int flag);

void drawSprite(sprite_t sprite, int y, int x, int flag);

void drawSpriteColored(sprite_t sprite, int y, int x, int flag, nPair_t colorPair);

void freeSprite(sprite_t *sprite);

#endif /* VOID_SPRITE_H */
