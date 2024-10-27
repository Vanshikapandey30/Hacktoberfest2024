// Function to find the shortest path 
public int findShortestPath(int[][] graph, int start, int end) 
{ 
    // Initialize the result 
    int result = 0; 
  
    // Queue to store the nodes to be processed 
    Queue<Integer> queue = new LinkedList<>(); 
  
    // Add the start node to the queue 
    queue.add(start); 
  
    // While the queue is not empty 
    while (!queue.isEmpty()) { 
  
        // Get the node at the front of the queue 
        int current = queue.poll(); 
  
        // Check if the current node is the end node 
        if (current == end) { 
            break; 
        } 
  
        // Iterate over all adjacent nodes 
        for (int i = 0; i < graph[current].length; i++) { 
  
            // Check if the adjacent node is valid and not visited 
            if (graph[current][i] != 0 && visited[i] == false) { 
  
                // Add the adjacent node to the queue 
                queue.add(i); 
  
                // Update the result 
                result += graph[current][i]; 
  
                // Mark the node as visited 
                visited[i] = true; 
            } 
        } 
    } 
  
    // Return the result 
    return result; 
} 
