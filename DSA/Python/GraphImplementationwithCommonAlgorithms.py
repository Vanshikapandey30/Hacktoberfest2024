from collections import defaultdict, deque
import heapq

class Graph:
    def __init__(self, directed=False):
        """Initialize a graph with optional directed edges"""
        self.graph = defaultdict(list)
        self.directed = directed
        self.vertices = set()
    
    def add_vertex(self, vertex):
        """Add a vertex to the graph"""
        self.vertices.add(vertex)
    
    def add_edge(self, u, v, weight=1):
        """Add an edge between vertices u and v with optional weight"""
        # Add vertices if they don't exist
        self.vertices.add(u)
        self.vertices.add(v)
        
        # Add edge u -> v
        self.graph[u].append((v, weight))
        
        # If undirected, add edge v -> u
        if not self.directed:
            self.graph[v].append((u, weight))
    
    def get_neighbors(self, vertex):
        """Get all neighbors of a vertex"""
        return [v for v, _ in self.graph[vertex]]
    
    def bfs(self, start_vertex):
        """Breadth-First Search traversal"""
        if start_vertex not in self.vertices:
            return []
        
        visited = set()
        traversal = []
        queue = deque([start_vertex])
        visited.add(start_vertex)
        
        while queue:
            vertex = queue.popleft()
            traversal.append(vertex)
            
            for neighbor, _ in self.graph[vertex]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        
        return traversal
    
    def dfs(self, start_vertex):
        """Depth-First Search traversal"""
        if start_vertex not in self.vertices:
            return []
        
        visited = set()
        traversal = []
        
        def dfs_recursive(vertex):
            visited.add(vertex)
            traversal.append(vertex)
            
            for neighbor, _ in self.graph[vertex]:
                if neighbor not in visited:
                    dfs_recursive(neighbor)
        
        dfs_recursive(start_vertex)
        return traversal
    
    def dijkstra(self, start_vertex):
        """Dijkstra's shortest path algorithm"""
        if start_vertex not in self.vertices:
            return {}
        
        # Initialize distances
        distances = {vertex: float('inf') for vertex in self.vertices}
        distances[start_vertex] = 0
        
        # Priority queue to store vertices and their distances
        pq = [(0, start_vertex)]
        
        # Dictionary to store the shortest path to each vertex
        previous = {vertex: None for vertex in self.vertices}
        
        while pq:
            current_distance, current_vertex = heapq.heappop(pq)
            
            # If we've found a longer path, skip
            if current_distance > distances[current_vertex]:
                continue
            
            # Check all neighbors
            for neighbor, weight in self.graph[current_vertex]:
                distance = current_distance + weight
                
                # If we've found a shorter path, update it
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    previous[neighbor] = current_vertex
                    heapq.heappush(pq, (distance, neighbor))
        
        return distances, previous
    
    def get_shortest_path(self, start_vertex, end_vertex):
        """Get the shortest path between two vertices using Dijkstra's algorithm"""
        if start_vertex not in self.vertices or end_vertex not in self.vertices:
            return None, None
        
        distances, previous = self.dijkstra(start_vertex)
        
        if distances[end_vertex] == float('inf'):
            return None, None
        
        # Reconstruct path
        path = []
        current_vertex = end_vertex
        
        while current_vertex is not None:
            path.append(current_vertex)
            current_vertex = previous[current_vertex]
        
        path.reverse()
        return path, distances[end_vertex]
    
    def has_cycle(self):
        """Detect if the graph has a cycle"""
        visited = set()
        rec_stack = set()
        
        def dfs_cycle(vertex):
            visited.add(vertex)
            rec_stack.add(vertex)
            
            for neighbor, _ in self.graph[vertex]:
                if neighbor not in visited:
                    if dfs_cycle(neighbor):
                        return True
                elif neighbor in rec_stack:
                    return True
            
            rec_stack.remove(vertex)
            return False
        
        for vertex in self.vertices:
            if vertex not in visited:
                if dfs_cycle(vertex):
                    return True
        
        return False
    
    def topological_sort(self):
        """Perform topological sort (only for directed acyclic graphs)"""
        if not self.directed or self.has_cycle():
            return None
        
        visited = set()
        stack = []
        
        def dfs_topological(vertex):
            visited.add(vertex)
            
            for neighbor, _ in self.graph[vertex]:
                if neighbor not in visited:
                    dfs_topological(neighbor)
            
            stack.append(vertex)
        
        for vertex in self.vertices:
            if vertex not in visited:
                dfs_topological(vertex)
        
        return stack[::-1]
        
        
        
# Create a new undirected graph
graph = Graph(directed=False)

# Add edges (automatically adds vertices)
graph.add_edge('A', 'B', 4)
graph.add_edge('A', 'C', 2)
graph.add_edge('B', 'C', 1)
graph.add_edge('B', 'D', 5)
graph.add_edge('C', 'D', 8)
graph.add_edge('C', 'E', 10)
graph.add_edge('D', 'E', 2)

# Perform BFS traversal starting from vertex 'A'
print("BFS traversal:", graph.bfs('A'))  # ['A', 'B', 'C', 'D', 'E']

# Perform DFS traversal starting from vertex 'A'
print("DFS traversal:", graph.dfs('A'))  # ['A', 'B', 'D', 'E', 'C']

# Find shortest path from 'A' to 'E'
path, distance = graph.get_shortest_path('A', 'E')
print(f"Shortest path from A to E: {path}")  # ['A', 'B', 'D', 'E']
print(f"Distance: {distance}")  # 11

# Create a directed graph for topological sort
dag = Graph(directed=True)
dag.add_edge('A', 'B')
dag.add_edge('B', 'C')
dag.add_edge('A', 'C')

print("Topological sort:", dag.topological_sort())  # ['A', 'B', 'C']
