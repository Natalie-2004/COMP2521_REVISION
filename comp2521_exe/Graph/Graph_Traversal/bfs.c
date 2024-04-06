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

//    A
//   / \
//  B   C
//  |   |
//  D   E
// 
// 1. 将起始顶点 A 加入队列。
// 2. 从队列中取出一个顶点，访问它，并将它的所有未访问的邻居加入队列。此时，队列中有 B 和 C。
// 3. 下一个从队列中取出的是 B，访问 B，并将其未访问的邻居 D 加入队列。现在队列中是 C 和 D。
// 4. 继续从队列中取出 C，并将其未访问的邻居 E 加入队列。现在队列是 D 和 E。
// 5. 最后，访问 D 和 E。这时，队列为空。
// Order: A, B, C, D, E

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"
#include "Queue.h"

void bfs(Graph g, Vertex src) {
    // create and initialise array
    // calloc -> takes two argument, the num of ele allocate; the sizeof each ele
    // the allocated memory in calloc will be initialise to 0
    // at this example, all ele in the array visited will be 'false'
	bool *visited = calloc(g->nV, sizeof(bool));
    // creaate and initialise predecessor array
	int *predecessor = malloc(g->nV * sizeof(int));
    // create new Queue
	Queue q = QueueNew();

	for (int i = 0; i < g->nV; i++) {
        // means the vertex is not visited yet
		predecessor[i] = -1;
	}

	printf("BFS visit order: %d ", src);
	visited[src] = true;
	QueueEnqueue(q, src);

	while (QueueSize(q) > 0) {
		Vertex v = QueueDequeue(q);
		struct adjNode *curr = g->edges[v];
		for (; curr != NULL; curr = curr->next) {
            // 如果w未被访问，将其加入队列，并更新其前驱为v
            // =对于当前访问的顶点 v，你会检查它的每一个邻居 w。
            // =如果 w 尚未被访问，你将其加入队列以供稍后访问，并记住它是从 v 被发现的（v 是 w 的前驱）。
			Vertex w = curr->v;
			if (!visited[w]) {
				printf("%d ", w);
				visited[w] = true;
				predecessor[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}

	printf("\n");
	for (int i = 0; i < g->nV; i++) {
        // 打印每个顶点的前驱
		printf("Predecessor of %d is %d\n", i, predecessor[i]);
	}

	free(visited);
	free(predecessor);
	QueueFree(q);
}

// from the smallest path from src to dest
void findPathBfs(Graph g, Vertex src, Vertex dest) {
    // create and initalise array and predecessor array
	bool *visited = calloc(g->nV, sizeof(bool));
	int *predecessor = malloc(g->nV * sizeof(int));
	Queue q = QueueNew();

	for (int i = 0; i < g->nV; i++) {
		predecessor[i] = -1;
	}

	visited[src] = true;
	QueueEnqueue(q, src);

	while (QueueSize(q) > 0) {
		Vertex v = QueueDequeue(q);
		struct adjNode *curr = g->edges[v];
		for (; curr != NULL; curr = curr->next) {
			Vertex w = curr->v;
			if (!visited[w]) {
				visited[w] = true;
				predecessor[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}

    // print path from from src to the dest 
	if (predecessor[dest] != -1) {
		printf("Path from %d to %d: ", src, dest);
		Vertex v = dest;
		while (v != src) {
			printf("%d <- ", v);
			v = predecessor[v];
		}
		printf("%d\n", src);
	} else {
        // if no path
		printf("No path from %d to %d\n", src, dest);
	}

	free(visited);
	free(predecessor);
	QueueFree(q);
}
