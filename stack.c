#include "stack.h"

void
push(struct stack *stack, void *data) {
	struct stackNode *temp = malloc(sizeof(struct stackNode));
	temp->data = data;

	if (stack->top == NULL) {
		temp->next = NULL;
	} else {
		temp->next = stack->top;
	}

	stack->top = temp;
	stack->num++;
}

void *pop(struct stack *stack) {
	void *data = NULL;
	if (stack->top != NULL) {
		struct stackNode *temp = stack->top;
		if (temp->next == NULL) {
			data = temp->data;
			free(temp);
			stack->top = NULL;
			stack->num = 0;
			return data;
		} else {
			data = temp->data;
			stack->top = temp->next;
			free(temp);
		}
	} else {
		printf("Stack is Empty.\n");
	}

	return data;
}

struct stack *
createStack() {
	struct stack *stack = malloc(sizeof(struct stack));
	stack->top = NULL;
	stack->num = 0;
	return stack;
}

/* Sample main to use stack
void main() {
	struct stack *stack = createStack();
	push(stack, 5);
	push(stack, 10);
	int dq = destack(stack);
	printf("%d destackd\n", dq);
	dq = destack(stack);
	printf("%d destackd\n", dq);
	printQueue(stack);
}*/
