// Depth-first search is described recursively as:
// 1 Mark current vertex as visited
    // -> The first time, this is the starting vertex
// 2 For each neighbour of the current vertex:
    // 1 If it has not been visited:
    // 1 Recursively traverse starting from that vertex
// The recursion naturally induces backtracking

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static void dfsRec(Graph g, Vertex v, bool *visited);

void dfs(Graph g, Vertex src) {
	bool *visited = calloc(g->nV, sizeof(bool));
	printf("DFS visit order: ");
	dfsRec(g, src, visited);
	printf("\n");
	free(visited);
}

static void dfsRec(Graph g, Vertex v, bool *visited) {
	printf("%d ", v);
	visited[v] = true;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			dfsRec(g, w, visited);
		}
	}
}
