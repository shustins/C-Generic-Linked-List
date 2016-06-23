*******************************************************************************
Generic Linked List Module (C) - Shawn Hustins
*******************************************************************************

1. Description
2. Usage
	2.1 Initialization
	2.2 Addition
	2.3 Removals
	2.4 Retrievals
	2.5 Termination
3. Secure Usage
	3.1 Undefined Behaviour
4. References

****************
1.0 Description:
****************

	This module contains functions for building and using a linked list. It
	allows for any type of data to be stored in each list element making it
	entirely reusable in any project.

**********
2.0 Usage:
**********

	The following section outlines usage of the linked list functions with
	brief examples of each used on a list of primitive and reference types.
	More example usage can be found in linkTest.c, further descriptions of
	functions can be found in linkedList.h.
	
	Struct used in examples:
	typedef struct form {
		int ID;
		char * name;
	} TestForm;

*******************
2.1 Initialization:
*******************

	newList(List * list, int dataSize, freeDataFn function); 
	//list - reference to caller's list
	//dataSize - size in bytes of data stored in each list element
	//function - pointer to a function used to free data referenced by list
	//           elements
	//NOTE: if data is to be dynamically allocated a freeing function must
	//       be created and specified upon initialization (see examples)
	
Primitive Example:
	
	List intlist;
	newList(&intList, sizeof(int), NULL);
		
Reference Example:

	List strList;
	newList(&strList, sizeof(char *), freeStrings);
	
	void freeStrings(void * data) {
		free(*char **)data);
	}
	
Struct Reference Example:

	List formList;
	newList(&formList, sizeof(TestForm), freeStructs);
	
	void freeStructs(void * data) {
		TestForm * cast = (TestForm *)data;
		free(cast->name); 
	}

**************										
2.2 Additions:
**************

	addHead(List * list, void * data);
	addTail(List * list, void * data);
	//list - reference to caller's list
	//data - reference to data being stored in new list element

Primitive Example:

	int num = 0;
	addHead(&intList, &num);
	
Reference Example:

	char * string = calloc(6, sizeof(char));
	strcpy(string, "hello");
	addHead(&strList, &string);
	
Struct Reference Example:

	int ID = 0;
	char * name = calloc(6, sizeof(char));
	strcpy(name, "Shawn");
	TestForm form = {.ID = ID, .name = name};
	addHead(&formList, &form);

*************	
2.3 Removals:
*************

	removeHead(List * list);
	removeTail(List * list);
	//list - reference to caller's list

Primitive Example:

	removeHead(&intList);
	
Reference Example:

	removeHead(&strList);
	
Struct Reference Example:

	removeHead(&formList);
	
***************
2.4 Retrievals:
***************

	retrieveHead(List * list);
	retrieveTail(List * list);
	//list - reference to caller's list
	//NOTE: returns reference to data

Primitive Example:

	int num = *(int *)retrieveHead(&intList);

Reference Example:

	char * string = *(char **)retrieveHead(&strList);
	
Struct Reference Example:

	TestForm form = *(TestForm *)retrieveHead(&formList);
	
****************
2.5 Termination:
****************

	destroyList(List * list);
	//list - reference to caller's list
	
Primitive Example:

	destroyList(&intList);
	
Reference Example:

	destroyList(&strList);
	
Struct Reference Example:

	destroyList(&formList);
	
*****************
3.0 Secure Usage:
*****************

	All functions in this library have built in error handling. To ensure these
	functions are used securely, perform checks on all return values.
	
	Initialization, Addition, Removal & Termination functions:
		return 0 on success
		return -1 on failure
		
	Retrieval functions:
		return void * to data on success
		return NULL on failure
		
	Causes of errors are described further in linkedList.h.
	
************************
3.1 Undefined Behaviour:
************************

	Only use an external freeing function if the list consistently references
	dynamically allocated memory. If the type of list used does not hold 
	references to dynamically allocated memory, NULL should be specified as the
	final parameter of initialization. If a function is specified, removals or
	termination will call this function before freeing the pointer to this 
	memory and the list element itself.

***************
4.0 References:
***************

	dbg.h - taken from:
	Title: Zed's Awesome Debug Macros
	Author: Zed A. Shaw
	Date: 2015
	Version: 1.0
	Availability: Learn C the Hard Way (text Publication)

*******************************************************************************