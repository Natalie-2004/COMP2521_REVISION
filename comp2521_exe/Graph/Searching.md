## Searching Algorithm

The most common question to be asked in Graph is: Finding A Path

We solve this question via using searching algorithms such as BFS or DFS

### Breath-First Searching (BFS) 广度优先搜索
Data structures used in BFS:
* Visited array
    • To keep track of which vertices have been visited
* Predecessor array
    • To keep track of the predecessor of each vertex
    • The predecessor of v is the vertex from which we reached v
        • i.e., the vertex before v on the path to v
* Queue (Queue.h) -> wk5 lec
    • First-in-first-out data structure
    • Stores unvisited vertices in the order that they should be visited

```
Example:
   A
  / \
 B   C
 |   |
 D   E
```
1. 将起始顶点 A 加入队列。
2. 从队列中取出一个顶点，访问它，并将它的所有未访问的邻居加入队列。此时，队列中有 B 和 C。
3. 下一个从队列中取出的是 B，访问 B，并将其未访问的邻居 D 加入队列。现在队列中是 C 和 D。
4. 继续从队列中取出 C，并将其未访问的邻居 E 加入队列。现在队列是 D 和 E。
5. 最后，访问 D 和 E。这时，队列为空。
Order: A, B, C, D, E

* BFS is O(V + E) when using the adjacency list representation:
* Typical queue implementation has O(1) enqueue and dequeue
* Each vertex is visited at most once ⇒ O(V)
* For each vertex, all of its edges are considered once ⇒ O(E)

```c
void breadthFirst(Graph g, Vertex src) {
  int *visited = calloc(g->nV,sizeof(int));

  // create a queue and add the src to it
  Queue q = newQueue();
  QueueJoin(q, src);

  // while the queue is not empty, remove the FIFO element from the queue and visit it
  while (!QueueEmpty(q)) {
    Vertex y, x = QueueLeave(q);

    if (visited[x]) continue;
    visited[x] = 1;

    // add each of the neighbors to the queue if not already visited
    for (y = 0; y < g->nV; y++) {
      if (!g->edges[x][y]) continue;
      if (!visited[y]) QueueJoin(q,y);
    }
  }
}
```

### Depth-First Searching (DFS) 深度优先搜索
Depth-first search is described recursively as:
* Mark current vertex as visited
    - The first time, this is the starting vertex
* For each neighbour of the current vertex:
    - If it has not been visited:
    - Recursively traverse starting from that vertex
The recursion naturally induces backtracking

```
Example:
   A
  / \
 B   C
 |   |
 D   E
```
1. 访问 A，并将其标记为已访问。
2. 选择 A 的一个未访问的邻居，例如 B，并递归地访问它。
3. 继续选择 B 的一个未访问的邻居，例如 D，并递归地访问它。
4. 当 D 没有未访问的邻居时，回溯到 B。
5. 当 B 也没有其他未访问的邻居时，回溯到 A。
6. 然后选择 A 的另一个未访问的邻居，例如 C，并递归地访问它。
7. 继续选择 C 的一个未访问的邻居，例如 E，并递归地访问它。
Order: A, B, D, C, E

```c
void dfs(Graph g, Vertex src) {
	bool *visited = calloc(g->nV, sizeof(bool));
	printf("DFS visit order: ");
	dfsRec(g, src, visited);
	printf("\n");
	free(visited);
}

static void dfsRec(Graph g, Vertex v, bool *visited) {
	printf("%d ", v);
	visited[v] = true;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			dfsRec(g, w, visited);
		}
	}
}
```

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week05mon-graph-traversal.pdf>

### Hamiltonian path && Hamiltonian circuit

<img width="700" alt="Screen Shot 2023-11-22 at 22 53 36" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/8792c6e9-a14a-4989-935a-647bc6aebe90">

- Hamiltonian path is a path that includes each vertex exactly once.
- Hamiltonian circuit is a cycle that includes each vertex exactly once. 
- Determing whehter a graph has above properties needs to use **DFS**
- Time Complexity:
    * Worst case O(V!)
<img width="442" alt="Screen Shot 2023-11-22 at 23 04 14" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/83f9cb6f-bcfe-4392-b302-9e54bfbe48ce">
<img width="442" alt="Screen Shot 2023-11-22 at 23 04 29" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/0e93e6cd-1143-4f9c-95f5-b6bc8c2d908c">

### Euler path && Euler circuit

<img width="700" alt="Screen Shot 2023-11-22 at 22 54 14" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/0b621de0-3bc6-475a-b225-dde5ed4f5e38">

- Euler path is a path that includes each edge exactly once: 
    * A graph has an Euler path if and only if *exactly zero or two vertices have odd degree*,
    * and all vertices with non-zero degree belong to the *same connected component*.
- Euler circuit is a cycle that includes each edge exactly once: 
    * A graph has an Euler circuit if and only if *every vertex has even degree*,
    * and all vertices with non-zero degree belong to the *same connected component*. 
- Determing whehter a graph has above properties needs to use **DFS**
- Time Complexity for Adj. List:
    * Finding degree of every vertex O(V + E).
    * Checking connectivity -> recursion O(V + E).
    * Worst case in overall O(V + E).
<img width="442" alt="Screen Shot 2023-11-22 at 23 03 37" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/f8fe9047-3d01-442a-b0a6-dca500ebbee4">
<img width="442" alt="Screen Shot 2023-11-22 at 23 03 52" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/9e4838e5-c8f7-4659-a8b0-4803bb13715a">

### Dijkstra Algorithm
- Searching the shortest path in a Graph from src to dest
- Requires Priority Queue
- Steps:
    1. Create a set containing every vertex of the graph
    2. Set all distances to Infinity (INT_MAX) and all predecessors to -1, set the source distance to 0
    3. Visit each vertex (v) from each other current vertex u and:
    4. If the distance of u +  the distance from u->v is less than the distance of v, then:
    5. Update the distance of v
    6. Set the predecessor of v to u

 ```c
dist[]  // array of cost of shortest path from source
pred[]  // array of predecessor in shortest path from source

function Dijkstra(Graph, source):

  vSet = all vertices of Graph

  for each vertex v in Graph:
    dist[v] = INFINITY
    pred[v] = -1

  dist[source] = 0

  while vSet is not empty:
    u = vertex in vSet with min dist[u]
    remove u from vSet

    for each neighbor v of u:
      alt = dist[u] + length(u, v)
      if alt < dist[v]:
        dist[v] = alt
        pred[v] = u

  return dist[], pred[]
```
