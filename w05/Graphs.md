#  Graphs

### Examples
* Maps
* Social Networks
* Internet
* Resource Allocation

### Graph Representation
V: vertices

E: edges

**Adjacency Matrix**

Data structure: 2D matrix indexed by the verticies.

M[0][1] contains:
* True (1) if an edge exists from vertex 0 to vertex 1. 
* False (0) if no edge exists from vertex 0 to vertex 1.

For graphs with complex vertices, M[x][y] may contain a struct carrying information about the vertex (eg. name, location, edge-weight, etc.)

Space Complexity: V x V, where V is the number of vertices.

Time Complexity to access an edge: O(1)

**Adjacency List**

Data structure: array of linked lists

A[0] contains a list of all the vertices connected to vertex 0.

Space Complexity: E, where E is the number of edges. Note that for a complete graph, E = V x V.

Time Complexity to access an edge: O(V)

### Graph Terminology

**Complete**: A graph is complete if every vertex has a direct connection to every other vertex.

**Connected Component**: A connected subgraph.

**Clique**: A complete subgraph.

**Cycle**: A non-empty path where the last vertex is the same as the first vertex.

**Degree**: the number of edges that a node has. For directed graphs, this can be categorized into an out-degree for outgoing edges and an in-degree for incoming edges.

**Directed / Undirected**: A graph can have undirected edges (eg. two-way roads) or directed edges (eg. one-way roads)

**Euler Path**: Visits each *edge* in the graph exactly once. (can remember it as 'e' for Euler and edge)

**Euler Tour**: An Euler path that ends at the same vertex that it started at.

**Forest**: A group of trees. ie. An undirected graph with no cycles. There is no requirement for it to be connected.

**Hamilton Path**: Visits each *vertex* in the graph exactly once.

**Hamilton Tour**: A Hamilton path that ends at the same vertex that it started at.

**Minimum Spanning Tree**: A set of edges from the graph that connects all the vertices together, without cycles, minimizing the total edge weight.

**Subgraph**: Some subcomponent of a graph.

**Tree**: An undirected, connected graph with no cycles.

**Weighted / unweighted**: Graph edges can be weighted (eg. the distance between two locations) or unweighted (eg. friendship is mutual)

## Graph Traversal

**Breadth First Search (BFS)**
* Use a queue and a seen list.
* Dequeue nodes, enqueue children.

**Depth First Search (DFS)**
* Use a stack and a seen list.
* Pop nodes, push children.


## Graph Algorithms

Minimum Spanning Tree
- Kruskal's
- Prim's

Shortest Path
- Djikstra's



