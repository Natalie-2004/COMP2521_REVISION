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

<img width="700" alt="Screenshot 2024-03-26 at 12 58 55 pm" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/b3310713-5691-411b-a955-a778d052e1ad">

```c
void breadthFirst(Graph g, Vertex src) {
  	int *predecessor = malloc(g->nV * sizeof(int));

  	// create a queue and add the src to it
  	Queue q = newQueue();

	for (int i = 0; i < g->nV; i++) {
		predecessor[i] = -1;
	}
	
	// set the starting point's predecessor to be marked 
	predecessor[src] = src;
	QueueEnqueue(q, src);

  	while (QueueSize(q) > 0) {
		// dequeue vertex v
		Vertex v = QueueDequeue(q);

		// printf("%d ", v);

		// explore v and its neighbours
		struct adjNode *curr = g->edges[v];
		for (; curr != NULL; curr = curr->next) {
				Vertex w = curr->v;
				// if this is not yet being visited
				if (predecessor[w] == -1) {
					predecessor[w] = v;
					QueueEnqueue(q,w);
		}
   	}
   	printf("\n")
   	free(predecessor);
   	QueueFree(q);
}
```

```c
findPathBfs(Graph g, Vertex src, Vertex dest) {
	int *predecessor = malloc(g->nV * sizeof(int));
	Queue q = QueueNew();

	for (int i = 0; i < g->nV; i++) {
		predecessor[i] = -1;
	}

	predecessor[src] = src;
	QueueEnqueue(q, src);

	while (QueueSize(q) > 0) {
		// dequeue vertex v
		Vertex v = QueueDequeue(q);

		// explore v
		struct adjNode *curr = g->edges[v];
		for (; curr != NULL; curr = curr->next) {
			Vertex w = curr->v;

			// if w hasn't been visited
			if (predecessor[w] == -1) {
				predecessor[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}

	if (predecessor[dest] != -1) {
		printf("Path from %d to %d: ", src, dest);

		Vertex curr = dest;
		while (curr != dest) {
			printf("%d <- ", curr);
			curr = predecessor[curr];
		}
		printf("%d\n", src);
	} else {
		printf("No path from %d to %d\n", src, dest);
	}

	free(predecessor);
	QueueFree(q);
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

<img width="700" alt="Screenshot 2024-03-26 at 9 34 20 pm" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/8e44d0ab-68d3-4d5e-aba8-9ce282a4af0e">


```c
void dfs(Graph g, Vertex src) {
	bool *visited = calloc(g->nV, sizeof(bool));
	printf("DFS visit order: ");
	dfsRec(g, src, visited);
	printf("\n");
	free(visited);
}
```
```c
static void dfsRec(Graph g, Vertex v, bool *visited) {
	printf("%d ", v);
	visited[v] = true;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			dfsRec(g, w, visited);

			// backtrack to v
			printf("%d ", v);
		}
	}
}
```
```c
bool dfsFindsPath(Graph g, Vertex src, Vertex dest) {
	bool *visited = calloc(g->nV, sizeof(bool));
	// The lines are tp replace *visited array, both case works
	// int *predecessor = malloc(g->nV * sizeof(int));
	// predecessor[src] = src;
	bool result = dfsFindsPathRec(g, src, dest, visited);
	free(visited);
	return result;
}
```
```c
bool dfsFindsPathRec(Graph g, Vertex src, Vertex dest, bool *visited) {
	// check if curr vertex equals to destination
	if (v == dest) return TRUE;

	visited[v] = true;
	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
		// if (predecessor[w] == -1) -> predecessor[w] = v;

			// if there's a path from w to the dest,
			// then means there's a path from v to the dest
			if (dfsFindsPathRec(g, w, dest, visited)) {
				return true;
			}
		}
	}

	return false;
}
```

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week05mon-graph-traversal.pdf>

### Hamiltonian path && Hamiltonian circuit -> using dfs

<img width="700" alt="Screen Shot 2023-11-22 at 22 53 36" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/8792c6e9-a14a-4989-935a-647bc6aebe90">

- Hamiltonian path is a path that includes each vertex exactly once.
- Hamiltonian circuit is a cycle that includes each vertex exactly once. 
- Determing whehter a graph has above properties needs to use **DFS**
- Time Complexity:
    * Worst case O(V!)
<img width="442" alt="Screen Shot 2023-11-22 at 23 04 14" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/83f9cb6f-bcfe-4392-b302-9e54bfbe48ce">
<img width="442" alt="Screen Shot 2023-11-22 at 23 04 29" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/0e93e6cd-1143-4f9c-95f5-b6bc8c2d908c">

### Euler path && Euler circuit -> using dfs

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
- It is not necessary require for PQ, but however using it significant improve time efficiency.
- Time Complexity:
	- Without Pq: O(V^2)
	- With Pq: O((V + E) log V)
- Steps:
    1. Create a set containing every vertex of the graph
    2. Set all distances to Infinity (INT_MAX) and all predecessors to -1, set the source distance to 0
    3. Visit each vertex (v) from each other current vertex u and:
    4. If the distance of u +  the distance from u->v is less than the distance of v, then:
    5. Update the distance of v
    6. Set the predecessor of v to u

```c
  while node all nodes have ben visited
  	find the unvisited vertex v with the smallest dist[v]
  	mark it as visited
  	for each edge (v, w, weight) in the graph:
  		relax along (v, w, weight)
