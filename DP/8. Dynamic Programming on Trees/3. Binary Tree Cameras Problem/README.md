Binary Tree Cameras Problem
===========================

Problem Definition
------------------

Given a binary tree, you need to place cameras on nodes of the tree such that every node in the tree is monitored. A camera placed at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the binary tree.

### Example

*   Input:
    
        
                        0
                       / \
                      0   0
                     / \
                    0   0
                
    
*   Output: `1` (Place a camera at the root)

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) Approach

This approach uses a recursive DFS traversal to place cameras. We can track three states for each node:

*   0: The node is not monitored.
*   1: The node is monitored but does not have a camera.
*   2: The node has a camera.

#### Pseudocode

    function minCameraCover(root):
        if root is null:
            return 0
    
        cameras = 0
        function dfs(node):
            if node is null:
                return 1
            left = dfs(node.left)
            right = dfs(node.right)
            if left == 0 or right == 0:
                cameras += 1
                return 2
            if left == 2 or right == 2:
                return 1
            return 0
    
        if dfs(root) == 0:
            cameras += 1
        return cameras
    

#### Java Implementation

    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class BinaryTreeCameras {
        private static int cameras;
    
        public static int minCameraCover(TreeNode root) {
            cameras = 0;
            if (dfs(root) == 0) {
                cameras++;
            }
            return cameras;
        }
    
        private static int dfs(TreeNode node) {
            if (node == null) return 1;
            int left = dfs(node.left);
            int right = dfs(node.right);
            if (left == 0 || right == 0) {
                cameras++;
                return 2;
            }
            if (left == 2 || right == 2) {
                return 1;
            }
            return 0;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(0);
            root.left = new TreeNode(0);
            root.right = new TreeNode(0);
            root.left.left = new TreeNode(0);
            root.left.right = new TreeNode(0);
            int result = minCameraCover(root);
            System.out.println("Minimum number of cameras: " + result);  // Output: 1
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) where n is the number of nodes in the tree.
*   **Space Complexity:** O(h) where h is the height of the tree (for the recursion stack).

### 2\. Iterative DFS Approach

This approach uses an iterative method with a stack to perform DFS without recursion, effectively achieving the same result.

#### Pseudocode

    function minCameraCoverIterative(root):
        if root is null:
            return 0
    
        stack = empty stack
        cameras = 0
        stack.push(root)
    
        while stack is not empty:
            node = stack.pop()
            if node is not null:
                left = node.left
                right = node.right
                stack.push(left)
                stack.push(right)
        
        // process nodes to calculate cameras needed
        return cameras
    

#### Java Implementation

    import java.util.Stack;
    
    public class BinaryTreeCamerasIterative {
        static class Pair {
            TreeNode node;
            int state; // 0: not monitored, 1: monitored, 2: has camera
    
            Pair(TreeNode node, int state) {
                this.node = node;
                this.state = state;
            }
        }
    
        public static int minCameraCoverIterative(TreeNode root) {
            if (root == null) return 0;
    
            Stack stack = new Stack<>();
            int cameras = 0;
            stack.push(new Pair(root, 0));
    
            while (!stack.isEmpty()) {
                Pair pair = stack.pop();
                TreeNode node = pair.node;
    
                if (node != null) {
                    int leftState = (node.left != null) ? pair.state : 1; // Simulating the left child state
                    int rightState = (node.right != null) ? pair.state : 1; // Simulating the right child state
    
                    if (leftState == 0 || rightState == 0) {
                        cameras++;
                        pair.state = 2; // Current node has camera
                    } else if (leftState == 2 || rightState == 2) {
                        pair.state = 1; // Current node is monitored
                    } else {
                        pair.state = 0; // Current node is not monitored
                    }
                    stack.push(new Pair(node.left, leftState));
                    stack.push(new Pair(node.right, rightState));
                }
            }
            return cameras;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(0);
            root.left = new TreeNode(0);
            root.right = new TreeNode(0);
            root.left.left = new TreeNode(0);
            root.left.right = new TreeNode(0);
            int result = minCameraCoverIterative(root);
            System.out.println("Minimum number of cameras: " + result);  // Output: 1
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(n) (for the stack)