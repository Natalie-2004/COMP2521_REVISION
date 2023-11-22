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

Example:
<img width="600" alt="Screen Shot 2023-11-22 at 22 52 25" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/159bed66-1cf7-44f4-a7ab-6439e63d7e1d">

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

### Depth-First Searching (DFS 深度优先搜索
Depth-first search is described recursively as:
* Mark current vertex as visited
    - The first time, this is the starting vertex
* For each neighbour of the current vertex:
    - If it has not been visited:
    - Recursively traverse starting from that vertex
The recursion naturally induces backtracking

Example:
<img width="600" alt="Screen Shot 2023-11-22 at 22 52 25" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/159bed66-1cf7-44f4-a7ab-6439e63d7e1d">

1. 访问 A，并将其标记为已访问。
2. 选择 A 的一个未访问的邻居，例如 B，并递归地访问它。
3. 继续选择 B 的一个未访问的邻居，例如 D，并递归地访问它。
4. 当 D 没有未访问的邻居时，回溯到 B。
5. 当 B 也没有其他未访问的邻居时，回溯到 A。
6. 然后选择 A 的另一个未访问的邻居，例如 C，并递归地访问它。
7. 继续选择 C 的一个未访问的邻居，例如 E，并递归地访问它。
Order: A, B, D, C, E

<https://cgi.cse.unsw.edu.au/~cs2521/23T3/lectures/slides/week05mon-graph-traversal.pdf>

### Hamiltonian path && Hamiltonian circuit

<img width="700" alt="Screen Shot 2023-11-22 at 22 53 36" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/8792c6e9-a14a-4989-935a-647bc6aebe90">

- Hamiltonian path is a path that includes each vertex exactly once.
- Hamiltonian circuit is a cycle that includes each vertex exactly once. 
- Determing whehter a graph has above properties needs to use **DFS**
- Time Complexity:
    * Worst case O(V!)

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
