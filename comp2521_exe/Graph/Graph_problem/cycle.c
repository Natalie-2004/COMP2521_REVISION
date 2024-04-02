
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool hasCycle(Graph g);

static bool dfsHasCycle(Graph g, Vertex v, Vertex prev, bool *visited);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	bool answer = hasCycle(g);
	printf("The graph %s a cycle\n",
			answer ? "contains" : "does not contain");

	GraphFree(g);
}

// perform a dfs, starting from any vertex
// during the dfs, if the curr vertex has an edge to an already visited vertex, 
// then it is a cycle 
static bool hasCycle(Graph g) {
	bool *visited = calloc(g->nV, sizeof(bool));

	for (Vertex v = 0; v < g->nV; v++) {
		// if v is not visited
		if (!visited[v]) {
			bool answer = dfsHasCycle(g, v, v, visited);
			// if there is a cycle, 
			if (answer) {
				free(visited);
				return true;
			}
		}
	}

	free(visited);
	return false;
}

static bool dfsHasCycle(Graph g, Vertex v, Vertex prev, bool *visited) {
	visited[v] = true;
	// printf("Visited %d\n", v);

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		// if the neighbour w is the vertex that it just came from 
		// don't count, skip
		if (w == prev) continue;

		if (visited[w]) {
			// printf("Found a cycle going from %d to %d\n", v, w);
			return true;
		} else {
			if (dfsHasCycle(g, w, v, visited)) {
				return true;
			}
		}
	}

	return false;
}

