
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static int *components(Graph g);
static void dfsComponents(Graph g, Vertex v, int *componentOf, int compNo);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	int *componentOf = components(g);
	for (Vertex v = 0; v < g->nV; v++) {
		printf("componentOf[%d]: %d\n", v, componentOf[v]);
	}

	free(componentOf);
	GraphFree(g);
}

// choose a vertex and perform dfs starting at the vertex
	// during the dfs, assign all vertices visited to compoenent 0
// after the dfs, if any vertex has not been assigned to a component,
// perform dfs starting at the vertex
	// during this operation, assign all visited vertices to component 1
// repeat until all vertices are assigned a componenet, increasing the 
// component number each time 
static int *components(Graph g) {
	int *componentOf = malloc(g->nV * sizeof(int));
	for (int i = 0; i < g->nV; i++) {
		componentOf[i] = -1;
	}

	int compNo = 0;
	for (int i = 0; i < g->nV; i++) {
		if (componentOf[i] == -1) {
			dfsComponents(g, i, componentOf, compNo);
			compNo++;
		}
	}

	return componentOf;
}

static void dfsComponents(Graph g, Vertex v, int *componentOf, int compNo) {
	componentOf[v] = compNo;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (componentOf[w] == -1) {
			dfsComponents(g, w, componentOf, compNo);
		}
	}
}

// struct graph {
// 	// num of connected components
// 	int nC;
// 	// componentOf array
// 	int **cc;
// }

// how many connected component are there 
// int numComponents(Graph g) {
// 	return g->nC;
// }

// are v and w in the same connected component
// bool isSameComponent(Graph g, Vertex v, Vertex w) {
// 	return g->cc[v] == g->cc[w];
// }

// is there a path between v and w?
// bool hasPath(Graph g, Vertex v, Vertex w) {
// 	return g->cc[v] == g->cc[w];
// }



