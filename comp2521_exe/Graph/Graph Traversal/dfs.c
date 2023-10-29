// Depth-first search is described recursively as:
// 1 Mark current vertex as visited
    // -> The first time, this is the starting vertex
// 2 For each neighbour of the current vertex:
    // 1 If it has not been visited:
    // 1 Recursively traverse starting from that vertex
// The recursion naturally induces backtracking

//    A
//   / \
//  B   C
//  |   |
//  D   E
// 
// 1. 访问 A，并将其标记为已访问。
// 2. 选择 A 的一个未访问的邻居，例如 B，并递归地访问它。
// 3. 继续选择 B 的一个未访问的邻居，例如 D，并递归地访问它。
// 4. 当 D 没有未访问的邻居时，回溯到 B。
// 5. 当 B 也没有其他未访问的邻居时，回溯到 A。
// 6. 然后选择 A 的另一个未访问的邻居，例如 C，并递归地访问它。
// 7. 继续选择 C 的一个未访问的邻居，例如 E，并递归地访问它。
// Order: A, B, D, C, E

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

static void dfsRec(Graph g, Vertex v, bool *visited);

void dfs(Graph g, Vertex src) {
	// create and initlaise a array, all ele is initialise to false
	bool *visited = calloc(g->nV, sizeof(bool));
	printf("DFS visit order: ");
	// 从起始顶点开始执行DFS
	dfsRec(g, src, visited);
	printf("\n");
	free(visited);
}

// execute the dfs recursively
static void dfsRec(Graph g, Vertex v, bool *visited) {
	// print the curr vertex
	printf("%d ", v);
	// make the curr vertex as true(visited)
	visited[v] = true;

	// iterate through all neighbours
	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		// if the neighbour is never visited before (false), do dfs recursively from this vertex. 
		if (!visited[w]) {
			dfsRec(g, w, visited);
		}
	}
}
