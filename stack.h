#pragma once

#include <stdio.h>
#include <stdlib.h>

struct stackNode {
	void *data;
	struct stackNode *next;
};

struct stack {
	struct stackNode *top;
	int num;
};

void push(struct stack *stack, void *data);
void *pop(struct stack *stack);
struct stack *createStack();
