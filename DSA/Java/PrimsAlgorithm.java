import java.util.*;

public class PrimsAlgorithm {
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    public static void primsAlgorithm(int[][] graph) {
        int vertices = graph.length;
        boolean[] visited = new boolean[vertices];
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        
        // Start from the first vertex
        visited[0] = true;
        for (int i = 0; i < vertices; i++) {
            if (graph[0][i] != 0) {
                pq.add(new Edge(0, i, graph[0][i]));
            }
        }

        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            if (visited[edge.dest]) continue;

            // Mark the vertex as visited
            visited[edge.dest] = true;
            System.out.println("Edge: (" + edge.src + " - " + edge.dest + ") Weight: " + edge.weight);

            // Add new edges to the priority queue
            for (int i = 0; i < vertices; i++) {
                if (!visited[i] && graph[edge.dest][i] != 0) {
                    pq.add(new Edge(edge.dest, i, graph[edge.dest][i]));
                }
            }
        }
    }

    public static void main(String[] args) {
        // Example graph represented as an adjacency matrix
        int[][] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };
        primsAlgorithm(graph);
    }
}
