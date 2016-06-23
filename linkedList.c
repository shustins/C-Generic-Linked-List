#include "linkedList.h"

int newList(List * list, int dataSize, freeData function) {
	
	check(dataSize > 0, "Invalid data size specified.");
	
	list->dataSize = dataSize;
	list->head = NULL;
	list->tail = NULL;
	list->freeFunc = function;
	
	return 0;
	
error:
	return -1;
}


int destroyList(List * list) {
	
	check(list, "No list specified.");
	while(list->head) {
		Node * current = list->head;
		list->head = current->next;
		if (list->freeFunc)
			list->freeFunc(current->data);
		free(current->data);
		free(current);
	}
	
	return 0;
	
error:
	return -1;
}


int addHead(List * list, void * data) {
	
	check(list, "No list specified.");
	
	Node * node = calloc(1, sizeof(Node));
	check(node, "Memory error.");
	
	node->data = calloc(1, list->dataSize);
	check(node->data, "Memory error.");
	
	memcpy(node->data, data, list->dataSize);
	
	if (!list->tail)
		list->tail = node;
	
	node->next = list->head;
	list->head = node;
	
	return 0;
	
error:
	return -1;
}


int addTail(List * list, void * data) {
	
	check(list, "No list specified.");
	
	Node * node = calloc(1, sizeof(Node));
	check(node, "Memory error.");
	
	node->data = calloc(1, list->dataSize);
	check(node->data, "Memory error.");
	
	memcpy(node->data, data, list->dataSize);
	node->next = NULL;
	
	if (!list->head)
		list->head = node;
	
	
	if (list->tail)
		list->tail->next = node;
	
	list->tail = node;
	
	return 0;
	
error:
	return -1;
}
	

int removeHead(List * list) {
	
	check(list, "No list specified.");
	check(list->head, "List is empty.");
	
	Node * remove = list->head;
	list->head = list->head->next;
	
	if (list->freeFunc)
		list->freeFunc(remove->data);
	free(remove->data);
	free(remove);
	
	return 0;

error:
	return -1;
}


int removeTail(List * list) {
	
	check(list, "No list specified.");
	check(list->tail, "List is empty.");
	
	Node * temp = list->head;
	while (temp->next != list->tail) {
		temp = temp->next;
	}
	
	if (list->freeFunc)
		list->freeFunc(list->tail->data);
	free(list->tail->data);
	free(list->tail);
	
	list->tail = temp;
	list->tail->next = NULL;
	
	return 0;
	
error:
	return -1;
}


void * retrieveHead(List * list) {
	
	check(list, "No list specified.");
	check(list->head, "List is empty.");
	
	return list->head->data;

error:
	return NULL;
}


void * retrieveTail(List * list) {
	
	check(list, "No list specified.");
	check(list->tail, "List is empty.");
	
	return list->tail->data;
	
error:
	return NULL;
}
