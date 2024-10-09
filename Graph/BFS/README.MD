Breadth-First Search (BFS)
==========================

Breadth-First Search (BFS) is a graph traversal algorithm that starts at a specified source node and explores all its neighboring nodes at the present depth before moving on to nodes at the next depth level. It is often used to find the shortest path in an unweighted graph or to explore all nodes within a graph.

Key Features
------------

*   **Level-by-level traversal:** BFS explores all nodes at one level before moving to the next level.
*   **Queue-based approach:** A queue is used to keep track of nodes that need to be explored.
*   **Shortest path in an unweighted graph:** BFS finds the shortest path from the source node to any other node in an unweighted graph.
*   **Time complexity:** `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.

BFS Algorithm
-------------

The BFS algorithm works as follows:

*   Start from the source node and mark it as visited.
*   Add the source node to a queue.
*   While the queue is not empty, repeat the following:
    *   Dequeue a node from the front of the queue.
    *   Visit all its unvisited neighboring nodes and add them to the queue.
    *   Mark those nodes as visited.

BFS Implementation in Java
--------------------------

    
    import java.util.*;
    
    public class BreadthFirstSearch {
        private List<List<Integer>> adjacencyList;
    
        // Constructor to initialize the graph with a specified number of nodes
        public BreadthFirstSearch(int numberOfNodes) {
            adjacencyList = new ArrayList<>(numberOfNodes);
            for (int i = 0; i < numberOfNodes; i++) {
                adjacencyList.add(new ArrayList<>());
            }
        }
    
        // Method to add an edge to the graph
        public void addEdge(int source, int destination) {
            adjacencyList.get(source).add(destination);
            adjacencyList.get(destination).add(source); // For undirected graph
        }
    
        // Method to perform BFS on the graph
        public void bfs(int startNode) {
            boolean[] visited = new boolean[adjacencyList.size()];
            Queue queue = new LinkedList<>();
    
            // Start BFS from the startNode
            visited[startNode] = true;
            queue.add(startNode);
    
            while (!queue.isEmpty()) {
                int currentNode = queue.poll();
                System.out.print(currentNode + " ");
    
                // Explore all neighbors of the current node
                for (int neighbor : adjacencyList.get(currentNode)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.add(neighbor);
                    }
                }
            }
        }
    
        public static void main(String[] args) {
            // Example graph
            BreadthFirstSearch bfsGraph = new BreadthFirstSearch(6);
    
            // Add edges to the graph
            bfsGraph.addEdge(0, 1);
            bfsGraph.addEdge(0, 2);
            bfsGraph.addEdge(1, 3);
            bfsGraph.addEdge(1, 4);
            bfsGraph.addEdge(2, 4);
            bfsGraph.addEdge(3, 5);
            bfsGraph.addEdge(4, 5);
    
            System.out.println("BFS starting from node 0:");
            bfsGraph.bfs(0);  // Perform BFS starting from node 0
        }
    }
        

Explanation of the Code
-----------------------

*   **Graph Representation:** The graph is represented as an adjacency list. Each index in the list corresponds to a node, and the list at that index contains its neighbors.
*   **BFS Method:** The `bfs` method performs BFS on the graph. It starts from a given node, uses a queue to explore its neighbors, and ensures that each node is visited only once.
*   **Visited Array:** The `visited` array is used to keep track of whether a node has been visited or not.
*   **Queue:** The queue is used to explore nodes in a level-order manner. Nodes are added to the queue as they are visited.
*   **Example Graph:** The graph in this example has 6 nodes (0 to 5) with edges added between them.

Output
------

The BFS traversal of the example graph starting from node 0 will produce the following output:

    
    BFS starting from node 0:
    0 1 2 3 4 5
        

Key Points
----------

*   **Traversal Order:** BFS explores nodes in layers. Nodes at distance 1 from the source are explored first, followed by nodes at distance 2, and so on.
*   **Shortest Path:** BFS is ideal for finding the shortest path in unweighted graphs.
*   **Queue-based Approach:** BFS uses a queue to keep track of which nodes to explore next.
*   **Time Complexity:** `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
*   **Space Complexity:** `O(V)`, due to the visited array and the queue.

Applications of BFS
-------------------

*   **Shortest Path in Unweighted Graphs:** BFS finds the shortest path from a source node to all other nodes.
*   **Connected Components:** BFS can be used to find connected components in a graph.
*   **Level-Order Traversal:** BFS is used to traverse trees level by level, which is equivalent to a level-order traversal in trees.
*   **Cycle Detection:** BFS can be used to detect cycles in an undirected graph.