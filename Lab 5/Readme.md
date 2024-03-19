<h1>01-Prims Algorithm</h1>

<p>Prim's Algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph with weighted edges. The MST of a graph is a subgraph that contains all the vertices of the original graph and forms a tree with the minimum possible total edge weight.</p>

<h1>Pseudo Code</h1>

```cpp

Prim's Algorithm(Graph G):
    Let n be the number of vertices in the graph G.
    Let visited[n] be an array to keep track of visited vertices.
    Initialize visited[] as false.
    Let minHeap be a priority queue to store (weight, vertex) pairs.
    Initialize minHeap with (0, startVertex) where startVertex is an arbitrary starting vertex.
    Initialize MST as an empty list.
    
    while minHeap is not empty:
        (weight, vertex) = minHeap.extractMin()
        if visited[vertex]:
            continue
        
        visited[vertex] = true
        Add (weight, vertex) to MST
        
        for each neighbor, edgeWeight in G[vertex]:
            if not visited[neighbor]:
                Insert (edgeWeight, neighbor) into minHeap
    
    return MST
```

<h1>Graph</h1>


<h1>02- Kruskals Algorithm</h1>

<p>Prim's Algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph with weighted edges. The MST of a graph is a subgraph that contains all the vertices of the original graph and forms a tree with the minimum possible total edge weight.</p>

<h1>Pseudo Code</h1>

```cpp

Kruskal's Algorithm(Graph G):
    Let n be the number of vertices in the graph G.
    Initialize a set forest to store the connected components of the graph G.
    Initialize an empty list mst to store the edges of the minimum spanning tree.
    Sort the edges of G in non-decreasing order of their weights.
    
    for each vertex v in G:
        Create a new set containing only vertex v and add it to forest.
    
    for each edge (u, v, weight) in sorted(G.edges):
        if find(u) ≠ find(v):  // Check if u and v belong to different connected components
            Add (u, v) to mst  // Include the edge in the MST
            Union(u, v)  // Merge the connected components containing u and v
    
    return mst
```

<h1>Graph</h1>

<h1>03-Dijikstra's Algorithm</h1>

<p>The algorithm works by iteratively exploring the vertices of the graph in a greedy manner, updating the shortest path distances from the source vertex to each vertex as it progresses. At each step, it selects the vertex with the smallest tentative distance (i.e., the shortest known distance from the source) and explores its neighbors to potentially improve their shortest path distances..</p>

<h1>Pseudo Code</h1>

```cpp

Dijkstra(Graph G, Vertex source):
    Initialize distances array dist[] for all vertices with infinity, except for the source vertex set to zero.
    Initialize priority queue minHeap to store (vertex, distance) pairs.
    Insert (source, 0) into minHeap.
    
    while minHeap is not empty:
        (vertex, distance) = minHeap.extractMin()
        
        for each neighbor, weight in G[vertex]:
            new_distance = distance + weight
            if new_distance < dist[neighbor]:
                dist[neighbor] = new_distance
                minHeap.insertOrUpdate(neighbor, new_distance)
    
    return dist

```

<h1>Graph</h1>
