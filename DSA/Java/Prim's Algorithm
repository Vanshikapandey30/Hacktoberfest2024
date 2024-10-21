import java.util.Arrays;

public class PrimsAlgorithm {
    
    // Number of vertices in the graph
    private static final int V = 5;

    // Function to find the vertex with minimum key value that is not yet included in MST
    int minKey(int[] key, boolean[] mstSet) {
        int min = Integer.MAX_VALUE, minIndex = -1;

        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    // Function to print the constructed MST
    void printMST(int[] parent, int[][] graph) {
        System.out.println("Edge \tWeight");
        for (int i = 1; i < V; i++) {
            System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
        }
    }

    // Function to construct and print MST using Prim's algorithm
    void primMST(int[][] graph) {
        // Array to store the constructed MST
        int[] parent = new int[V];

        // Key values used to pick the minimum weight edge
        int[] key = new int[V];

        // To represent the set of vertices not yet included in MST
        boolean[] mstSet = new boolean[V];

        // Initialize all keys as INFINITE
        Arrays.fill(key, Integer.MAX_VALUE);

        // Start from the first vertex
        key[0] = 0;
        parent[0] = -1; // First node is always the root of MST

        // The MST will have V vertices
        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum key vertex not yet included in MST
            int u = minKey(key, mstSet);

            // Add the picked vertex to the MST Set
            mstSet[u] = true;

            // Update the key value and parent index of the adjacent vertices
            for (int v = 0; v < V; v++) {
                // graph[u][v] is non-zero for adjacent vertices
                // mstSet[v] is false for vertices not yet included in MST
                // Update the key only if graph[u][v] is smaller than key[v]
                if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        // Print the MST
        printMST(parent, graph);
    }

    public static void main(String[] args) {
        PrimsAlgorithm t = new PrimsAlgorithm();
        
        // Example graph represented as an adjacency matrix
        int[][] graph = { { 0, 2, 0, 6, 0 },
                          { 2, 0, 3, 8, 5 },
                          { 0, 3, 0, 0, 7 },
                          { 6, 8, 0, 0, 9 },
                          { 0, 5, 7, 9, 0 } };
        
        // Execute Prim's algorithm to find MST
        t.primMST(graph);
    }
}
