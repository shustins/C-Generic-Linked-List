#ifndef _list_h_
#define _list_h_

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

typedef void (*freeData)(void *);

typedef struct listNode {
	void * data;			// Pointer to data held by list node
	struct listNode * next;	// Pointer to next element in list
} Node;

typedef struct {
	int dataSize;			// Size of data stored in list
	Node * head; 			// Pointer to list head
	Node * tail;			// Pointer to list tail
	freeData freeFunc;		// Pointer to function that frees any data not
} List;						// directly stored in list node

/*
 * newList
 * IN:	 *list - pointer for caller to hold the list struct
 * 		 dataSize - the size in bytes of each piece of data being held in list
 * 		 function - pointer to the function required to free data not directly
 * 					stored in list node (can be NULL if unnecessary)
 * OUT:	 return 0 on success
 * 		 return -1 on failure (non-natural data size)
 * POST: produces a list including specified assignments
 */
int newList(List * list, int dataSize, freeData function);

/*
 * destroyList
 * IN:	 *list - pointer to an existing list
 * OUT:	 return 0 on success
 * 		 return -1 on failure  (no list specified)
 * POST: frees all memory allocated to nodes of list, calls function to free
 * 		 data if one exists
 */
int destroyList(List * list);

/*
 * addHead
 * IN:	 *list - pointer to an existing list
 * 		 *data - pointer to the data to be stored
 * OUT:  returns 0 on success
 * 		 returns -1 on failure (no list specified, memory error)
 * POST: allocates memory for new node and places it at the head of the list
 */
int addHead(List * list, void * data);

/*
 * addTail
 * IN:	 *list - pointer to an existing list
 * 		 *data - pointer to the data to be stored
 * OUT:  returns 0 on success
 * 		 returns -1 on failure (no list specified, memory error)
 * POST: allocates memory for new node and places it at the tail of the list
 */
int addTail(List * list, void * data);

/*
 * removeHead
 * IN:	 *list - pointer to an existing list
 * OUT:	 returns 0 on success
 * 		 returns -1 on failure (no list specified, empty list)
 * POST: frees all memory allocated for node at head of list, calls function
 * 		 to free data if one exists
 */
int removeHead(List * list);

/*
 * removeTail
 * IN:	 *list - pointer to an existing list
 * OUT:	 returns 0 on success
 * 		 returns -1 on failure (no list specified, empty list)
 * POST: frees all memory allocated for node at tail of list, calls function
 * 		 to free data if one exists
 */
int removeTail(List * list);

/*
 * retrieveHead
 * IN:	 *list - pointer to an existing list
 * OUT:	 returns pointer to data on success
 * 		 returns NULL on failure (no list specified, empty list)
 * POST: returns a pointer to the data stroed at the head of the list
 */
void * retrieveHead(List * list);

/*
 * retrieveTail
 * IN:	 *list - pointer to an existing list
 * OUT:	 returns pointer to data on success
 * 		 returns NULL on failure (no list specified, empty list)
 * POST: returns a pointer to the data stroed at the tail of the list
 */
void * retrieveTail(List * list);

#endif
