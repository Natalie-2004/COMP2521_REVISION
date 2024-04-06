#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Implemented using Adjacency Matrix, not Adjacency List
#include "Graph.h"
#include "Pq.h"

static Graph KruskalMst(Graph g);
static Pq makeEdgesPq(Graph g);
static bool hasPath(Graph g, Vertex src, Vertex dest);
static bool doHasPath(Graph g, Vertex v, Vertex dest, bool *visited);

// GraphNumVertices && GraphNUmEdges replaces g->nV && mst->nE, 
// as commonly user can't access the codes inside ADT

// Constructing a MST using kruskal algo
static Graph KruskalMst(Graph g) {
    // mst = empty graph with V vertices
    Graph mst = GraphNew(GraphNumVertices(g));
    // sortedEdfes = sort edges of G by weight 
    // -> by creating new Pq of edges from Graph g
    Pq pq = makeEdgesPq(g);

    // iterate over the sorted edges 
    while (GraphNumEdges(mst) < g->nV - 1 && !PqIsEmpty(pq)) {
        // extract the smallest weighted path and stored at e
        struct edge e = PqExtract(pq);

        // for each edge, check if adding the edge to the MST doesn't create a cycle
        if (!hasPath(mst, e.v, e.w)) {
            // add e to mst
            GraphInsertEdge(mst, e);
        }
    }

    PqFree(pq);
    // if mst has v - 1 edges, found and return 
    if (GraphNumEdges(mst) == GraphNumVertices(g) - 1) {
        return mst;
    } else {
        // cant find mst
        GraphFree(mst);
        return NULL;
    }
}

// create Pq for all edges of the graph to it, and sorted by weight
static Pq makeEdgesPq(Graph g) {
    Pq pq = PqNew();

    // insert all edges from the graph into the Pq
    for (int i = 0; i < GraphNumVertices(g); i++) {
        for (int j = j + 1; j < GraphNumVertices(g); j++) {
            // if there's weighting between edges i and j
            if (GraphIsAdjacent(g, i, j) != 0.0) {
                // using compound literal to create an unname struct to be insert directly 
                PqInsert(pq, (struct edge) {i, j, g->edges[i][j]});

                // alternative:
                // struct edge e;  
                // e.v = i;        
                // e.w = j;        
                // e.weight = g->edges[i][j];  
                // PqInsert(pq, e); 
            }
        }
    }

    return pq;
}

// check if there's already a path between two vertices -> detect cycle
static bool hasPath(Graph g, Vertex src, Vertex dest) {
    bool *visited = calloc(g->nV, sizeof(bool));
    assert(visited != NULL);

    bool res = doHasPath(g, src, dest, visited);

    free(visited);
    return res;
}

// perform dfs search 
static bool doHasPath(Graph g, Vertex v, Vertex dest, bool *visited) {
    visited[v] = true;

    if (v == dest) {
        return true;
    }

    for (int w = 0; w < GraphNumVertices(g); w++) {
        if (GraphIsAdjacent(g, v, w) > 0.0 && !visited[w]) {
            if (doHasPath(g, w, dest, visited)) {
                return true;
            }
        }
    }

    return false;

}