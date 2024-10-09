Depth-First Search (DFS)
========================

Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It is commonly used for searching tree or graph data structures.

Key Features
------------

*   **Exploration Strategy:** DFS explores a branch as far as possible before backtracking.
*   **Stack-based Approach:** DFS can be implemented using a stack (either explicitly or implicitly using recursion).
*   **Time Complexity:** `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
*   **Space Complexity:** `O(V)`, for the visited nodes and the stack space used during traversal.

DFS Algorithm
-------------

The DFS algorithm works as follows:

*   Start from a specified node and mark it as visited.
*   For each adjacent unvisited node, recursively perform DFS on that node.
*   Backtrack when there are no more unvisited adjacent nodes.

DFS Implementation in Java
--------------------------

    
    import java.util.*;
    
    public class DepthFirstSearch {
        private List<List<Integer>> adjacencyList;
    
        // Constructor to initialize the graph with a specified number of nodes
        public DepthFirstSearch(int numberOfNodes) {
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
    
        // Method to perform DFS on the graph
        public void dfs(int startNode) {
            boolean[] visited = new boolean[adjacencyList.size()];
            dfsUtil(startNode, visited);
        }
    
        // Utility method for DFS
        private void dfsUtil(int currentNode, boolean[] visited) {
            visited[currentNode] = true;
            System.out.print(currentNode + " ");
    
            // Explore all neighbors of the current node
            for (int neighbor : adjacencyList.get(currentNode)) {
                if (!visited[neighbor]) {
                    dfsUtil(neighbor, visited);
                }
            }
        }
    
        public static void main(String[] args) {
            // Example graph
            DepthFirstSearch dfsGraph = new DepthFirstSearch(6);
    
            // Add edges to the graph
            dfsGraph.addEdge(0, 1);
            dfsGraph.addEdge(0, 2);
            dfsGraph.addEdge(1, 3);
            dfsGraph.addEdge(1, 4);
            dfsGraph.addEdge(2, 4);
            dfsGraph.addEdge(3, 5);
            dfsGraph.addEdge(4, 5);
    
            System.out.println("DFS starting from node 0:");
            dfsGraph.dfs(0);  // Perform DFS starting from node 0
        }
    }
        

Explanation of the Code
-----------------------

*   **Graph Representation:** The graph is represented as an adjacency list. Each index in the list corresponds to a node, and the list at that index contains its neighbors.
*   **DFS Method:** The `dfs` method initializes the visited array and calls the utility method to perform DFS.
*   **Visited Array:** The `visited` array is used to keep track of whether a node has been visited or not.
*   **Recursive Utility Method:** The `dfsUtil` method is a recursive function that performs the actual DFS traversal.
*   **Example Graph:** The graph in this example has 6 nodes (0 to 5) with edges added between them.

Output
------

The DFS traversal of the example graph starting from node 0 will produce the following output:

    
    DFS starting from node 0:
    0 1 3 5 4 2
        

Key Points
----------

*   **Traversal Order:** DFS explores as far as possible down one branch before backtracking.
*   **Uses Recursion:** DFS can be implemented using recursion, making it elegant and straightforward.
*   **Time Complexity:** `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
*   **Space Complexity:** `O(V)`, due to the visited array and the recursive call stack.

Applications of DFS
-------------------

*   **Pathfinding:** DFS can be used to find a path between two nodes in a graph.
*   **Topological Sorting:** DFS is useful in topological sorting of a directed acyclic graph (DAG).
*   **Connected Components:** DFS can identify connected components in a graph.
*   **Cycle Detection:** DFS can be used to detect cycles in a graph.