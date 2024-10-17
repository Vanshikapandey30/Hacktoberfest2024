/**
 * Floyd-Warshall algorithm 
  The Floyd-Warshall algorithm is a graph analysis technique that efficiently 
 * finds the shortest paths between all pairs of vertices in a weighted graph. 
 * It works by systematically considering each vertex as a potential intermediate
 *  point in the path between every pair of vertices, updating the shortest known
 *  distances accordingly. This algorithm can handle both positive and negative
 *  edge weights (as long as there are no negative cycles) and is particularly
 *  useful in applications such as network routing, where comprehensive path
 *  information is required. With a time complexity of O(V³), where V is the 
 * number of vertices, it provides a complete matrix of shortest distances
 *  between all vertices in the graph, making it invaluable for scenarios 
 * requiring all-pairs shortest path information.
 */
 








package DSA.Java;

public class FloydWarshall_Algo {
    private static final int INF = Integer.MAX_VALUE / 2; // Avoid overflow

    public static int[][] floydWarshall(int[][] graph) {
        int V = graph.length;
        int[][] dist = new int[V][V];

        // Initialize the distance matrix
        for (int i = 0; i < V; i++) {
            System.arraycopy(graph[i], 0, dist[i], 0, V);
        }

        // Main algorithm
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                if (dist[i][k] == INF) continue; // Skip if no path from i to k
                for (int j = 0; j < V; j++) {
                    if (dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        int V = 4; // Number of vertices
        int[][] graph = {
            {0, 3, INF, 5},
            {2, 0, INF, 4},
            {INF, 1, 0, INF},
            {INF, INF, 2, 0}
        };

        int[][] shortestDistances = floydWarshall(graph);

        // Print the shortest distances
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (shortestDistances[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(shortestDistances[i][j] + "   ");
            }
            System.out.println();
        }
    }
}