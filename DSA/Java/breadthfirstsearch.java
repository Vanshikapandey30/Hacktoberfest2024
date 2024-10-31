public void bfs(int start, List<List<Integer>> adjList) {
    boolean[] visited = new boolean[adjList.size()];
    Queue<Integer> queue = new LinkedList<>();
    queue.add(start);
    visited[start] = true;
    while (!queue.isEmpty()) {
        int node = queue.poll();
        System.out.print(node + " ");
        for (int neighbor : adjList.get(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.add(neighbor);
            }
        }
    }
}
