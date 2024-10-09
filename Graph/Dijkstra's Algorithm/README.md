Dijkstra's Algorithm in Java
============================

Overview
--------

Dijkstra's algorithm finds the shortest path from a starting node to all other nodes in a weighted graph using a greedy approach.

Steps
-----

*   Initialize distances: Set all distances to infinity, except for the source node (0).
*   Select the node with the smallest distance that hasn't been visited.
*   Update the distances to neighboring nodes.
*   Mark the node as visited and repeat until all nodes are visited.

Pseudocode
----------

    function Dijkstra(Graph, source):
        initialize all distances to infinity
        set distance of source to 0
        while there are unvisited nodes:
            select the node with the smallest distance
            update distances to neighbors
            mark the node as visited
    

Java Implementation (Simple)
----------------------------

    // Simple Java implementation of Dijkstra's Algorithm
    import java.util.*;
    
    public class Dijkstra {
        static final int V = 9;
    
        // Method to find the vertex with the smallest distance
        int findMinDistance(int[] distances, boolean[] visited) {
            int min = Integer.MAX_VALUE;
            int minIndex = -1;
    
            for (int i = 0; i < V; i++) {
                if (!visited[i] && distances[i] <= min) {
                    min = distances[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }
    
        // Method implementing Dijkstra's Algorithm
        void dijkstra(int[][] graph, int source) {
            int[] distances = new int[V];
            boolean[] visited = new boolean[V];
    
            Arrays.fill(distances, Integer.MAX_VALUE);
            distances[source] = 0;
    
            for (int count = 0; count < V - 1; count++) {
                int u = findMinDistance(distances, visited);
                visited[u] = true;
    
                for (int v = 0; v < V; v++) {
                    if (!visited[v] && graph[u][v] != -1 && distances[u] != Integer.MAX_VALUE && 
                        distances[u] + graph[u][v] < distances[v]) {
                        distances[v] = distances[u] + graph[u][v];
                    }
                }
            }
    
            System.out.println("Vertex Distance from Source");
            for (int i = 0; i < V; i++) {
                System.out.println(i + " \t\t " + distances[i]);
            }
        }
    
        public static void main(String[] args) {
            int graph[][] = new int[][] {
                { 0, 4, -1, -1, -1, -1, -1, 8, -1 },
                { 4, 0, 8, -1, -1, -1, -1, 11, -1 },
                { -1, 8, 0, 7, -1, 4, -1, -1, 2 },
                { -1, -1, 7, 0, 9, 14, -1, -1, -1 },
                { -1, -1, -1, 9, 0, 10, -1, -1, -1 },
                { -1, -1, 4, 14, 10, 0, 2, -1, -1 },
                { -1, -1, -1, -1, -1, 2, 0, 1, 6 },
                { 8, 11, -1, -1, -1, -1, 1, 0, 7 },
                { -1, -1, 2, -1, -1, -1, 6, 7, 0 }
            };
            Dijkstra dijkstra = new Dijkstra();
            dijkstra.dijkstra(graph, 0);
        }
    }
    

Optimized Java Implementation (Using Priority Queue)
----------------------------------------------------

    // Optimized Dijkstra's Algorithm using Priority Queue
    import java.util.*;
    
    class Node {
        int id, cost;
        Node(int id, int cost) { this.id = id; this.cost = cost; }
    }
    
    public class DijkstraPriorityQueue {
        int[] distances;
        boolean[] settled;
        PriorityQueue pq;
        List<List<Node> > adjacent;;
        int vertexCount;
    
        public DijkstraPriorityQueue(int vertexCount) {
            this.vertexCount = vertexCount;
            distances = new int[vertexCount];
            settled = new boolean[vertexCount];
            pq = new PriorityQueue<>(Comparator.comparingInt(node -> node.cost));
        }
    
        public void dijkstra(List> adjList, int source) {
            this.adjList = adjList;
            Arrays.fill(distances, Integer.MAX_VALUE);
            pq.add(new Node(source, 0));
            distances[source] = 0;
    
            while (settled.length != vertexCount) {
                Node current = pq.poll();
                int u = current.id;
                if (settled[u]) continue;
                settled[u] = true;
    
                for (Node neighbor : adjList.get(u)) {
                    if (!settled[neighbor.id]) {
                        int newDist = distances[u] + neighbor.cost;
                        if (newDist < distances[neighbor.id]) {
                            distances[neighbor.id] = newDist;
                            pq.add(new Node(neighbor.id, newDist));
                        }
                    }
                }
            }
    
            System.out.println("Vertex Distance from Source");
            for (int i = 0; i < distances.length; i++) {
                System.out.println(i + " \t\t " + distances[i]);
            }
        }
    
        public static void main(String[] args) {
            int vertexCount = 9;
            List> adjList = new ArrayList<>(vertexCount);
            for (int i = 0; i < vertexCount; i++) {
                adjList.add(new ArrayList<>());
            }
    
            adjList.get(0).add(new Node(1, 4));
            adjList.get(0).add(new Node(7, 8));
            adjList.get(1).add(new Node(2, 8));
            adjList.get(1).add(new Node(7, 11));
            adjList.get(2).add(new Node(3, 7));
            adjList.get(2).add(new Node(5, 4));
            adjList.get(2).add(new Node(8, 2));
            adjList.get(3).add(new Node(4, 9));
            adjList.get(3).add(new Node(5, 14));
            adjList.get(4).add(new Node(5, 10));
            adjList.get(5).add(new Node(6, 2));
            adjList.get(6).add(new Node(7, 1));
            adjList.get(6).add(new Node(8, 6));
            adjList.get(7).add(new Node(8, 7));
    
            DijkstraPriorityQueue dijkstra = new DijkstraPriorityQueue(vertexCount);
            dijkstra.dijkstra(adjList, 0);
        }
    }
    

Limitations of Dijkstra's Algorithm
-----------------------------------

*   **Non-Negative Weights Only:** Dijkstra's algorithm cannot handle graphs with negative weight edges.
*   **Efficiency with Sparse Graphs:** For dense graphs, the algorithm can be inefficient; other algorithms like Floyd-Warshall may be more appropriate.
*   **Single-Source Shortest Paths:** It finds the shortest path from one source node to all other nodes, not the shortest paths between all pairs of nodes.

Usages of Dijkstra's Algorithm
------------------------------

*   **GPS Navigation:** Used for finding the shortest route on maps.
*   **Network Routing:** Helps determine the most efficient paths for data transmission.
*   **Game Development:** Utilized in pathfinding algorithms for AI in games.
*   **Telecommunications:** Assists in optimizing communication network paths.

Complexity
----------

The time complexity of Dijkstra's algorithm depends on the data structure used for the priority queue:

*   **Using a simple array:** O(V2)
*   **Using a binary heap:** O((V + E) log V), where E is the number of edges.
*   **Using a Fibonacci heap:** O(E + V log V), which is more efficient for dense graphs.