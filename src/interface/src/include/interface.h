/**
 *	\file		interface.h	
 *	\brief		Header file for game interfaces 
 *	\author		VoidScientist
 *	\version	1.0
 */

#ifndef VOID_INTERFACE
#define VOID_INTERFACE

typedef enum {NONE, QUIT_GAME, START_GAME} menuResult_t;


menuResult_t startPlayerMenu(void);

#endif /* VOID_INTERFACE */
