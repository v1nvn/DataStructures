#include "linked_list.h"
#include "graph.h"

struct llNode *
createLLNode(void *data) {
	struct llNode *node = malloc(sizeof(struct llNode));
	if (node == NULL) {
		printf(" There was some problem with memory allocation");
		return NULL;
	}

	node->data = data;
	node->next = NULL;
	return node;
}

void addToLLStart(struct linkedList *list, void *data) {
	struct llNode *node = createLLNode(data);
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		node->next = list->head;
		list->head = node;
	}
}


void addToLLEnd(struct linkedList *list, void *data) {
	struct llNode *node = createLLNode(data);

	if (list->tail == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
}

void *removeFromLL(struct linkedList *list, void *data) {
	/*struct llNode *node = list->head;
	while (node != NULL) {
		if (node->data == *data)
	}*/
}

/*void
printLL(struct linkedList *list) {
	if(list->head == NULL) {
		printf("Empty list\n");
	} else {
		struct llNode *node = list->head;
		do {
			printf(" -> %d", node->data);
			node = node->next;
		} while (node != NULL);
		printf(" <- TAIL\n");
	}
}
*/
struct linkedList *createLinkedList() {
	struct linkedList *list = malloc(sizeof(struct linkedList));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/*void main() {
	struct linkedList *list = createLinkedList();
	int a = 5;
	addToLLStart(list, a);
	int b = 6;
	addToLLStart(list, b);
	int c = 7;
	addToLLEnd(list, c);
	printLL(list);

}*/