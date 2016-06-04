#include "queue.h"

void
enqueue(struct queue *queue, void *data) {
	struct queueNode *temp = malloc(sizeof(struct queueNode));
	temp->data = data;

	if (queue->begin == NULL && queue->end == NULL) {
		temp->next = NULL;
		queue->end = temp;
	} else {
		temp->next = queue->begin;
	}

	queue->begin = temp;  
}

void *dequeue(struct queue *queue) {
	void *data = NULL;
	if (queue->begin != NULL && queue->end != NULL) {
		struct queueNode *temp = queue->begin;
		if (temp->next == NULL) {
			data = temp->data;
			free(temp);
			queue->begin = NULL;
			queue->end = NULL;
			return data;
		}

		while (temp->next->next != NULL) {
			temp = temp->next;
		}

		data = temp->next->data;
		free(temp->next);
		temp->next = NULL;
	}
	
	return data;
}

struct queue *
createQueue() {
	struct queue *queue = malloc(sizeof(struct queue));
	queue->begin = NULL;
	queue->end = NULL;
	return queue;
}

/* Sample main to use queue
void main() {
	struct queue *queue = createQueue();
	enqueue(queue, 5);
	enqueue(queue, 10);
	int dq = dequeue(queue);
	printf("%d dequeued\n", dq);
	dq = dequeue(queue);
	printf("%d dequeued\n", dq);
	printQueue(queue);
}*/
