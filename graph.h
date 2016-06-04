#pragma once

#include "linked_list.h"
#include <stddef.h>
#include <stdbool.h>

#define MAX_VERTICES 1024

struct vertex {
	int data;
	struct linkedList *adjList;
};

struct graph {
	int n_vertices;
	struct vertex vertices[MAX_VERTICES];
};

struct graph *createGraph();