import java.util.*;

// Graph class to represent the graph using an adjacency list
class Graph {
    private int V; // Number of vertices
    private LinkedList<Integer>[] adj; // Adjacency List

    // Constructor
    Graph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    // Method to add an edge between two vertices
    void addEdge(int v, int w) {
        adj[v].add(w); // Add w to v's list
    }

    // DFS traversal starting from a given vertex v
    void DFS(int v, boolean[] visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        System.out.print(v + " ");

        // Recursively visit all the vertices adjacent to this vertex
        for (int n : adj[v]) {
            if (!visited[n]) {
                DFS(n, visited);
            }
        }
    }

    // Helper method to start DFS traversal from all vertices
    void DFS() {
        // Mark all the vertices as not visited
        boolean[] visited = new boolean[V];

        // Call the recursive DFS function for all unvisited vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, visited);
            }
        }
    }
}

public class DFSDemo {
    public static void main(String[] args) {
        Graph g = new Graph(6); // Create a graph with 6 vertices

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);

        System.out.println("Depth First Traversal (DFS) of the graph:");
        g.DFS(); // Perform DFS traversal
    }
}
