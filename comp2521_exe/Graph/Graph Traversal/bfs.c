// Data structures used in BFS:
// • Visited array
    // • To keep track of which vertices have been visited
// • Predecessor array
    // • To keep track of the predecessor of each vertex
    // • The predecessor of v is the vertex from which we reached v
        // • i.e., the vertex before v on the path to v
// • Queue
    // • First-in-first-out data structure
    // • Stores unvisited vertices in the order that they should be visited

// BFS is O(V + E) when using the adjacency list representation:
// • Typical queue implementation has O(1) enqueue and dequeue
// • Each vertex is visited at most once ⇒ O(V)
// • For each vertex, all of its edges are considered once ⇒ O(E)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"
#include "Queue.h"

void bfs(Graph g, Vertex src) {
    bool *visited = calloc(g->nV, sizeof(bool));

    int *predecessor = malloc(g->nV * sizeof(int));

    for (int i = 0; i < g->nV; i++) {
        predecessor[i] = -1;
    }

    printf("BSF visit order: %d ", src);
    visited[src] = true;
    QueueEnqueue(q, src);

    while (QueueSize(q) > 0) {
        Vertex v = QueueDequeue(q);

        struct adjNode *curr = g->edges[v];

        for (; curr != NULL; curr = curr->next) {
            Vertex w = curr->w;
            if (!visited[w]) {
                printf("%d ", w);
                visited[w] = true;
                predecessor[w] = v;
                QueueEnqueue(q,w);
            }
        }
    }

    printf("\n");

    for (int i = 0; i < g->nV; i++) {
        printf("Predecessor of %d is %d\n", i, predecessor[i]);
    }

    free(visited);
    free(predecessor);
    QueueFree(q);
}

// finds the shortest path(num of edges) between starting vertex and all other vertices
void frindPathBfs(Graph g, Vertex src, Vertex dest) {
    bool *visited  = calloc(g->nV, sizeof(bool));

    int *predecessor = malloc(g->nV * sizeof(int));

    Queue q = QueueNew();

    for (int  i = 0; i < g->nV; i++) {
        predecessor[i] = -1;
    }

    visited[src] = true;
    QueueEnqueue(q, src);

    while (QueueSize(q) > 0) {
        Vertex v = QueueDequeue(q);

        struct adjNode *curr = g->edges[v];

        for (; curr != NULL; curr = curr->next) {
            Vertex w = curr->w;
            if (!vistied[w]) {
                visited[w] = true;
                predecessor[w] = v;
                QueueEnqueue(q,w);
            }
        }
    }
    

    if (predecessor[dest] != -1) {
        printf("Path from %d to %d: ", src, dest);
        Vertex v = dest;
        while (v != src) {
            printf("%d <- ", v);
            v = predecessor[v];
        }
        printf("%d\n", src);
    } else {
        printf("No path from %d to %d\n", src, dest);
    }

    free(visited);
    free(predecessor);
    Queue(q);
}