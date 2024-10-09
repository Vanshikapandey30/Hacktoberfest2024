Path Queries in Trees
=====================

Problem Definition
------------------

The Path Queries in Trees problem involves finding the properties of paths between two nodes in a tree. Given a tree and two nodes, the objective is to answer queries about the path between these nodes, such as the sum of weights on the path or the maximum value on the path.

### Example

*   Input Tree:
    
        
                        1
                       / \
                      2   3
                     / \   \
                    4   5   6
                
    
*   Query: Find the sum of weights from node 4 to node 5.
    
        
                Path: 4 -> 2 -> 5
                Sum = weight(4) + weight(2) + weight(5) = 0 + 1 + 0 = 1
                
    

Solution Approaches
-------------------

### 1\. Depth First Search (DFS) Approach

This approach uses DFS to traverse the tree and preprocess the necessary information to answer the queries efficiently.

#### Pseudocode

    function dfs(node, parent):
        depth[node] = depth[parent] + 1
        for each child of node:
            if child != parent:
                dfs(child, node)
    
    function preprocess():
        initialize depth and other properties
        dfs(root, null)
    
    function query(u, v):
        # Find the lowest common ancestor (LCA) and compute the path properties
    

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
    
    public class PathQueriesInTree {
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
    
        public static int query(TreeNode u, TreeNode v) {
            // Implement the logic to find the LCA and compute the desired properties
            return 0; // Placeholder
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
            System.out.println(query(node4, node5)); // Output will depend on the implementation of query
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) for preprocessing, where n is the number of nodes.
*   **Space Complexity:** O(n) for storing depth and other properties.

### 2\. Lowest Common Ancestor (LCA) Approach

Using the LCA, we can quickly find the properties of the path by breaking it down into two subpaths: from the first node to the LCA and from the LCA to the second node.

#### Pseudocode

    function findLCA(u, v):
        # Logic to find the LCA of nodes u and v
    
    function query(u, v):
        lca = findLCA(u, v)
        path_weight = pathWeight(u, lca) + pathWeight(v, lca) - weight(lca)
    

#### Java Implementation

    public static TreeNode findLCA(TreeNode u, TreeNode v) {
        // Implement the logic to find the LCA
        return null; // Placeholder
    }
    
    public static int pathWeight(TreeNode u, TreeNode ancestor) {
        // Implement logic to calculate path weight from u to ancestor
        return 0; // Placeholder
    }
    
    public static int query(TreeNode u, TreeNode v) {
        TreeNode lca = findLCA(u, v);
        int pathWeight = pathWeight(u, lca) + pathWeight(v, lca);
        return pathWeight; // Return the computed weight
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) for preprocessing and O(log n) for each query.
*   **Space Complexity:** O(n) for storing parent pointers for LCA calculation.