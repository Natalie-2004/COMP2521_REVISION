#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool hasEulerianCircuit(Graph g);
static int degree(Graph g, Vertex v);
static bool eulerConnected(Graph g);
static void dfsRec(Graph g, Vertex v, bool *visited);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	bool answer = hasEulerianCircuit(g);
	printf("The graph %s an Eulerian Circuit\n",
			answer ? "has" : "does not have");

	GraphFree(g);
}

static bool hasEulerianCircuit(Graph g) {
    for (Vertex v = 0; v < g->nV; v++) {
        if (degree(g, v) % 2 == 1) {
            return false;
        }
    }

    return eulerConnected(g);
}

static int degree(Graph g, Vertex v) {
	int deg = 0;
	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		deg++;
	}
	return deg;
}

static bool eulerConnected(Graph g) {
	bool *visited = calloc(g->nV, sizeof(bool));

	for (Vertex v = 0; v < g->nV; v++) {
		if (degree(g, v) > 0) {
			dfsRec(g, v, visited);
			break;
		}
	}

	for (Vertex v = 0; v < g->nV; v++) {
		if (degree(g, v) > 0 && !visited[v]) {
			return false;
		}
	}

	return true;
}

static void dfsRec(Graph g, Vertex v, bool *visited) {
	visited[v] = true;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			dfsRec(g, w, visited);
		}
	}
}
