#pragma once

#include <stdio.h>
#include <stdlib.h>

struct llNode {
	void *data;
	struct llNode *next;
};

struct linkedList {
	struct llNode *head;
	struct llNode *tail;
};

/*void printLL(struct linkedList *list);*/
void addToLLStart(struct linkedList *list, void *data);
void addToLLEnd(struct linkedList *list, void *data);
void *removeFromLL(struct linkedList *list, void *data);
struct linkedList *createLinkedList();