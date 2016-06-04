#pragma once

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
	void *data;
	struct queueNode *next;
};

struct queue {
	struct queueNode *begin;
	struct queueNode *end;
};

void enqueue(struct queue *queue, void *data);
void *dequeue(struct queue *queue);
struct queue *createQueue();
