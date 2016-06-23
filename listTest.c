#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "dbg.h"

typedef struct form {
	int ID;
	char * name;
} TestForm;

void testInts();

void testStrings();
void freeStrings(void * data);

void testStructs();
void freeStructs(void * data);

int main() {
	
	printf("\n");
	testInts();
	printf("\n\n");
	testStrings();
	printf("\n\n");
	testStructs();
	printf("\n");
	
	return 0;
}


void testInts() {
	
	List intList;
	int nums[3] = { 4, 9, 16 };
	int retrieved = 0;
	
	printf("-----Building new list for ints-----\n");
	newList(&intList, sizeof(int), NULL);
	
	printf("adding %d at head\n", nums[0]);
	addHead(&intList, &nums[0]);
	printf("adding %d at tail\n", nums[1]);
	addTail(&intList, &nums[1]);
	printf("adding %d at tail\n", nums[2]);
	addTail(&intList, &nums[2]);
	printf("-----List successfully populated-----\n");
	
	retrieved = *(int *)retrieveTail(&intList);
	printf("Tail holds: %d\n", retrieved);
	retrieved = *(int *)retrieveHead(&intList);
	printf("Head holds: %d\n", retrieved);
	removeTail(&intList);
	printf("Tail removed\n");
	retrieved = *(int *)retrieveTail(&intList);
	printf("Tail now holds: %d\n", retrieved);
	
	destroyList(&intList);
	printf("-----List destroyed, int tests successful-----\n");
}


void testStrings() {
	
	List strList;
	char * string1 = calloc(6, sizeof(char));
	strcpy(string1, "apple");
	char * string2 = calloc(7, sizeof(char));
	strcpy(string2, "banana");
	char * string3 = calloc(7, sizeof(char));
	strcpy(string3, "cherry");
	char * retrieved = NULL;
	
	printf("-----Building new list for strings-----\n");
	newList(&strList, sizeof(char *), freeStrings);
	
	printf("adding '%s' at head\n", string1);
	addHead(&strList, &string1);
	printf("adding '%s' at tail\n", string2);
	addTail(&strList, &string2);
	printf("adding '%s' at tail\n", string3);
	addTail(&strList, &string3);
	printf("-----List successfully populated-----\n");
	
	retrieved = *(char **)retrieveTail(&strList);
	printf("Tail holds: '%s'\n", retrieved);
	retrieved = *(char **)retrieveHead(&strList);
	printf("Head holds: '%s'\n", retrieved);
	removeTail(&strList);
	printf("Tail removed\n");
	retrieved = *(char **)retrieveTail(&strList);
	printf("Tail now holds: '%s'\n", retrieved);
	
	destroyList(&strList);
	printf("-----List destroyed, string tests successful-----\n");
}


void freeStrings(void * data) {
	
	free(*(char **)data);
}


void testStructs() {
	
	List formList;
	TestForm retrieved = {.ID = 0, .name = NULL};
	
	int ID = 1234;
	char * name = calloc(6, sizeof(char));
	strcpy(name, "Shawn");
	TestForm form1 = {.ID = ID, .name = name};
	
	ID = 5678;
	name = calloc(4, sizeof(char));
	strcpy(name, "Bob");
	TestForm form2 = {.ID = ID, .name = name};
	
	ID = 9000;
	name = calloc(8, sizeof(char));
	strcpy(name, "Richard");
	TestForm form3 = {.ID = ID, .name = name};
	
	printf("-----Building new list for struct (TestForm)-----\n");
	newList(&formList, sizeof(TestForm), freeStructs);
	
	printf("adding '%d: %s' at head\n", form1.ID, form1.name);
	addHead(&formList, &form1);
	printf("adding '%d: %s' at tail\n", form2.ID, form2.name);
	addTail(&formList, &form2);
	printf("adding '%d: %s' at tail\n", form3.ID, form3.name);
	addTail(&formList, &form3);
	printf("-----List successfully populated-----\n");
	
	retrieved = *(TestForm *)retrieveTail(&formList);
	printf("Tail holds: '%d: %s'\n", retrieved.ID, retrieved.name);
	retrieved = *(TestForm *)retrieveHead(&formList);
	printf("Head holds: '%d: %s'\n", retrieved.ID, retrieved.name);
	removeTail(&formList);
	printf("Tail removed\n");
	retrieved = *(TestForm *)retrieveTail(&formList);
	printf("Tail now holds: '%d: %s'\n", retrieved.ID, retrieved.name);

	destroyList(&formList);
	printf("-----List destroyed, struct tests successful-----\n");
}


void freeStructs(void * data) {
	
	TestForm * cast = (TestForm *)data;
	
	free(cast->name);	
}

