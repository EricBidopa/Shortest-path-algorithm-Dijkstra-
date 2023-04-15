# Shortest-path-algorithm-Dijkstra-
This is another greedy algorithm


The code implements Dijkstra's algorithm, which is an algorithm 
used to find the shortest path between a source vertex and all other 
vertices in a weighted graph.

The code reads in the input values of n, m, and the edges and weights 
of an undirected graph with n vertices and m edges. It then reads in 
the source and destination vertices and uses Dijkstra's algorithm to 
find the shortest path between the source and destination vertices.

In the algorithm, a priority queue is used to store the vertices and 
their distances from the source vertex. Initially, all distances 
are set to infinity except for the source vertex, whose distance 
is set to zero. The algorithm then iterates through the priority 
queue, popping the vertex with the smallest distance, and updating 
the distances of its adjacent vertices if a shorter path is found. 
The algorithm continues until all vertices have been visited and 
their distances from the source vertex have been computed.

The output of the code is the shortest distance from the source vertex 
to the destination vertex, as well as the path taken to get there.
 The parent vector is used to keep track of the path taken to each vertex, 
 and the path is printed by backtracking from the destination vertex to the 
 source vertex using the parent vector.
