## Graph

### Properties
- Has V - a set of vertices
- Has E - a set of edges
- Has at most V(V-1)/2 edges (excluding loop)

- An **undirected graph** is when an edge from 'v' to 'w' is the same edge from 'w' to 'v', and there are *no self loops*
- A **directed graph** is when an edge from 'v' to w is not the same edge from 'w' to 'v', and there is *self loops*
- A **weighted graph** is when each edge has a weight

- Is dense if E is large, is sparse if E is small
- The vertices are said to be **adjacent** if there is an edge 'e' connects 'v' and 'w'
- And 'e' is the incident on both 'v' and 'w'
- The degree of a vertex v is the number of edges incident on e
- A **path** is a sequence of vertices where each vertex has an edge to its predecessor
- A **cycle** is where the last vertex in a path is the same as the first vertex in path

- The length of a path/cycle is the number of edges in that path/cycle
- A connected graph is when there is a path from each vertex to every other vertex
- A complete graph is if there is an edge from each vertex to every other vertex

- A tree is a connected graph/subgraph with no cycles
- A **spanning tree** is a tree containing all vertices of the graph
- A clique is a complete subgraph

### Graph Basic
#### Array of Edges 边集数组
- Edges are represented as an array of Edge values (struct containing pairs of Vertices)
- Space Efficiency
- Time Complexity: 
    - Initialisation O(1)
    - Insert edge O(E)
    - Delete edge O(E)
    - Find edge O(log(E)) -> in order
- ADT:


#### Adjacency Matrix
- Edges represented by a V * V matrix
- If sparse, space is Inefficient
- Time Complexity:
    - Initialisation O(V^2)
    - Insert edge O(1)
    - Delete edge O(1)
- ADT:


#### Adjacency List
- For each vertex, store a linked list of adjacent vertices
- Space Efficient
- Time complexity:
    - Initialisation O(V)
    - Insert Edge O(1)
    - Delete Edge O(E)
- ADT:
