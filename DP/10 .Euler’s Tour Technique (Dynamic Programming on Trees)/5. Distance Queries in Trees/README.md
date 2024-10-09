Distance Queries in Trees
=========================

Problem Definition
------------------

The Distance Queries in Trees problem involves finding the distance between two nodes in a tree. The distance is defined as the number of edges in the shortest path connecting the two nodes.

### Example

*   Input Tree:
    
        
                        1
                       / \
                      2   3
                     / \   \
                    4   5   6
                
    
*   Query: Find the distance between nodes 4 and 5.
    
        
                Path: 4 -> 2 -> 5
                Distance = 2
                
    

Solution Approaches
-------------------

### 1\. Depth First Search (DFS) Approach

This approach uses DFS to preprocess the necessary information to efficiently calculate the distances between any two nodes.

#### Pseudocode

    function dfs(node, parent):
        depth[node] = depth[parent] + 1
        for each child of node:
            if child != parent:
                dfs(child, node)
    
    function preprocess():
        initialize depth and other properties
        dfs(root, null)
    
    function distance(u, v):
        lca = findLCA(u, v)
        return depth[u] + depth[v] - 2 * depth[lca]
    

#### Java Implementation

    import java.util.*;
    
    class TreeNode {
        int value;
        List children;
    
        TreeNode(int val) {
            value = val;
            children = new ArrayList<>();
        }
    }
    
    public class DistanceQueriesInTree {
        static int[] depth;
        static TreeNode root;
    
        public static void dfs(TreeNode node, TreeNode parent) {
            if (parent != null) {
                depth[node.value] = depth[parent.value] + 1;
            }
            for (TreeNode child : node.children) {
                if (child != parent) {
                    dfs(child, node);
                }
            }
        }
    
        public static void preprocess() {
            depth = new int[100]; // Assuming a maximum of 100 nodes
            dfs(root, null);
        }
    
        public static TreeNode findLCA(TreeNode u, TreeNode v) {
            // Implement the logic to find the LCA
            return null; // Placeholder
        }
    
        public static int distance(TreeNode u, TreeNode v) {
            TreeNode lca = findLCA(u, v);
            return depth[u.value] + depth[v.value] - 2 * depth[lca.value];
        }
    
        public static void main(String[] args) {
            root = new TreeNode(1);
            TreeNode node2 = new TreeNode(2);
            TreeNode node3 = new TreeNode(3);
            TreeNode node4 = new TreeNode(4);
            TreeNode node5 = new TreeNode(5);
            TreeNode node6 = new TreeNode(6);
    
            root.children.add(node2);
            root.children.add(node3);
            node2.children.add(node4);
            node2.children.add(node5);
            node3.children.add(node6);
    
            preprocess();
            // Example query
            System.out.println(distance(node4, node5)); // Output will depend on the implementation of distance
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) for preprocessing, where n is the number of nodes. O(log n) for each distance query.
*   **Space Complexity:** O(n) for storing depth and other properties.

### 2\. Lowest Common Ancestor (LCA) Approach

Using the LCA, we can quickly find the distance between two nodes by determining the distance from each node to the LCA and summing these distances.

#### Pseudocode

    function findLCA(u, v):
        # Logic to find the LCA of nodes u and v
    
    function distance(u, v):
        lca = findLCA(u, v)
        return depth[u] + depth[v] - 2 * depth[lca]
    

#### Java Implementation

    public static TreeNode findLCA(TreeNode u, TreeNode v) {
        // Implement the logic to find the LCA
        return null; // Placeholder
    }
    
    public static int distance(TreeNode u, TreeNode v) {
        TreeNode lca = findLCA(u, v);
        return depth[u.value] + depth[v.value] - 2 * depth[lca.value];
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) for preprocessing and O(log n) for each distance query.
*   **Space Complexity:** O(n) for storing parent pointers for LCA calculation.