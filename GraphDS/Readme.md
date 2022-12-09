<p align="center">
    <img src="./Images/graphintro.jpeg"  width="500" />
</p>   

>## **Graph**
- collection of  vertices and edges connecting these vertices  
- **Directed Edge** - One way connection  
- **Undirected Edge** - Two way connection  
- **Directed Graph** -  All directed edges   
- **Undirected Graph** - All undirected edges  
- **Indegree** - No of edges going out of the node  
- **Outdegree** - No of edges coming in the node  

------------------------
>## Representation of Graph

<p align="center">
    <img src="./Images/ex.png"  width="200" />
</p>

- `Adjacency list`   
An array of lists is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs. Following is the adjacency list representation of the above graph.  
 

 <p align="center">
    <img src="./Images/listadjacency.png"  width="400" />
</p>

- `Adjacency matrix`  
Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.

<p align="center">
    <img src="./Images/adjacencymatrix.png"  width="200" />
</p>

- Other ways - Edge set, Compact List, Cost Adjacency List, etc.

---------

>## Graph Traversal

- process of visiting each and every node of a graph
- Two algorithms for graph traversal:  
        `Breadth First search` - (Queue DS is used)  
            In BFS , we start with a node  and start  exploring  its connected node.  The same process is repeated  with all the connecting nodes untill all the nodes are visited.   
        `Depth First search` - (Stack DS is used)  
            In DFS ,  we start with a node and start exploring its connected nodes keeping  on suspending  the exploration  of previous  nodes.
