Topological Sort Algorithm in Java
==================================

Overview
--------

Topological sorting of a directed acyclic graph (DAG) is a linear ordering of its vertices such that for every directed edge `U -> V`, vertex `U` comes before vertex `V` in the ordering. Topological sort is useful for scheduling tasks, resolving dependencies, and many other scenarios.

Steps
-----

*   Compute the in-degree of each vertex (number of incoming edges).
*   Add all vertices with in-degree 0 to a queue.
*   While the queue is not empty:
    *   Remove a vertex from the queue and add it to the topological order.
    *   Decrease the in-degree of its neighbors by 1.
    *   If the in-degree of a neighbor becomes 0, add it to the queue.

Pseudocode
----------

    function TopologicalSort(Graph):
        initialize in-degree array
        for each vertex in Graph:
            calculate in-degree
        create queue and add vertices with in-degree 0
    
        while queue is not empty:
            vertex = dequeue
            add vertex to topological order
            for each neighbor of vertex:
                decrease in-degree
                if in-degree of neighbor becomes 0:
                    enqueue neighbor
    

Java Implementation
-------------------

    // Java implementation of Topological Sort using Kahn's Algorithm
    import java.util.*;
    
    public class TopologicalSort {
        public static void topologicalSort(int vertices, List> adjList) {
            int[] inDegree = new int[vertices];
            for (int i = 0; i < vertices; i++) {
                for (int neighbor : adjList.get(i)) {
                    inDegree[neighbor]++;
                }
            }
    
            Queue queue = new LinkedList<>();
            for (int i = 0; i < vertices; i++) {
                if (inDegree[i] == 0) {
                    queue.add(i);
                }
            }
    
            List topologicalOrder = new ArrayList<>();
            while (!queue.isEmpty()) {
                int vertex = queue.poll();
                topologicalOrder.add(vertex);
    
                for (int neighbor : adjList.get(vertex)) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        queue.add(neighbor);
                    }
                }
            }
    
            // Check for cycles
            if (topologicalOrder.size() != vertices) {
                System.out.println("Graph has a cycle, topological sort not possible.");
                return;
            }
    
            // Print the topological order
            System.out.println("Topological Order: " + topologicalOrder);
        }
    
        public static void main(String[] args) {
            int vertices = 6;
            List> adjList = new ArrayList<>(vertices);
            for (int i = 0; i < vertices; i++) {
                adjList.add(new ArrayList<>());
            }
    
            // Adding edges
            adjList.get(5).add(2);
            adjList.get(5).add(0);
            adjList.get(4).add(0);
            adjList.get(4).add(1);
            adjList.get(2).add(3);
            adjList.get(3).add(1);
    
            topologicalSort(vertices, adjList);
        }
    }
    

Limitations of Topological Sort
-------------------------------

*   Topological sorting is applicable only to directed acyclic graphs (DAGs).
*   If the graph contains cycles, topological sort cannot be performed.
*   There may be multiple valid topological sorts for a single graph, depending on the algorithm and data structures used.

Usages of Topological Sort
--------------------------

*   Task scheduling based on dependencies.
*   Build systems to manage dependencies between modules or files.
*   Organizing course schedules based on prerequisite courses.
*   Data serialization requiring a linear representation of data.

Complexity
----------

The time complexity of the Topological Sort algorithm is:

*   **Time Complexity: O(V + E)**, where V is the number of vertices and E is the number of edges in the graph.

Space Complexity
----------------

The space complexity of the Topological Sort algorithm is:

*   **O(V):** The algorithm requires space to store the in-degree array and the queue.

Key Points for Interviews
-------------------------

*   Topological sort is specifically for directed acyclic graphs (DAGs).
*   Understand the differences between Kahn's algorithm and DFS-based topological sort.
*   Identify how to detect cycles in a graph during the sorting process.
*   Be familiar with time complexity O(V + E) and its implications for large graphs.
*   Practice problems involving task scheduling, build orders, or course prerequisites.