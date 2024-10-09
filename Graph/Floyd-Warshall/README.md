Floyd-Warshall Algorithm in Java
================================

Overview
--------

The Floyd-Warshall algorithm finds the shortest paths between all pairs of vertices in a weighted graph, allowing for negative weights but no negative weight cycles.

Steps
-----

*   Initialize the distance matrix: Set the distance to zero for all vertices to themselves and to infinity for other pairs.
*   Update the distance matrix: For each vertex, check if the distance from vertex i to j can be shortened by going through vertex k.
*   Repeat the process for all vertices: This will ensure that all shortest paths are found.

Pseudocode
----------

    function FloydWarshall(Graph):
        initialize distance matrix
        for each vertex k:
            for each vertex i:
                for each vertex j:
                    if distance[i][j] > distance[i][k] + distance[k][j]:
                        update distance[i][j]
    

Java Implementation
-------------------

    // Java implementation of the Floyd-Warshall algorithm
    public class FloydWarshall {
        public static void floydWarshall(int graph[][]) {
            int V = graph.length;
            int[][] distance = new int[V][V];
    
            // Initialize the distance matrix
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    distance[i][j] = graph[i][j];
                }
            }
    
            // Update the distance matrix
            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (distance[i][j] > distance[i][k] + distance[k][j]) {
                            distance[i][j] = distance[i][k] + distance[k][j];
                        }
                    }
                }
            }
    
            // Print the result
            System.out.println("Shortest distances between every pair of vertices:");
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (distance[i][j] == Integer.MAX_VALUE) {
                        System.out.print("INF ");
                    } else {
                        System.out.print(distance[i][j] + " ");
                    }
                }
                System.out.println();
            }
        }
    
        public static void main(String[] args) {
            int graph[][] = {
                {0, 3, Integer.MAX_VALUE, 7},
                {8, 0, 2, Integer.MAX_VALUE},
                {5, Integer.MAX_VALUE, 0, 1},
                {2, Integer.MAX_VALUE, Integer.MAX_VALUE, 0}
            };
            floydWarshall(graph);
        }
    }
    

Limitations of Floyd-Warshall Algorithm
---------------------------------------

*   **Time Complexity:** The algorithm has a time complexity of O(V³), making it inefficient for very large graphs.
*   **Space Complexity:** It requires O(V²) space to store the distance matrix.
*   **Negative Weight Cycles:** The algorithm cannot handle graphs with negative weight cycles, as it may produce incorrect results.

Usages of Floyd-Warshall Algorithm
----------------------------------

*   **All-Pairs Shortest Paths:** It is primarily used to find the shortest paths between all pairs of vertices in a graph.
*   **Network Routing:** Can be used in routing algorithms to determine optimal paths in networks.
*   **Graph Analysis:** Helps in analyzing the structure and properties of graphs.
*   **Game Development:** Useful in game development for pathfinding algorithms in maps and levels.

Complexity
----------

The time complexity of the Floyd-Warshall algorithm is:

*   **Time Complexity: O(V³**, where V is the number of vertices in the graph.

Space Complexity
----------------

The space complexity of the Floyd-Warshall algorithm is:

*   **O(V²):** The algorithm requires space to store the distance matrix.