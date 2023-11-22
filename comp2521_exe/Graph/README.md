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
<img width="850" alt="Screen Shot 2023-11-22 at 21 11 52" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/bae70a00-cba2-4da3-a84f-5cecc9946cc2">

- Edges are represented as an array of Edge values (struct containing pairs of Vertices)
- Space Efficiency
- Time Complexity:
	* Initialisation O(1)
	* Insert edge O(E)
	* Delete edge O(E)
	* Find edge O(log(E)) -> in order
- ADT:
<img width="850" alt="Screen Shot 2023-11-22 at 21 11 02" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/b1fd4de5-35e1-4e90-a346-2386e9fe0fd7">  

#### Adjacency Matrix 邻接矩阵
<img width="850" alt="Screen Shot 2023-11-22 at 21 12 08" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/15e84345-0e42-4705-ac7d-c3eb5b8c8be8">

- Edges represented by a V * V matrix
- If sparse, space is Inefficient
- Time Complexity:
	* Initialisation O(V^2)
	* Insert edge O(1)
	* Delete edge O(1)
- AD*:
<img width="850" alt="Screen Shot 2023-11-22 at 21 11 10" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/52cc3d2d-4673-436c-9a5c-ed3cc24fbfc7">  

#### Adjacency List 邻接表
<img width="850" alt="Screen Shot 2023-11-22 at 21 12 33" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/20b34e08-7780-4290-b87f-b17377af1e95">

- For each vertex, store a linked list of adjacent vertices
- Space Efficient
- Time complexity:
	* Initialisation O(V)
	* Insert Edge O(1)
	* Delete Edge O(E)
- ADT:
<img width="850" alt="Screen Shot 2023-11-22 at 21 11 29" src="https://github.com/Natalie-2004/COMP2521_REVISION/assets/62165943/dd8bc228-cf8c-4739-bb7c-c2c73e101f52">  
