// Implementation of the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph_Basic.h"

typedef struct graph {
    int nVertices;
    int nEdges;
    bool **edges;
} Graph;

static bool validVertex(Graph *g, Vertex v);

static bool validVertex(Graph *g, Vertex v) {
	return (v >= 0 && v < g->nVertices);
}

// Returns a new grapg with nVertices
Graph *initialGraph(int nVertices) {
    Graph *new_graph = malloc(sizeof(Graph));

    new_graph->nVertices = nVertices;
    new_graph->nEdges = 0;

    new_graph->edges = malloc(nVertices * sizeof(bool *));
    
    for (int i = 0; i < nVertices; i++) {
        new_graph->edges[i] = malloc(nVertices * sizeof(Graph));

        for (int j = 0; j < nVertices; j++) {
            new_graph->edges[i][j] = 0;
        }
    }

    return new_graph;
}

// Free all memory allocated to Graph
void freeGraph(Graph *g) {
    for (int i = 0; i < g->nVertices; i++) {
        // deallocate memory allocated to each adjacency list of vertices
        free(g->edges[i]);
    }
    // deallocates the memory allocated to the array of pointers that point to the adjacency lists of vertices
    // g->edges is the first ele in the array
    free(g->edges);
    free(g);
}

// Returns the number of vertices in a graph
int GraphNumVertices(Graph *g) {
	return g->nVertices;
}

// Returns the number of edges in a graph
int GraphNumEdges(Graph *g) {
    return g->nEdges;
}

// Returns true if there is an edge between v and w,
// and false otherwise
bool GraphIsAdj(Graph *g, Vertex v, Vertex w) {
    assert(validVertex(g, v));
    assert(validVertex(g, w));

    return g->edges[v][w];
}

// Inserts an edge between v and w
void GraphInsertEdge(Graph *g, Vertex v, Vertex w) {
    assert(validVertex(g, v));
    assert(validVertex(g, w));

    if (g->edges[v][w]) {
        g->edges[v][w] = 1;
        g->edges[w][v] = 1;
        g->nEdges++;
    }
}

// Remove an edge between v and w
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w) {
    assert(validVertex(g, v));
    assert(validVertex(g, w));

    if (g->edges[v][w]) {
        g->edges[v][w] = 0;
        g->edges[w][v] = 0;
        g->nEdges--;
    }
}

// Return the degree of a vertex
int GraphDegree(Graph *g, Vertex v) {
    assert(validVertex(g, v));

    int degree = 0;
    for (Vertex w = 0; w < g->nVertices; w++) {
        if (g->edges[v][w]) {
            degree++;
        }
    }
    return degree;
}

// Display a graph
void GraphShow(Graph *g) {
    printf("Number of vertices: %d\n", g->nVertices);
	printf("Number of edges: %d\n", g->nEdges);
	printf("Edges:\n");
	for (int i = 0; i < g->nVertices; i++) {
		printf("%2d:", i);
		for (int j = 0; j < g->nVertices; j++) {
			if (g->edges[i][j]) {
				printf(" %d", j);
			}
		}
		printf("\n");
	}
	printf("\n");
}