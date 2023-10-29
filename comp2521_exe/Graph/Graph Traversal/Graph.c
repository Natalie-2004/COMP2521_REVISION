// Implementation of the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

// structs imported from GraphPrivate

// struct graph {
// 	int nV;
// 	int nE;
// 	struct adjNode **edges;
// };

// struct adjNode {
// 	Vertex v;
// 	struct adjNode *next;
// };

static bool validVertex(Graph g, Vertex v);

static bool doFindEdge(struct adjNode *list, Vertex v);
static struct adjNode *doInsertEdge(struct adjNode *list, Vertex v);

// Returns a new graph with nV vertices
Graph GraphNew(int nV) {
    Graph g = malloc (sizeof(struct Graph));
    g->nV = nV;
    g->nE = 0;
    g->edges = calloc(nV, sizeof(struct adjNode *));

    return g;
}

// Frees all memory allocated to a graph
void GraphFree(Graph g) {
    for (int i = 0; i < g->nV; i++) {
        struct adjNode *curr = g->edges[i];

        while (curr != NULL) {
            struct adjNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// Return the num of vertices in a graph
int GraphNumVercies(Graph g) {
    return g->nV;
}

// Return the num of Edges in a graph 
int GraphNumEdges(Graph g) {
    return g->nE;
}

// Returns true if there's an edge between v and w, otherwise false
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w) {
    assert(validVertex(g,v));
    assert(validVertex(g,w));

    return doFindEdge(g->edges[v], w);
}

static bool doFindEdge(struct adjNode *list, Vertex v) {
    if (list == NULL || v < list->v) {
        return false;
    } else if (v == list->v) {
        return true;
    } else {
        return doFindEdge(list->next, v);
    }
}

// Inserts an edge between v and w
void GraphInsertEdge(Graph g, Vertex v, Vertex w) {
    assert(validVertex(g, v));
    assert(validVertex(g, w));

    if (!GraphIsAdjacent(g,v,w)) {
        g->edges[v] = doInsertEdge(g->edges[v], w);
        g->edges[v] = doInsertEdge(g->edges[w], v);
        g->nE++;
    }
}

static struct adjNode *doInsertEdge(struct adjNode *list, Vertex v) {
    if (list == NULL || v < list->v) {
        struct adjNode *n = malloc(sizeof(struct adjNode));
        n->v = v;
        n->next = list;
        return n;
    } else if (v == list->v) {
        return list;
    } else {
        list->next = doInsertEdge(list->next, v);
        return list;
    }
}

// Display a graph 
void GraphShow (Graph g) {
    printf("Number of vertices: %d\n", g->nV);
	printf("Number of edges: %d\n", g->nE);
	printf("Edges:\n");
	for (int i = 0; i < g->nV; i++) {
		printf("%2d:", i);
		for (struct adjNode *curr = g->edges[i]; curr != NULL; curr = curr->next) {
			printf(" %d", curr->v);
		}
		printf("\n");
	}
	printf("\n");
}