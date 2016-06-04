#include "graph.h"
#include "queue.h"
#include "stack.h"

void
dfsTraversal(struct graph *graph) {
	printf("DFS Traversal\n");
	int n_visited = 0;
	int visited_vertex[MAX_VERTICES];
	struct stack *stack = createStack();
	push(stack, &graph->vertices[0]);
	struct vertex *vertex = NULL;
	while(stack->top != NULL && (n_visited < graph->n_vertices)) {
		vertex = (struct vertex *) pop(stack);
		int i;
		bool isVisited = false;
		for (i = 0; i < n_visited; i++) {
			if (visited_vertex[i] == vertex->data) {
				isVisited = true;
				break;
			}
		}

		if (!isVisited) {
			printf("%d ", vertex->data);
			visited_vertex[n_visited] = vertex->data;
			n_visited++;
			struct linkedList *list = vertex->adjList;
			if(list != NULL && list->head != NULL) {
				struct llNode *node = list->head;
				do {
					push(stack, node->data);
					node = node->next;
				} while (node != NULL);
			}
		}
	}

	printf("\n");
}

void
bfsTraversal(struct graph *graph) {
	printf("BFS Traversal\n");
	int n_visited = 0;
	int visited_vertex[MAX_VERTICES];
	struct queue *queue = createQueue();
	enqueue(queue, &graph->vertices[0]);
	struct vertex *vertex = NULL;
	while((queue->begin != NULL && queue->end != NULL) && (n_visited < graph->n_vertices)) {
		vertex = (struct vertex *) dequeue(queue);
		int i;
		bool isVisited = false;
		for (i = 0; i < n_visited; i++) {
			if (visited_vertex[i] == vertex->data) {
				isVisited = true;
				break;
			}
		}

		if (!isVisited) {
			printf("%d ", vertex->data);
			visited_vertex[n_visited] = vertex->data;
			n_visited++;
			struct linkedList *list = vertex->adjList;
			if(list != NULL && list->head != NULL) {
				struct llNode *node = list->head;
				do {
					enqueue(queue, node->data);
					node = node->next;
				} while (node != NULL);
			}
		}
	}

	printf("\n");
}

void
createVertex(struct vertex *vertex, int data) {
	vertex->data = data;
	vertex->adjList = createLinkedList();
} 

void
addEdge(struct graph *graph, int src, int dst) {
	int i;
	bool srcFound = false;
	bool dstFound = false;
	struct vertex *srcVertex = NULL;
	struct vertex *dstVertex = NULL;
	for (i = 0; i < graph->n_vertices; i++) {
		if (graph->vertices[i].data == src) {
			srcFound = true;
			srcVertex = &graph->vertices[i];
			if (dstFound) {
				break;
			}
		}

		if (graph->vertices[i].data == dst) {
			dstFound = true;
			dstVertex = &graph->vertices[i];
			if (srcFound){
				break;
			}
		}
	}

	if (srcFound && dstFound) {
		addToLLEnd(srcVertex->adjList, dstVertex);
	} else {
		printf("Invalid vertices. src:%d dst:%d\n", srcFound, dstFound);
	}
}

void
addVertex(struct graph *graph, int data) {
	if (graph->n_vertices < MAX_VERTICES) {
		createVertex(&graph->vertices[graph->n_vertices], data);
		graph->n_vertices++;
	} else {
		printf("Vertex limit reached!\n");
	}
}

printAdjList(struct linkedList *list) {
	if(list->head != NULL) {
		struct llNode *node = list->head;
		do {
			struct vertex *vertex = (struct vertex *) node->data;
			printf(" -> %d", vertex->data);
			node = node->next;
		} while (node != NULL);
	}
}

void
printGraph(struct graph *graph) {
	int i;
	for (i = 0; i < graph->n_vertices; i++) {
		printf("%d)", graph->vertices[i].data);
		printAdjList(graph->vertices[i].adjList);
		printf("\n");
	}
}


struct graph *
createGraph() {
	struct graph *graph = malloc(sizeof(struct graph));
	if (graph == NULL) {
		printf("Error allocating memory.\n");
		return NULL;
	}

	graph->n_vertices = 0;

	return graph;
}

void main() {
	struct graph *graph = createGraph();
	addVertex(graph, 1);
	addVertex(graph, 2);
	addVertex(graph, 3);
	addVertex(graph, 4);
	addVertex(graph, 5);

	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 1);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 2);
	addEdge(graph, 3, 1);
	addEdge(graph, 4, 1);
	addEdge(graph, 5, 2);
	addEdge(graph, 5, 3);
	addEdge(graph, 3, 5);
	addEdge(graph, 2, 5);

	printGraph(graph);
	bfsTraversal(graph);
	dfsTraversal(graph);
}