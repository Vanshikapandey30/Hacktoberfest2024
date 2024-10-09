Subtree Queries Problem
=======================

Problem Definition
------------------

The Subtree Queries Problem involves answering queries about the nodes within a subtree of a given tree structure. Each query may require the sum, maximum, or other aggregate statistics of the values of nodes in a specified subtree.

### Example

*   Input:
    
        
                        1(5)
                       / \
                    2(3)  3(8)
                   / \
                4(6)  5(2)
                
    
*   Query: Find the sum of values in the subtree rooted at node 2. `Output: 11` (3 + 6 + 2 = 11)

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) Approach

This approach uses DFS to traverse the tree and precomputes the sum of values in each subtree. This allows each query to be answered in constant time.

#### Pseudocode

    function preprocess(node):
        if node is null:
            return 0
        leftSum = preprocess(node.left)
        rightSum = preprocess(node.right)
        subtreeSum[node] = node.value + leftSum + rightSum
        return subtreeSum[node]
    
    function query(node):
        return subtreeSum[node]
    

#### Java Implementation

    import java.util.HashMap;
    import java.util.Map;
    
    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class SubtreeQueries {
        private static Map subtreeSum = new HashMap<>();
    
        public static void preprocess(TreeNode root) {
            if (root == null) return;
            
            int leftSum = preprocess(root.left);
            int rightSum = preprocess(root.right);
            subtreeSum.put(root, root.value + leftSum + rightSum);
            return subtreeSum.get(root);
        }
    
        public static int query(TreeNode node) {
            return subtreeSum.getOrDefault(node, 0);
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(5);
            root.left = new TreeNode(3);
            root.right = new TreeNode(8);
            root.left.left = new TreeNode(6);
            root.left.right = new TreeNode(2);
            
            preprocess(root);
            
            int sumAtNode2 = query(root.left);  // Querying subtree rooted at node with value 3
            System.out.println("Sum of subtree rooted at node 2: " + sumAtNode2); // Output: 11
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) for preprocessing the tree, O(1) for each query.
*   **Space Complexity:** O(n) for storing subtree sums in a map.

### 2\. Dynamic Programming Approach

In this approach, we can maintain a parent-child relationship to facilitate easier access to a node’s subtree during queries.

#### Pseudocode

    function preprocess(node):
        if node is null:
            return 0
        leftSum = preprocess(node.left)
        rightSum = preprocess(node.right)
        subtreeSum[node] = node.value + leftSum + rightSum
        return subtreeSum[node]
    
    function query(node):
        return subtreeSum[node]
    

#### Java Implementation

    import java.util.HashMap;
    import java.util.Map;
    
    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class SubtreeQueriesDynamic {
        private static Map subtreeSum = new HashMap<>();
    
        public static void preprocess(TreeNode root) {
            if (root == null) return;
            
            int leftSum = preprocess(root.left);
            int rightSum = preprocess(root.right);
            subtreeSum.put(root, root.value + leftSum + rightSum);
            return subtreeSum.get(root);
        }
    
        public static int query(TreeNode node) {
            return subtreeSum.getOrDefault(node, 0);
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(5);
            root.left = new TreeNode(3);
            root.right = new TreeNode(8);
            root.left.left = new TreeNode(6);
            root.left.right = new TreeNode(2);
            
            preprocess(root);
            
            int sumAtNode2 = query(root.left);  // Querying subtree rooted at node with value 3
            System.out.println("Sum of subtree rooted at node 2: " + sumAtNode2); // Output: 11
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) for preprocessing the tree, O(1) for each query.
*   **Space Complexity:** O(n) for storing subtree sums in a map.