Diameter of Binary Tree
=======================

Problem Definition
------------------

The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree. This path may or may not pass through the root node. The length of a path is the number of edges between the nodes.

### Example

*   Input:
    
        
                        1
                       / \
                      2   3
                     / \
                    4   5
                
    
*   Output: `3` (The path is 4 → 2 → 1 → 3)

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) Approach

This approach uses a recursive DFS traversal to calculate the diameter. At each node, we calculate the height of the left and right subtrees, and update the maximum diameter encountered.

#### Pseudocode

    function diameterOfBinaryTree(root):
        maxDiameter = 0
    
        function dfs(node):
            if node is null:
                return 0
            leftHeight = dfs(node.left)
            rightHeight = dfs(node.right)
            maxDiameter = max(maxDiameter, leftHeight + rightHeight)
            return max(leftHeight, rightHeight) + 1
    
        dfs(root)
        return maxDiameter
    

#### Java Implementation

    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class DiameterOfBinaryTree {
        private static int maxDiameter;
    
        public static int diameterOfBinaryTree(TreeNode root) {
            maxDiameter = 0;
            dfs(root);
            return maxDiameter;
        }
    
        private static int dfs(TreeNode node) {
            if (node == null) return 0;
            int leftHeight = dfs(node.left);
            int rightHeight = dfs(node.right);
            maxDiameter = Math.max(maxDiameter, leftHeight + rightHeight);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            int result = diameterOfBinaryTree(root);
            System.out.println("Diameter of Binary Tree: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) where n is the number of nodes in the tree.
*   **Space Complexity:** O(h) where h is the height of the tree (for the recursion stack).

### 2\. Iterative DFS Approach

This approach utilizes an iterative method using a stack to find the diameter without recursion.

#### Pseudocode

    function diameterOfBinaryTreeIterative(root):
        if root is null:
            return 0
    
        stack = empty stack
        maxDiameter = 0
        stack.push((root, 0))  # (node, height)
        
        while stack is not empty:
            node, height = stack.pop()
            if node is not null:
                leftHeight = height(node.left)
                rightHeight = height(node.right)
                maxDiameter = max(maxDiameter, leftHeight + rightHeight)
                stack.push((node.left, leftHeight))
                stack.push((node.right, rightHeight))
        
        return maxDiameter
    

#### Java Implementation

    import java.util.Stack;
    
    public class DiameterOfBinaryTreeIterative {
        static class Pair {
            TreeNode node;
            int height;
    
            Pair(TreeNode node, int height) {
                this.node = node;
                this.height = height;
            }
        }
    
        public static int diameterOfBinaryTreeIterative(TreeNode root) {
            if (root == null) return 0;
    
            Stack stack = new Stack<>();
            int maxDiameter = 0;
            stack.push(new Pair(root, 0));
    
            while (!stack.isEmpty()) {
                Pair pair = stack.pop();
                TreeNode node = pair.node;
                int height = pair.height;
    
                if (node != null) {
                    int leftHeight = getHeight(node.left);
                    int rightHeight = getHeight(node.right);
                    maxDiameter = Math.max(maxDiameter, leftHeight + rightHeight);
    
                    stack.push(new Pair(node.left, leftHeight));
                    stack.push(new Pair(node.right, rightHeight));
                }
            }
            return maxDiameter;
        }
    
        private static int getHeight(TreeNode node) {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            int result = diameterOfBinaryTreeIterative(root);
            System.out.println("Diameter of Binary Tree: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(n) (for the stack)

### 3\. Using Dynamic Programming (DP)

In this approach, we can also store the maximum diameter calculated at each node using dynamic programming principles.

#### Pseudocode

    function diameterOfBinaryTreeDP(root):
        if root is null:
            return 0
    
        leftDiameter = diameterOfBinaryTreeDP(root.left)
        rightDiameter = diameterOfBinaryTreeDP(root.right)
    
        maxSingle = max(leftDiameter, rightDiameter)
        maxTop = maxSingle + root.value
    
        global maxDiameter
        maxDiameter = max(maxDiameter, maxTop)
        return maxSingle
    

#### Java Implementation

    public class DiameterOfBinaryTreeDP {
        private static int maxDiameter;
    
        public static int diameterOfBinaryTree(TreeNode root) {
            maxDiameter = 0;
            diameterOfBinaryTreeDP(root);
            return maxDiameter;
        }
    
        private static int diameterOfBinaryTreeDP(TreeNode node) {
            if (node == null) return 0;
    
            int leftDiameter = diameterOfBinaryTreeDP(node.left);
            int rightDiameter = diameterOfBinaryTreeDP(node.right);
    
            int maxSingle = Math.max(leftDiameter, rightDiameter);
            maxDiameter = Math.max(maxDiameter, leftDiameter + rightDiameter);
            return maxSingle + 1;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            int result = diameterOfBinaryTree(root);
            System.out.println("Diameter of Binary Tree: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(h) (for recursion stack)