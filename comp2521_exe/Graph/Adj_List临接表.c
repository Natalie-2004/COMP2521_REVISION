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
    AdjNode **edges;
} Graph;

typedef struct adj_node {
    Vertex v;
    AdjNode *next;
} AdjNode;

static bool validVertex(Graph *g, Vertex v);
static void sortedInsert(AdjNode **head_ptr, AdjNode *new_node);
static AdjNode *create_AdjNode(Vertex v);

// Returns a new graph with nV vertices
Graph *initialGraph(int nVertices) {
    Graph *new_graph = malloc(sizeof(Graph));
    // When allocating memory for the adjacency list array, you should use sizeof(AdjNode *). 
    // This will allocate memory for an array of pointers rather than an array of AdjNode structs.
    new_graph->edges = calloc(nVertices, sizeof(AdjNode *));
    new_graph->nVertices = nVertices;
    new_graph->nEdges = 0;

    return new_graph;
}

// Free all memory
// here takes a pointer to Graph as its argument, instead the Graph itself
void freeGraph(Graph *g) {
    for (int i = 0; i < g->nVertices; i++) {
        AdjNode *curr = g->edges[i];

        while (curr) {
            AdjNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
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

    AdjNode *curr = g->edges[v];
    for (; curr != NULL && w >= curr->v; curr = curr->next) {
        if (curr->v == w) {
            return true;
        }
    }
    
    return false;
}

// Hepler function to create a new AdjNode
static AdjNode *create_AdjNode(Vertex v) {
    AdjNode *new_node = malloc(sizeof(AdjNode));

    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }

    new_node->v = v;
    new_node->next = NULL;
    return new_node;
} 

// Helper function to insert a node in sorted order
static void sortedInsert(AdjNode **head_ptr, AdjNode *new_node) {
    AdjNode *Node;

    if (*head_ptr == NULL || (*head_ptr)->v >= new_node->v) {
        new_node->next = (*head_ptr);
        *head_ptr = new_node;
    } else {
        // Locate the node before the point of insertion
        Node = *head_ptr;
        while (Node->next != NULL && Node->next->v < new_node->v) {
            Node = Node->next;
        }
        new_node->next = Node->next;
        Node->next = new_node;
    }
}

// Insert an edge between v and w
void GraphInsertEdge(Graph *g, Vertex v, Vertex w) {
    assert(validVertex(g, v));
    assert(validVertex(g, w));

    // Make sure adjacency lists should be in ascending order
    // Insert node for vertex w in list of vertex v
    AdjNode *new_node_w = create_AdjNode(w);
    sortedInsert(&(g->edges[v]), new_node_w);

    // Insert node for vertex v in list of vertex w
    AdjNode *new_node_v = create_AdjNode(v);
    sortedInsert(&(g->edges[w]), new_node_v);

    // Increment the edge count as we've added a new edge
    g->nEdges++;
}

// Helper function to remove a vertex from an adjacency list
static void removeVertex(AdjNode **list, Vertex v) {
    AdjNode *prev = NULL;
    AdjNode *curr = *list;
    while (curr != NULL && curr->v != v) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL) {  // vertex is at the head of the list
            *list = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}

// Removes an edge between v and w
void GraphRemoveEdge(Graph *g, Vertex v, Vertex w) {
    assert(validVertex(g, v));
	assert(validVertex(g, w));

    // Remove w from v's adjacency list and v from w's adjacency list
    removeVertex(&(g->edges[v]), w);
    removeVertex(&(g->edges[w]), v);
    
    // Decrement the edge count as we've removed an edge
    g->nEdges--;
}

// Return the degree of a vertex
int GraphDegree(Graph *g, Vertex v) {
    assert(validVertex(g, v));

    int degree = 0;
    AdjNode *curr;
    // initializes curr to the head of the adjacency list(邻接表) of vertex v (g->edges[v])
    for (curr = g->edges[v]; curr != NULL; curr = curr->next) {
        // Each iteration corresponds to traversing to the next adjacent vertex of vertex v, 
        // hence incrementing the count of edges incident to vertex v.
        degree++;
    }
    return degree;
}

// Display a Graph 
void GraphShow(Graph *g) {
    printf("Number of vertices: %d\n", g->nVertices);
    printf("Number of edges: %d\n", g->nEdges);
    printf("Edges:\n");

    for (int i = 0; i < g->nVertices; i++) {
		printf("%2d:", i);
		for (AdjNode *curr = g->edges[i]; curr != NULL; curr = curr->next) {
			printf(" %d", curr->v);
		}
		printf("\n");
	}
	printf("\n");
}

static bool validVertex(Graph *g, Vertex v) {
	return (v >= 0 && v < g->nVertices);
}

