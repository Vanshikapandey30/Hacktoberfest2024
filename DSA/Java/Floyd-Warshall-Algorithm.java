import java.util.Arrays;

public class FloydWarshallAlgorithm {
    final static int INF = 99999; // Represents infinity

    // Function to implement Floyd-Warshall Algorithm
    void floydWarshall(int graph[][], int V) {
        int dist[][] = new int[V][V];

        // Initialize the solution matrix with the input graph matrix
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        // Applying the Floyd-Warshall algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    // If vertex k is on the shortest path from i to j,
                    // update the value of dist[i][j]
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        // Print the shortest distance matrix
        printSolution(dist, V);
    }

    // Function to print the shortest distance matrix
    void printSolution(int dist[][], int V) {
        System.out.println("Shortest distances between every pair of vertices:");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Driver method to test the algorithm
    public static void main(String[] args) {
        FloydWarshallAlgorithm fwa = new FloydWarshallAlgorithm();
        int graph[][] = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}
        };
        int V = 4; // Number of vertices in the graph

        fwa.floydWarshall(graph, V);
    }
}


// input
// graph = {
//     {0, 5, INF, 10},
//     {INF, 0, 3, INF},
//     {INF, INF, 0, 1},
//     {INF, INF, INF, 0}
// }

