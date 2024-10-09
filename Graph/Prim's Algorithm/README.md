Prim's Algorithm
================

What is Prim’s Algorithm Used For?
----------------------------------

Prim’s Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. It is widely used in:

*   Network design for telecommunication, electrical grids, and transportation networks.
*   Minimizing the cost of connecting nodes in a network.

Key Points for Interviews
-------------------------

*   **Greedy Approach:** Prim’s algorithm follows a greedy strategy, selecting the minimum weight edge that does not form a cycle.
*   **Time Complexity:** The time complexity of Prim's Algorithm is `O(E log V)` when using a priority queue (binary heap). This is important for scalability.
*   **Data Structures Used:**
    *   A priority queue (min-heap) is used to select the smallest edge.
    *   An adjacency list is often preferred over a matrix to reduce space complexity, especially for sparse graphs.
*   **Difference Between Prim's and Kruskal's Algorithm:**
    *   Prim's algorithm builds the MST by expanding from one vertex, while Kruskal's works by selecting edges across the graph.
    *   Kruskal's is generally preferred when the graph is sparse (fewer edges), while Prim's is efficient when the graph is dense (many edges).
*   **Handling Disconnected Graphs:** Prim’s algorithm works for connected graphs; for disconnected graphs, it will only find the MST of the connected component.
*   **Space Complexity:** The space complexity is `O(V + E)` due to the adjacency list and priority queue.

Explanation of Steps with an Example
------------------------------------

### Graph Structure:

The graph has 4 vertices (0, 1, 2, 3) and 5 edges with the following weights:

*   Edge from vertex 0 to 1 with a weight of 10.
*   Edge from vertex 0 to 2 with a weight of 6.
*   Edge from vertex 0 to 3 with a weight of 5.
*   Edge from vertex 1 to 3 with a weight of 15.
*   Edge from vertex 2 to 3 with a weight of 4.

### Minimum Spanning Tree:

Prim’s Algorithm selects edges based on the minimum weight without forming cycles. The MST for this graph is:

*   Edge from vertex 2 to 3 with a weight of 4
*   Edge from vertex 0 to 3 with a weight of 5
*   Edge from vertex 0 to 1 with a weight of 10

The total weight of the MST is **19**.

Pseudocode for Prim’s Algorithm
-------------------------------

    
    function prim(graph):
        create a set called MST (minimum spanning tree)
        create a priority queue (min-heap) for edges, initialized with a random edge
        create a set to keep track of visited nodes
    
        while the priority queue is not empty:
            edge = priority_queue.pop()
            if edge's end node is not in visited nodes:
                add edge to MST
                add edge's end node to visited nodes
                for each edge connected to edge's end node:
                    if the other end of the edge is not in visited nodes:
                        add the edge to the priority queue
        return MST
            

Java Implementation of Prim’s Algorithm
---------------------------------------

    
    // Java Program to Implement Prim's Algorithm
    import java.util.*;
    
    // Class to represent an edge in the graph
    class Edge {
        int source;
        int dest;
        int weight;
    
        // Constructor to initialize an edge
        Edge(int source, int dest, int weight) {
            this.source = source;
            this.dest = dest;
            this.weight = weight;
        }
    }
    
    // Class to represent the graph
    class Graph {
        int vertices;
        LinkedList[] adjacencyList;
    
        // Constructor to initialize the graph with the given number of vertices
        Graph(int vertices) {
            this.vertices = vertices;
            adjacencyList = new LinkedList[vertices];
            for (int i = 0; i < vertices; i++) {
                adjacencyList[i] = new LinkedList<>();
            }
        }
    
        // Method to add an edge to the graph
        void addEdge(int source, int dest, int weight) {
            Edge edge = new Edge(source, dest, weight);
            adjacencyList[source].add(edge);
    
            // Adding the reverse edge since it's an undirected graph
            adjacencyList[dest].add(new Edge(dest, source, weight));
        }
    
        // Method to implement Prim's algorithm to find the Minimum Spanning Tree (MST)
        void primMST() {
            // Array to keep track of vertices included in MST
            boolean[] inMST = new boolean[vertices];
    
            // Priority queue to select the edge with the smallest weight
            PriorityQueue priorityQueue =
                new PriorityQueue<>(Comparator.comparingInt(e -> e.weight));
    
            // List to store the MST edges
            List mst = new ArrayList<>();
    
            // Start from any vertex, here it's 0
            int startVertex = 0;
    
            // Mark the start vertex as included in MST
            inMST[startVertex] = true;
    
            // Add all edges from the start vertex to the priority queue
            for (Edge edge : adjacencyList[startVertex]) {
                priorityQueue.add(edge);
            }
    
            // Process the edges in the priority queue
            while (!priorityQueue.isEmpty()) {
                // Get the edge with the smallest weight
                Edge currentEdge = priorityQueue.poll();
    
                // If the destination vertex is not yet included in MST
                if (!inMST[currentEdge.dest]) {
                    // Add the edge to the MST
                    mst.add(currentEdge);
    
                    // Mark the destination vertex as included in MST
                    inMST[currentEdge.dest] = true;
    
                    // Add all edges from the current edge's destination to the priority queue
                    for (Edge edge : adjacencyList[currentEdge.dest]) {
                        if (!inMST[edge.dest]) {
                            priorityQueue.add(edge);
                        }
                    }
                }
            }
    
            // Print the edges in the MST
            System.out.println("Minimum Spanning Tree:");
            for (Edge edge : mst) {
                System.out.println("Edge: " + edge.source + " - " +
                                   edge.dest + " Weight: " + edge.weight);
            }
        }
    }
    
    // Main class to test the Prim's algorithm implementation
    public class PrimAlgorithmExample {
        public static void main(String[] args) {
            // Create a graph with 4 vertices
            Graph graph = new Graph(4);
    
            // Add edges to the graph
            graph.addEdge(0, 1, 10);
            graph.addEdge(0, 2, 6);
            graph.addEdge(0, 3, 5);
            graph.addEdge(1, 3, 15);
            graph.addEdge(2, 3, 4);
    
            // Find and print the MST using Prim's algorithm
            graph.primMST();
        }
    }
            

Applications of Prim's Algorithm
--------------------------------

*   Designing networks such as telecommunication, roadways, and computer networks, where minimizing the cost to connect all nodes is critical.
*   Solving problems in cluster analysis or image segmentation in computer vision.