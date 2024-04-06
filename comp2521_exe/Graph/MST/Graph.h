// Interface to the Undirected Weighted Graph ADT
// - Vertices are identified by integers between 0 and nV - 1,
//   where nV is the number of vertices in the graph
// - Weights are doubles and must be positive
// - Self-loops are not allowed

// !!! DO NOT MODIFY THIS FILE !!!

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

typedef struct graph *Graph;

typedef int Vertex;

// DO NOT modify this struct
struct graph {
    int nV;         // #vertices
    int nE;         // #edges
    double **edges; // adjacency matrix storing positive weights
                    // 0 if nodes not adjacent
};

// edges are pairs of vertices (end-points)
struct edge {
    Vertex v;
    Vertex w;
    double weight;
};

/**
 * Creates a graph with `nV` vertices and no edges
 */
Graph GraphNew(int nV);

/**
 * Frees all memory allocated to the given graph
 */
void GraphFree(Graph g);

/**
 * Returns the number of vertices in the graph
 */
int GraphNumVertices(Graph g);

/**
 * Returns the number of edges in the graph
 */
int GraphNumEdges(Graph g) ;

/**
 * Inserts an edge into a graph. Does nothing if there is already an
 * edge between `e.v` and `e.w`. Returns true if successful, and false
 * if there was already an edge.
 */
bool GraphInsertEdge(Graph g, struct edge e);

/**
 * Removes an edge from a graph. Returns true if successful, and false
 * if the edge did not exist.
 */
bool GraphRemoveEdge(Graph g, Vertex v, Vertex w);

/**
 * Returns the weight of the edge between `v` and `w` if it exists, or
 * 0.0 otherwise
 */
double GraphIsAdjacent(Graph g, Vertex v, Vertex w);

/**
 * Displays information about the graph
 */
void GraphShow(Graph g);

#endif
