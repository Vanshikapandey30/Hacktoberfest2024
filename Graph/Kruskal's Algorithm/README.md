Kruskal's Algorithm: An Overview
================================

Kruskal's Algorithm is a greedy algorithm designed to find the Minimum Spanning Tree (MST) of a connected, undirected graph. The MST is a subset of edges that connects all vertices with the minimum total edge weight while avoiding any cycles. The algorithm systematically adds edges in order of increasing weight, ensuring that no cycles are formed, thus constructing the MST step-by-step with minimal weight.

Key Concepts
------------

*   **Graph**: A collection of vertices (nodes) connected by edges.
*   **Spanning Tree**: A subgraph that connects all vertices without cycles, utilizing the minimum number of edges.
*   **Minimum Spanning Tree (MST)**: A spanning tree with the minimum sum of edge weights.

How Kruskal's Algorithm Works
-----------------------------

1.  **Sort the Edges**: The edges of the graph are sorted in non-decreasing order based on their weights.
2.  **Initialize MST**: An empty set (or list) is initialized to store the edges of the MST.
3.  **Iterate through Edges**:
    *   For each edge, check if adding it would create a cycle using the Union-Find data structure.
    *   If it does not form a cycle, the edge is added to the MST.
    *   If it would form a cycle, the edge is skipped.
4.  **Repeat** the process until `V - 1` edges are added (where `V` is the number of vertices in the graph).

Union-Find Algorithm
--------------------

The Union-Find algorithm is employed to detect cycles. It has two key functions:

*   **Find**: Determines the set (or component) that a specific vertex belongs to.
*   **Union**: Merges two sets if adding the edge between them does not form a cycle.

The **Find-Set** operation uses path compression to speed up future find operations, while the **Union** function employs union by rank to keep the tree flat, enhancing algorithm efficiency.

Example Walkthrough
-------------------

Given a graph with 5 vertices and 7 edges, the edges and their respective weights are:

# Edge Weights

| Edge     | Weight |
|----------|--------|
| (0, 1)   | 1      |
| (0, 2)   | 3      |
| (0, 3)   | 4      |
| (1, 3)   | 5      |
| (1, 4)   | 2      |
| (2, 4)   | 4      |
| (3, 4)   | 7      |


### Steps:

1.  Sort the edges by weight: `(0, 1) → (1, 4) → (0, 2) → (0, 3) → (2, 4) → (1, 3) → (3, 4)`.
2.  Initialize an empty MST set.
3.  Start adding the edges:
    *   Add (0, 1) (no cycle formed).
    *   Add (1, 4) (no cycle formed).
    *   Add (0, 2) (no cycle formed).
    *   Add (0, 3) (no cycle formed).
    *   Skip (2, 4) since it would create a cycle.
    *   Skip (1, 3) for the same reason.
    *   Skip (3, 4) because it also forms a cycle.
4.  The final MST consists of: `{(0, 1), (1, 4), (0, 2), (0, 3)}` with a total weight of 10.

Kruskal's Algorithm Pseudocode
------------------------------

    
    KRUSKAL(G):
        A ← ∅                       // Initialize an empty set for the MST
        for each vertex v in G.V:   // Loop through all vertices in the graph
            MAKE-SET(v)             // Create a set for each vertex (initialize Union-Find)
            
        sort the edges of G.E in non-decreasing order by weight w  // Sort edges by weight
    
        for each edge (u, v) in the sorted order:  // Loop through the sorted edges
            if FIND-SET(u) ≠ FIND-SET(v):           // Check if u and v belong to different sets
                A ← A ∪ {(u, v)}                     // Add edge (u, v) to the MST
                UNION(u, v)                          // Merge the sets of u and v
                
        return A                                     // Return the final set of edges in the MST
    

Time Complexity
---------------

*   **Sorting the Edges**: The time complexity for sorting the edges is `O(E log E)`, where `E` is the number of edges.
*   **Union-Find Operations**: Each operation takes nearly constant time, `O(log V)`, thanks to path compression and union by rank.
*   **Overall Complexity**: The total time complexity of the algorithm is `O(E log E + E log V)`. Since `E log V` is less than or equal to `E log E`, this simplifies to: `O(E log E)`.

Kruskal’s Algorithm in Java
---------------------------

    
    import java.util.*;
    
    class Edge implements Comparable {
        int src, dest, weight;
    
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    
        @Override
        public int compareTo(Edge compareEdge) {
            return this.weight - compareEdge.weight;
        }
    }
    
    class Graph {
        int V, E;
        Edge[] edges;
    
        public Graph(int V, int E) {
            this.V = V;
            this.E = E;
            edges = new Edge[E];
        }
    
        int find(int[] parent, int i) {
            if (parent[i] == -1)
                return i;
            return find(parent, parent[i]);
        }
    
        void union(int[] parent, int x, int y) {
            int xset = find(parent, x);
            int yset = find(parent, y);
            parent[xset] = yset;
        }
    
        void kruskalMST() {
            Edge[] result = new Edge[V - 1];
            int e = 0; // Index for result
            int i = 0; // Index for sorted edges
    
            Arrays.sort(edges);
    
            int[] parent = new int[V];
            Arrays.fill(parent, -1);
    
            while (e < V - 1) {
                Edge next_edge = edges[i++];
    
                int x = find(parent, next_edge.src);
                int y = find(parent, next_edge.dest);
    
                if (x != y) {
                    result[e++] = next_edge;
                    union(parent, x, y);
                }
            }
    
            System.out.println("Edges in the Minimum Spanning Tree:");
            for (Edge edge : result) {
                System.out.println(edge.src + " -- " + edge.dest + " == " + edge.weight);
            }
        }
    }
    
    // Example Usage
    public class Main {
        public static void main(String[] args) {
            int V = 5; // Number of vertices
            int E = 7; // Number of edges
            Graph graph = new Graph(V, E);
    
            graph.edges[0] = new Edge(0, 1, 1);
            graph.edges[1] = new Edge(0, 2, 3);
            graph.edges[2] = new Edge(0, 3, 4);
            graph.edges[3] = new Edge(1, 3, 5);
            graph.edges[4] = new Edge(1, 4, 2);
            graph.edges[5] = new Edge(2, 4, 4);
            graph.edges[6] = new Edge(3, 4, 7);
    
            graph.kruskalMST();
        }
    }
    

Important Points for Interviews
-------------------------------

*   Understanding the greedy strategy and when it can be applied effectively.
*   Familiarity with the Union-Find data structure, including its operations and optimization techniques.
*   Ability to analyze the time complexity and identify bottlenecks in performance.
*   Knowledge of edge cases and how to handle graphs with cycles, disconnected components, or large edge weights.
*   Practicing coding the algorithm in different programming languages to improve adaptability.