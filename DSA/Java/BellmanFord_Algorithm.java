import java.util.*;
import java.util.Arrays;

class BellmanFord {
    class Edge {
        int source, destination, weight;

        Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }

    int vertices, edges;
    Edge[] edgeList;

    BellmanFord(int vertices, int edges) {
        this.vertices = vertices;
        this.edges = edges;
        edgeList = new Edge[edges];
    }

    void addEdge(int index, int source, int destination, int weight) {
        edgeList[index] = new Edge(source, destination, weight);
    }

    int[] bellmanFord(int source) {
        int[] distances = new int[vertices];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;

        // Relax all edges (vertices-1) times
        for (int i = 0; i < vertices - 1; i++) {
            for (Edge edge : edgeList) {
                if (distances[edge.source] != Integer.MAX_VALUE &&
                    distances[edge.source] + edge.weight < distances[edge.destination]) {
                    distances[edge.destination] = distances[edge.source] + edge.weight;
                }
            }
        }

        // Check for negative weight cycles
        for (Edge edge : edgeList) {
            if (distances[edge.source] != Integer.MAX_VALUE &&
                distances[edge.source] + edge.weight < distances[edge.destination]) {
                System.out.println("Graph contains negative weight cycle");
                return null;
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        int vertices = 5;
        int edges = 8;

        BellmanFord graph = new BellmanFord(vertices, edges);

        // Adding edges
        graph.addEdge(0, 0, 1, -1);
        graph.addEdge(1, 0, 2, 4);
        graph.addEdge(2, 1, 2, 3);
        graph.addEdge(3, 1, 3, 2);
        graph.addEdge(4, 1, 4, 2);
        graph.addEdge(5, 3, 2, 5);
        graph.addEdge(6, 3, 1, 1);
        graph.addEdge(7, 4, 3, -3);

        // Running Bellman-Ford
        int[] distances = graph.bellmanFord(0);

        // Print shortest distances
        if (distances != null) {
            System.out.println("Vertex Distance from Source:");
            for (int i = 0; i < distances.length; i++) {
                System.out.println("Vertex " + i + ": " + distances[i]);
            }
        }
    }
}
