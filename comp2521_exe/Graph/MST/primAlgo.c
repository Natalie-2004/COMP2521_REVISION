#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Implemented using Adjacency Matrix, not Adjacency List
#include "Graph.h"
#include "Pq.h"

static Graph PrimMst(Graph g) {
    Graph mst = GraphNew(GraphNumVertices(g));
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    assert(visited != NULL);

    Pq pq = PqNew();

    // start from vertex 0
    visited[0] = true;

    // Add all edges from vertex 0 to the Pq
    for (int i = 0; i < GraphNumVertices(g); i++) {
        if (GraphIsAdjacent(g, 0, i) != 0.0) {
            PqInsert(pq, (struct edge) {0, i, g->edges[0][i]});
        }
    }

    // While the MST does not have V-1 edges and the priority queue is not empty
    while (GraphNumEdges(mst) < GraphNumVertices(g) - 1 && !PqIsEmpty) {
        struct edge e = PqExtract(pq);

        // If the destination vertex of the edge is not visited, 
        // it is a valid edge to add to the MST
        if (!visited[e.w]) {
            GraphInsertEdge(mst, e);
            int v = e.w;
            visited[v] = true;

            // Add all new candidate edges from the newly visited vertex to the Pq
            for (int j = 0; j < GraphNumVertices(g); j++) {
                if (GraphIsAdjacent(g, v, j) != 0.0 && !visited[j]) {
                    PqInsert(pq, (struct edge) {v, j, g->edges[v][j]});
                }
            }
        }
    }

    PqFree(pq);
    free(visited);

    if (GraphNumEdges(mst) == GraphNumVertices(g) - 1) {
        return mst;
    } else {
        GraphFree(mst);
        return NULL;
    }
}