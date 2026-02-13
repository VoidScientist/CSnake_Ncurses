/**
 * @file  sllist.h
 * @brief header file for singly linked list implementation
 * @author VoidScientist
 */

#ifndef VOID_SLLIST_H
#define VOID_SLLIST_H

/** ######################################################################################## */
/**                       I N C L U D E S                                                    */

#include <stddef.h> 

/** ######################################################################################## */
/**                       C O N S T A N T S                                                  */

#define SLLIST_OK         		1
#define SLLIST_ERR       		-1
#define SLLIST_NULL      		-2  
#define SLLIST_HEAD_NULL 		-3
#define SLLIST_OUT_OF_BOUNDS	-4
#define SLLIST_SIZE_MISMATCH	-5
#define SLLIST_MALLOC_ERR		-6

/** ######################################################################################## */
/**                       T Y P E D E F S                                                    */

typedef struct SLList SLList_t;

/** ######################################################################################## */
/**                       C O N S T R U C T O R  /  D E S T R U C T O R                      */

/**
 * @brief creates a singly linked list with nodes containing
 * 		  values of size `nodeSize`
 *
 * @return SLLIST_OK in case of success.
 *
 */
int SLList_create		(SLList_t **ppList, size_t nodeSize);
/**
 * @brief destroys a singly linked list and free its nodes.
 *
 * @return SLLIST_OK in case of success.
 *
 */
int SLList_destroy		(SLList_t *pList);

/** ######################################################################################## */
/**                       L I F O   F U N C T I O N S                                        */

int SLList_push			(SLList_t *pList, const void *pItem);
int SLList_pop			(SLList_t *pList, void *pItem, size_t size);

/** ######################################################################################## */
/**                       F I F O    F U N C T I O N S                                       */

int SLList_add			(SLList_t *pList, const void *pItem);
int SLList_remove		(SLList_t *pList, void *pItem, size_t size);

/** ######################################################################################## */
/**                       G E T T E R    F U N C T I O N S                                   */

int SLList_getLength	(const SLList_t *pList);
int SLList_getNodeSize	(const SLList_t *pList);

int SLList_get			(const SLList_t *pList, int id, void *pItem, size_t size);



#endif /* VOID_SLLIST_H */
