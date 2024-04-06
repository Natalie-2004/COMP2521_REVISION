
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static bool hasHamiltonianCircuit(Graph g);

static bool dfsHamiltonianCircuit(Graph g, Vertex v, bool *visited, int numVerticesLeft);

int main(void) {
	Graph g = GraphRead(stdin);
	
	printf("Graph:\n");
	GraphShow(g);

	bool answer = hasHamiltonianCircuit(g);
	printf("The graph %s a Hamiltonian Circuit\n",
			answer ? "has" : "does not have");

	GraphFree(g);
}

static bool hasHamiltonianCircuit(Graph g) {
	bool *visited = calloc(g->nV, sizeof(bool));
	bool result = dfsHamiltonianCircuit(g, 0, visited, g->nV);
	free(visited);
	return result;
}

static bool dfsHamiltonianCircuit(Graph g, Vertex v, bool *visited, int numVerticesLeft) {
	visited[v] = true;
	numVerticesLeft--;


    // checking if is a complete circuit
    // the last vertex visited must be directly connected (adjacent) to the first vertex
	if (numVerticesLeft == 0 && GraphIsAdjacent(g, v, 0)) {
		return true;
	}

    // for each neighbour w of v in g
	for (Vertex w = 0; w < g->nV; w++) {
		if (!visited[w] && GraphIsAdjacent(g, v, w)) {
            if (dfsHamiltonianCircuit(g, w, visited, numVerticesLeft)) {
                return true;
            }
        }
	}

	// if can't find any hamiltonian Circuit, set v back to false
	// this is important because if dont unvisited,
	// the graph can't visitng backward to try different Circuit
	visited[v] = false;
	return false;
}

