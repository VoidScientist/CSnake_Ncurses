/**
 * @file  sllist.c
 * @brief implementation file for singly linked list implementation
 * @author VoidScientist
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sllist.h"


#define NODE_OK  1
#define NODE_ERR 0


typedef struct Node {

	void			*pData;
	struct Node		*pNext;

} node_t;


struct SLList {

	int 	length;
	size_t 	nodeSize;
	node_t 	*pHead;
	node_t  *pTail;

};

/** ######################################################################################## */
/**				 			N O D E   R E L A T E D   F U N C T I O N S 					 */


static node_t *createNode(const void *pData, size_t nodeSize) {

	node_t *pResult = malloc(sizeof *pResult);
	
	if (pResult == NULL) {
		perror("createNode:malloc()");
		return NULL;
 	}

	pResult->pData   = malloc(nodeSize);

	if (pResult->pData == NULL) {
		perror("createNode:malloc()");
		free(pResult);
		return NULL;
	}

	memcpy(pResult->pData, pData, nodeSize);

	pResult->pNext   = NULL;

	return pResult;

}


static int destroyNode(node_t *pNode) {

	if (pNode == NULL) return NODE_ERR;

	free(pNode->pData);
	free(pNode);

	return NODE_OK;

}


static int getNodeData(const node_t *pNode, void *pBuffer, size_t nodeSize) {

	if (pNode == NULL) return NODE_ERR;

	memcpy(pBuffer, pNode->pData, nodeSize);

	return NODE_OK;

}


static int setNodeData(node_t *pNode, const void *pData, size_t nodeSize) {

	if (pNode == NULL) return NODE_ERR;

	memcpy(pNode->pData, pData, nodeSize);

	return NODE_OK;

}


static node_t *getNodeNext(const node_t *pNode) {

	if (pNode == NULL) return NULL;

	return pNode->pNext;

}


static int setNodeNext(node_t *pNode, const node_t *pNext) {

	if (pNode == NULL) return NODE_ERR;

	pNode->pNext = pNext;

	return NODE_OK;	

}


/** ######################################################################################## */
/**				 		S L L I S T   R E L A T E D   F U N C T I O N S 					 */


int SLList_create(SLList_t **ppList, size_t nodeSize) {

	SLList_t *pList = malloc( sizeof( SLList_t ) );

	if (pList == NULL) {
		perror("SLList_create:malloc()");
		return SLLIST_MALLOC_ERR;
	}

	*ppList        = pList;

	pList->length   = 0;
	pList->nodeSize = nodeSize;
	pList->pHead     = NULL;
	pList->pTail     = NULL; 

	return SLLIST_OK;

}


int SLList_destroy(SLList_t *pList) {
	
	node_t *pPrevious;
	node_t *pCurrent;

	if (pList == NULL) return SLLIST_NULL;

	pPrevious = pList->pHead;
	pCurrent  = getNodeNext(pList->pHead);

	while ( pPrevious != NULL ) {

		destroyNode(pPrevious);

		pPrevious = pCurrent;
		pCurrent  = getNodeNext(pCurrent);

	}

	free(pList);

	return SLLIST_OK;

}


int SLList_push(SLList_t *pList, const void *pItem) {

	node_t *pNew;

	if (pList == NULL) return SLLIST_NULL;

	pNew = createNode(pItem, pList->nodeSize);

	if (pNew == NULL) return SLLIST_ERR;

	setNodeNext(pNew, pList->pHead);

	pList->pHead = pNew;

	pList->length++;	

	return SLLIST_OK;

}


int SLList_pop(SLList_t *pList, void *pItem, size_t size) {

	node_t *pNext;

	if (pList == NULL) return SLLIST_NULL;
	if (pList->nodeSize != size) return SLLIST_SIZE_MISMATCH;
	if (pList->pHead == NULL) return SLLIST_HEAD_NULL;

	pNext = getNodeNext(pList->pHead);

	getNodeData(pList->pHead, pItem, size);
	destroyNode(pList->pHead);

	pList->pHead = pNext;

	if (pList->pHead == NULL) {
		pList->pTail = NULL;
	}

	pList->length--;

	return SLLIST_OK;	

}


int SLList_add(SLList_t *pList, const void *pItem) {

	node_t *pNew;

	if (pList == NULL) return SLLIST_NULL;
	
	pNew = createNode(pItem, pList->nodeSize);

	if (pNew == NULL) return SLLIST_ERR;


	if (pList->pHead == NULL) {

		pList->pHead = pNew;

	} else {

		setNodeNext(pList->pTail, pNew);

	}
	
	pList->pTail = pNew;
	
	pList->length++;

	return SLLIST_OK;

}


int SLList_remove(SLList_t *pList, void *pItem, size_t size) {

	return SLList_pop(pList, pItem, size);

}


int SLList_getLength(const SLList_t *pList) {

	if (pList == NULL) return SLLIST_NULL;

	return pList->length; 

}



int SLList_getNodeSize(const SLList_t *pList) {

	if (pList == NULL) return SLLIST_NULL;

	return pList->nodeSize;

}



int SLList_get(const SLList_t *pList, int id, void *pItem, size_t size) {

	node_t *pCurrentNode;

	if (pList == NULL) return SLLIST_NULL;
	if (pList->nodeSize != size) return SLLIST_SIZE_MISMATCH;
	if (pList->pHead == NULL) return SLLIST_HEAD_NULL;

	pCurrentNode = pList->pHead;

	for (int current = 0; current < id; current++) {

		pCurrentNode = getNodeNext(pCurrentNode);

		if (pCurrentNode == NULL) return SLLIST_OUT_OF_BOUNDS;

	}

	getNodeData(pCurrentNode, pItem, size);

	return SLLIST_OK;

}
