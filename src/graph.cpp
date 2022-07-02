//#region INTRODUCTION
/*#GRAPH DATA STRUCTURE
G = [V, E] // Collection of vertices and edges
## Terminologies:
- Indegree = number of edges can access this vertix
- Outdegree = number of edges this vertex can access
- Adjacant vertices = if two vertices connected an edge
- Path = set of vertices which connects a pair of vertices
- Cycle= Ciruclar Path = Path that starts and ends in the same vertex

-

## Types of Graph
 --Directed graphs
    ---Self loop = connected to self
    ---Parallel edges= two vertices interconnected
 --Simple Digraph [directed graph]
    --- without self loop and parallel edges
 --Graph/non-directed graph
 --Non-connected graph
    --ARTICULATION Point: The vertex whose  removal leads to non-connected graph [2 seperate components]
 --Strongly connected directed graph
    From every vertices, we can reach all other vertices.
 --Directed Acyclic Graph (DAG)
    - directed
    - no cycle
 --Topological ordering
    --If the vertices can be arranged in straight line which is only possible in DAG.
*/
/* Representation of a UNDIRECTED GRAPH
G = [V,E] , |V| = n , |E|=e
1. Adjacency Matrix// space O(n^2)
    A matrix of n*n with row wise marking of connceted edges
2. Adjacency List// space O(n+2e)
    Array of linked list
3. Compact List// O(n+2e+1) array style storage

/* Representation of a DIRECTED GRAPH
1. Adjacency Matrix
2. Adjacency List//if outdegree is important
3. Inverse Adjacency list//if indegree is important
 */
//#endregion
#include <iostream>
