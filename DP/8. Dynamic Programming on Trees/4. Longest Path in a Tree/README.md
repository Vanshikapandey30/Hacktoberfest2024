Longest Path in a Tree Problem
==============================

Problem Definition
------------------

Given a binary tree, the longest path is defined as the maximum number of edges between any two nodes in the tree. This path may or may not pass through the root. The task is to find the length of this longest path.

### Example

*   Input:
    
        
                        1
                       / \
                      2   3
                     / \
                    4   5
                
    
*   Output: `3` (The longest path is 4 -> 2 -> 1 -> 3 or 5 -> 2 -> 1 -> 3)

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) Approach

This approach uses DFS to traverse the tree and calculate the longest path. The length of the longest path will be the maximum distance found between any two nodes.

#### Pseudocode

    function longestPath(root):
        if root is null:
            return 0
    
        maxLength = 0
        function dfs(node):
            nonlocal maxLength
            if node is null:
                return 0
            
            leftDepth = dfs(node.left)
            rightDepth = dfs(node.right)
            
            maxLength = max(maxLength, leftDepth + rightDepth)
            
            return max(leftDepth, rightDepth) + 1
    
        dfs(root)
        return maxLength
    

#### Java Implementation

    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class LongestPathInTree {
        private static int maxLength;
    
        public static int longestPath(TreeNode root) {
            maxLength = 0;
            dfs(root);
            return maxLength;
        }
    
        private static int dfs(TreeNode node) {
            if (node == null) return 0;
            int leftDepth = dfs(node.left);
            int rightDepth = dfs(node.right);
            maxLength = Math.max(maxLength, leftDepth + rightDepth);
            return Math.max(leftDepth, rightDepth) + 1;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            int result = longestPath(root);
            System.out.println("Length of the longest path: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) where n is the number of nodes in the tree.
*   **Space Complexity:** O(h) where h is the height of the tree (for the recursion stack).

### 2\. Iterative DFS Approach

This approach uses an iterative method with a stack to perform DFS without recursion, effectively achieving the same result.

#### Pseudocode

    function longestPathIterative(root):
        if root is null:
            return 0
    
        stack = empty stack
        maxLength = 0
        stack.push(root)
    
        while stack is not empty:
            node = stack.pop()
            if node is not null:
                leftDepth = node.left != null ? longestPathIterative(node.left) : 0
                rightDepth = node.right != null ? longestPathIterative(node.right) : 0
                maxLength = max(maxLength, leftDepth + rightDepth)
                stack.push(node.left)
                stack.push(node.right)
        
        return maxLength
    

#### Java Implementation

    import java.util.Stack;
    
    public class LongestPathInTreeIterative {
        public static int longestPathIterative(TreeNode root) {
            if (root == null) return 0;
    
            Stack stack = new Stack<>();
            stack.push(root);
            int maxLength = 0;
    
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                if (node != null) {
                    int leftDepth = node.left != null ? longestPathIterative(node.left) : 0;
                    int rightDepth = node.right != null ? longestPathIterative(node.right) : 0;
                    maxLength = Math.max(maxLength, leftDepth + rightDepth);
                    stack.push(node.left);
                    stack.push(node.right);
                }
            }
            return maxLength;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            int result = longestPathIterative(root);
            System.out.println("Length of the longest path: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(n) (for the stack)