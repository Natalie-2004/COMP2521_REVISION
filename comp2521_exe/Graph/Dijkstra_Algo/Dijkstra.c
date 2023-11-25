#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "Graph.h"
#include "GraphPrivate.h"

int minDistance(int dist[], int vSet[], int nV);

// Function to perform Dijkstra's algorithm
void Dijkstra(Graph g, Vertex source, int *dist, int *pred) {
    int nV = GraphNumVertices(g);
    int vSet[nV]; // Set of unvisited vertices

    // Initialize distances, predecessors, and the vertex set
    for (int v = 0; v < nV; v++) {
        dist[v] = INT_MAX;
        pred[v] = -1;
        vSet[v] = 1; // All vertices are initially unvisited
    }
    dist[source] = 0;

    for (int count = 0; count < nV - 1; count++) {
        // Find the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, vSet, nV);

        // Mark the picked vertex as processed
        vSet[u] = 0;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < nV; v++) {
            if (vSet[v] && GraphIsAdjacent(g, u, v) && dist[u] != INT_MAX
                && dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                pred[v] = u;
            }
        }
    }
}

int minDistance(int dist[], int vSet[], int nV) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < nV; v++) {
        if (vSet[v] == 1 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int nV = 5; // Example: Graph with 5 vertices
    Graph g = GraphNew(nV);

    // Example: Adding edges to the graph
    GraphInsertEdge(g, 0, 1);
    GraphInsertEdge(g, 0, 2);
    GraphInsertEdge(g, 1, 2);
    GraphInsertEdge(g, 1, 3);
    GraphInsertEdge(g, 2, 3);
    GraphInsertEdge(g, 3, 4);

    // Assume each edge has a length of 1 for simplicity
    // You need to implement a way to store and retrieve these lengths

    // Vertex 0: Source vertex, distance is 0, no predecessor (-1).
    // Vertex 1: Directly connected to vertex 0, distance is 1, predecessor is 0.
    // Vertex 2: Directly connected to vertex 0, distance is 1, predecessor is 0.
    // Vertex 3: Can be reached through vertex 2 (or 1, but 2 is chosen probably due to the order of processing), so distance is 2, predecessor is 2.
    // Vertex 4: Can be reached through vertex 3, so distance is 3, predecessor is 3.

    int dist[nV], pred[nV];
    Vertex source = 0; // Example: Source vertex is 0
    Dijkstra(g, source, dist, pred);

    // Output the results
    printf("Shortest distances from vertex %d:\n", source);
    for (int i = 0; i < nV; i++) {
        printf("Distance to vertex %d = %d\n", i, dist[i]);
    }

    printf("\nPredecessors in the shortest path:\n");
    for (int i = 0; i < nV; i++) {
        printf("Predecessor of vertex %d = %d\n", i, pred[i]);
    }

    GraphFree(g);
    return 0;
}
