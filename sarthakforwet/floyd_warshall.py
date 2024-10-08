def floyd_warshall(graph):
    # Number of vertices in the graph
    V = len(graph)
    
    # Initialize the distance matrix with the given graph
    dist = [row[:] for row in graph]
    
    # Initialize the path matrix
    path = [[j if graph[i][j] != float('inf') else None for j in range(V)] for i in range(V)]
    
    # Update dist[i][j] for all intermediate vertices k
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    path[i][j] = path[i][k]
    
    return dist, path

# Function to reconstruct the path
def get_path(path, start, end):
    if path[start][end] is None:
        return []
    
    route = [start]
    while start != end:
        start = path[start][end]
        route.append(start)
    return route

# Example usage
if __name__ == "__main__":
    # Define the graph as an adjacency matrix
    # Use float('inf') for no direct connection
    graph = [
        [0, 3, float('inf'), 7],
        [8, 0, 2, float('inf')],
        [5, float('inf'), 0, 1],
        [2, float('inf'), float('inf'), 0]
    ]
    
    # Run Floyd-Warshall algorithm
    distances, paths = floyd_warshall(graph)
    
    # Print the shortest distance matrix
    print("Shortest distances between every pair of vertices:")
    for row in distances:
        print([f"{d:3}" if d != float('inf') else "INF" for d in row])
    
    # Example: Find shortest path from vertex 0 to 2
    start, end = 0, 2
    shortest_path = get_path(paths, start, end)
    
    print(f"\nShortest path from {start} to {end}:")
    print(" -> ".join(map(str, shortest_path)))
    print(f"Distance: {distances[start][end]}")