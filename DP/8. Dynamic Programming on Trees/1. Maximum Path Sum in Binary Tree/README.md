Maximum Path Sum in Binary Tree
===============================

Problem Definition
------------------

The Maximum Path Sum in Binary Tree problem involves finding the maximum sum of values along any path from a node to any of its descendants. A path can start and end at any node in the tree.

### Example

*   Input:
    
        
                        1
                       / \
                      2   3
                
    
*   Output: `6` (The path is 2 → 1 → 3)

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) Approach

This approach uses a recursive DFS traversal to calculate the maximum path sum. At each node, the function calculates the maximum path sum that can be obtained by including the node and either of its left or right child.

#### Pseudocode

    function maxPathSum(root):
        maxSum = -∞
        
        function dfs(node):
            if node is null:
                return 0
            left = max(dfs(node.left), 0)
            right = max(dfs(node.right), 0)
            currentMax = node.value + left + right
            maxSum = max(maxSum, currentMax)
            return node.value + max(left, right)
    
        dfs(root)
        return maxSum
    

#### Java Implementation

    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class MaximumPathSumBinaryTree {
        private static int maxSum;
    
        public static int maxPathSum(TreeNode root) {
            maxSum = Integer.MIN_VALUE;
            dfs(root);
            return maxSum;
        }
    
        private static int dfs(TreeNode node) {
            if (node == null) return 0;
            int left = Math.max(dfs(node.left), 0);
            int right = Math.max(dfs(node.right), 0);
            int currentMax = node.value + left + right;
            maxSum = Math.max(maxSum, currentMax);
            return node.value + Math.max(left, right);
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            int result = maxPathSum(root);
            System.out.println("Maximum Path Sum: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) where n is the number of nodes in the tree.
*   **Space Complexity:** O(h) where h is the height of the tree (for the recursion stack).

### 2\. Iterative DFS Approach

This approach uses an iterative DFS with a stack to achieve the same result without recursion.

#### Pseudocode

    function maxPathSumIterative(root):
        if root is null:
            return 0
    
        stack = empty stack
        maxSum = -∞
        stack.push((root, 0))  # (node, path sum)
        
        while stack is not empty:
            node, currentSum = stack.pop()
            if node is not null:
                left = Math.max(0, currentSum + node.left.value)
                right = Math.max(0, currentSum + node.right.value)
                maxSum = max(maxSum, currentSum + node.value)
                stack.push((node.left, left))
                stack.push((node.right, right))
        
        return maxSum
    

#### Java Implementation

    import java.util.Stack;
    
    public class MaximumPathSumBinaryTreeIterative {
        static class Pair {
            TreeNode node;
            int currentSum;
    
            Pair(TreeNode node, int currentSum) {
                this.node = node;
                this.currentSum = currentSum;
            }
        }
    
        public static int maxPathSumIterative(TreeNode root) {
            if (root == null) return 0;
    
            Stack stack = new Stack<>();
            int maxSum = Integer.MIN_VALUE;
            stack.push(new Pair(root, 0));
    
            while (!stack.isEmpty()) {
                Pair pair = stack.pop();
                TreeNode node = pair.node;
                int currentSum = pair.currentSum;
    
                if (node != null) {
                    currentSum += node.value;
                    maxSum = Math.max(maxSum, currentSum);
    
                    // Push children to the stack
                    stack.push(new Pair(node.left, currentSum));
                    stack.push(new Pair(node.right, currentSum));
                }
            }
            return maxSum;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            int result = maxPathSumIterative(root);
            System.out.println("Maximum Path Sum: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(n) (for the stack)

### 3\. Using Dynamic Programming

This approach involves using dynamic programming, although it is less common for this problem due to the tree structure. However, we can keep track of maximum sums at each node.

#### Pseudocode

    function maxPathSumDP(root):
        if root is null:
            return 0
        
        left = maxPathSumDP(root.left)
        right = maxPathSumDP(root.right)
    
        max_single = max(max(left, right) + root.value, root.value)
        max_top = max(max_single, left + right + root.value)
    
        global maxSum
        maxSum = max(maxSum, max_top)
        return max_single
    

#### Java Implementation

    public class MaximumPathSumBinaryTreeDP {
        private static int maxSum;
    
        public static int maxPathSum(TreeNode root) {
            maxSum = Integer.MIN_VALUE;
            maxPathSumDP(root);
            return maxSum;
        }
    
        private static int maxPathSumDP(TreeNode node) {
            if (node == null) return 0;
    
            int left = maxPathSumDP(node.left);
            int right = maxPathSumDP(node.right);
    
            int maxSingle = Math.max(Math.max(left, right) + node.value, node.value);
            int maxTop = Math.max(maxSingle, left + right + node.value);
    
            maxSum = Math.max(maxSum, maxTop);
            return maxSingle;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            int result = maxPathSum(root);
            System.out.println("Maximum Path Sum: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(h) (for recursion stack)