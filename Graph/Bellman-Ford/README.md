Bellman-Ford Algorithm in Java
==============================

Overview
--------

The Bellman-Ford algorithm finds the shortest path from a single source node to all other nodes in a weighted graph, even if the graph contains negative weight edges.

Steps
-----

*   Initialize distances: Set all distances to infinity, except for the source node (0).
*   Relax edges: For each edge, update the distance to the destination node if the current distance is greater than the new calculated distance.
*   Repeat: Repeat the relaxation process for (V - 1) times, where V is the number of vertices.
*   Check for negative weight cycles: If a distance can still be updated, the graph contains a negative weight cycle.

Pseudocode
----------

    function BellmanFord(Graph, source):
        initialize all distances to infinity
        set distance of source to 0
        for each vertex in Graph:
            for each edge in Graph:
                relax the edge
        if there is a shorter path, report negative cycle
    

Java Implementation
-------------------

    // Java implementation of the Bellman-Ford algorithm
    import java.util.*;
    
    class Edge {
        int source, destination, weight;
        Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }
    
    public class BellmanFord {
        int vertexCount;
        List edges;
    
        public BellmanFord(int vertexCount) {
            this.vertexCount = vertexCount;
            this.edges = new ArrayList<>();
        }
    
        public void addEdge(int source, int destination, int weight) {
            edges.add(new Edge(source, destination, weight));
        }
    
        public void bellmanFord(int source) {
            int[] distances = new int[vertexCount];
            Arrays.fill(distances, Integer.MAX_VALUE);
            distances[source] = 0;
    
            for (int i = 1; i < vertexCount; i++) {
                for (Edge edge : edges) {
                    if (distances[edge.source] != Integer.MAX_VALUE &&
                        distances[edge.source] + edge.weight < distances[edge.destination]) {
                        distances[edge.destination] = distances[edge.source] + edge.weight;
                    }
                }
            }
    
            // Check for negative weight cycles
            for (Edge edge : edges) {
                if (distances[edge.source] != Integer.MAX_VALUE &&
                    distances[edge.source] + edge.weight < distances[edge.destination]) {
                    System.out.println("Graph contains negative weight cycle.");
                    return;
                }
            }
    
            System.out.println("Vertex Distance from Source");
            for (int i = 0; i < vertexCount; i++) {
                System.out.println(i + " \t\t " + (distances[i] == Integer.MAX_VALUE ? "Infinity" : distances[i]));
            }
        }
    
        public static void main(String[] args) {
            BellmanFord graph = new BellmanFord(5);
            graph.addEdge(0, 1, -1);
            graph.addEdge(0, 2, 4);
            graph.addEdge(1, 2, 3);
            graph.addEdge(1, 3, 2);
            graph.addEdge(1, 4, 2);
            graph.addEdge(3, 2, 5);
            graph.addEdge(3, 1, 1);
            graph.addEdge(4, 3, -3);
    
            graph.bellmanFord(0);
        }
    }
    

Limitations of Bellman-Ford Algorithm
-------------------------------------

*   **Time Complexity:** The algorithm has a time complexity of O(VE), which can be inefficient for large graphs.
*   **Negative Cycles:** If the graph contains negative weight cycles, the algorithm may not provide valid shortest paths.
*   **Less Efficient than Dijkstra's:** For graphs with no negative weight edges, Dijkstra's algorithm is generally more efficient.

Usages of Bellman-Ford Algorithm
--------------------------------

*   **Finding Shortest Paths:** Used to find shortest paths in graphs with negative weights.
*   **Network Routing:** Helps in optimizing routing protocols in networks.
*   **Finance:** Can be applied in financial networks for calculating shortest paths in cost analysis.
*   **Transportation:** Utilized in transportation networks for route optimization.

Complexity
----------

The time complexity of the Bellman-Ford algorithm is:

*   **Time Complexity: O(VE**, where V is the number of vertices and E is the number of edges in the graph.

Space Complexity
----------------

The space complexity of the Bellman-Ford algorithm is:

*   **O(V):** The algorithm requires space for storing the distance array and the edge list.