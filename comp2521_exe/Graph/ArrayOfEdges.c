// 边集数组

// Implementation of the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph_Basic.h"

#define DEFAULT_CAPACITY 16

typedef struct edge {
	Vertex v;
	Vertex w;
} Edge;

typedef struct graph {
	int nVertices;
	int nEdges;
	Edge *edges;
	int maxE;
} Graph;

static bool validVertex(Graph *g, Vertex v);

static bool validVertex(Graph *g, Vertex v) {
	return (v >= 0 && v < g->nVertices);
}

/**
 * Returns a new graph with nV vertices
 */
Graph *initialGraph(int nVertices) {
	Graph *g = malloc(sizeof(Graph));
	g->nVertices = nVertices;
	g->nEdges = 0;

	g->edges = malloc(DEFAULT_CAPACITY * sizeof(struct edge));
	g->maxE = DEFAULT_CAPACITY;
	return g;
}

/**
 * Frees all memory allocated to a graph
 */
void freeGraph(Graph *g) {
	free(g->edges);
	free(g);
}

/**
 * Returns the number of vertices in a graph
 */
int GraphNumVertices(Graph *g) {
	return g->nVertices;
}

/**
 * Returns the number of edges in a graph
 */
int GraphNumEdges(Graph *g) {
	return g->nEdges;
}

/**
 * Returns true if there is an edge between v and w,
 * and false otherwise
 */
bool GraphIsAdj(Graph *g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	for (int i = 0; i < g->nEdges; i++) {
		if ((g->edges[i].v == v && g->edges[i].w == w) ||
				(g->edges[i].v == w && g->edges[i].w == v)) {
			return true;
		}
	}
	return false;
}

/**
 * Inserts an edge between v and w
 */
void GraphInsertEdge(Graph *g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	if (!GraphIsAdj(g, v, w)) {
		if (g->nEdges == g->maxE) {
			g->maxE *= 2;
			g->edges = realloc(g->edges, g->maxE * sizeof(struct edge));
		}
		g->edges[g->nEdges] = (struct edge){v, w};
		g->nEdges++;
	}
}

/**
 * Removes an edge between v and w
 */
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	for (int i = 0; i < g->nEdges; i++) {
		if ((g->edges[i].v == v && g->edges[i].w == w) ||
				(g->edges[i].v == w && g->edges[i].w == v)) {
			g->edges[i] = g->edges[g->nEdges - 1];
			g->nEdges--;
			return;
		}
	}
}

/**
 * Returns the degree of a vertex
 */
int GraphDegree(Graph *g, Vertex v) {
	assert(validVertex(g, v));

	int degree = 0;
	for (int i = 0; i < g->nEdges; i++) {
		if (g->edges[i].v == v || g->edges[i].w == v) {
			degree++;
		}
	}
	return degree;
}

/**
 * Displays a graph
 */
void GraphShow(Graph *g) {
	printf("Number of vertices: %d\n", g->nVertices);
	printf("Number of edges: %d\n", g->nEdges);
	printf("Edges:\n");
	for (int i = 0; i < g->nEdges; i++) {
		printf("(%d, %d)\n", g->edges[i].v, g->edges[i].w);
	}
	printf("\n");
}

