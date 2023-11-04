
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void bfs(Graph g, Vertex v);
void findPathBfs(Graph g, Vertex src, Vertex dest);
void dfs(Graph g, Vertex v);

int main(int argc, char *argv[]) {
	Graph g = GraphNew(9);

	GraphInsertEdge(g, 0, 1);
	GraphInsertEdge(g, 0, 2);
	GraphInsertEdge(g, 0, 3);

	GraphInsertEdge(g, 1, 0);
	GraphInsertEdge(g, 1, 2);

	GraphInsertEdge(g, 2, 0);
	GraphInsertEdge(g, 2, 1);
	GraphInsertEdge(g, 2, 3);
	GraphInsertEdge(g, 2, 6);

	GraphInsertEdge(g, 3, 0);
	GraphInsertEdge(g, 3, 2);
	GraphInsertEdge(g, 3, 4);
	GraphInsertEdge(g, 3, 5);

	GraphInsertEdge(g, 4, 3);
	GraphInsertEdge(g, 4, 5);
	
	GraphInsertEdge(g, 5, 3);
	GraphInsertEdge(g, 5, 4);
	GraphInsertEdge(g, 5, 8);

	GraphInsertEdge(g, 6, 2);
	GraphInsertEdge(g, 6, 7);

	GraphInsertEdge(g, 7, 6);
	GraphInsertEdge(g, 7, 8);

	GraphInsertEdge(g, 8, 5);
	GraphInsertEdge(g, 8, 7);

	bfs(g, 0);

	findPathBfs(g, 0, 8);

	dfs(g, 0);

	GraphFree(g);
}