```

Note: This example doesn't used Pq.
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

### Minimum Spanning Tree
- A tree inside a Graph that has the shorest weighte while walking through every vertices from src to dest
- Involved Prim's Algo or kruskal's Algo

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week07wed-msts.pdf>

**Prim's Algo** - Grow the tree in successive stages
1. The tree has one vertex as the starting point and no edge initially
2. In each iteration, find all the edges connect with the targeted vertex i.e the starting vertex
3. And then select the edge with smallest weight and add to the tree
3. Throughout, maintain the properties of trees such that it is connecting and no cycles.

Analysis:
- has at most E edges -> O(E)
- has at most V iteration -> O(V)
- For each iteration, finding the min weighted edge: O(E + V * E) = O(V * E)
	- with set of edges O(E) -> Overall O(E + V)
	- with Fibonacci heap is O(log (E)) = O(log V) -> Overall O(E + V * log V)

<img width="750" alt="Screen Shot 2023-11-25 at 15 58 05" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/62137b57-20e6-448e-85e2-52358fc13065">


**Krustal's Algo** - Maintain a forest all the time
1. Initially, there are n trees such that every vertex is a tree (Build queue of edges and sort the elements in order)
2. Each iteration, dequeue and get the edge, check whether the two vertex connected are in the same tree
3. If not, accept edge into the set -> merging the trees together
4. At the end, it comes up one complete tree


Analysis:
- has at most E iterations
- sorting edges is O(E * log E)
- checking if adding edge would form a cycle
	- cycle chekcing is O(V) -> adj. List.
	- overall O(E * log E + E * V) = O(E * V)

<img width="750" alt="Screen Shot 2023-11-25 at 15 58 29" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/ef123a1a-4abe-42aa-ab80-548827da65bc">

*EXE: Checking whether a graph is well connected*
- In the context of this problem, we will assume a vertex is ‘well connected’ if it has an edge to at least 2 other vertices
- We will implement this using an adjacency matrix, but the algorithm is similar to an adjacency list, except rather than using another for loop, just iterate over the list per vertex
```c
/*
  Adjacency Matrix implementation
*/
int wellConnected(Graph g) {
  // create an int[] that holds the count of connections per vertex
  int *connections = calloc(g->nV, sizeof(int));

  // iterate over each vertex, and if an edge between i and j exists, increment
  // the connection count for i
  for (int i = 0; i < g->nV; i++) {
    for (int j = 0; j < g->nV; j++) {
      if (g->edges[i][j]) {
        connections[i]++;
      }
    }
  }

  // for each vertex, if the connection count is 2 or more, increment the total
  // well connected count, and return it
  int count = 0;
  for (int i = 0; i < g->nV; i++) {
    if (connections[i] >= 2) {
      count++;
    }
  }
  return count;
}
```
