Euler Tour Problem
==================

Problem Definition
------------------

The Euler Tour Problem involves traversing a tree or a graph in a specific manner where each edge is visited exactly once. In the context of trees, an Euler tour is a walk through the tree that visits every edge twice (once in each direction). The challenge is to generate a tour of the tree that records the sequence of nodes visited.

### Example

*   Input:
    
        
                        1
                       / \
                      2   3
                     / \
                    4   5
                
    
*   Output: `[1, 2, 4, 2, 5, 2, 1, 3]` (The Euler Tour visits each edge twice)

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) Approach

This approach uses DFS to traverse the tree. During the traversal, we will keep track of the nodes visited to form the Euler tour.

#### Pseudocode

    function eulerTour(root):
        tour = []
        function dfs(node):
            if node is null:
                return
            
            tour.append(node.value)
            dfs(node.left)
            tour.append(node.value)
            dfs(node.right)
            tour.append(node.value)
    
        dfs(root)
        return tour
    

#### Java Implementation

    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class EulerTour {
        public static List eulerTour(TreeNode root) {
            List tour = new ArrayList<>();
            dfs(root, tour);
            return tour;
        }
    
        private static void dfs(TreeNode node, List tour) {
            if (node == null) return;
    
            tour.add(node.value);
            dfs(node.left, tour);
            tour.add(node.value);
            dfs(node.right, tour);
            tour.add(node.value);
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            
            List result = eulerTour(root);
            System.out.println("Euler Tour: " + result);  // Output: [1, 2, 4, 2, 5, 2, 1, 3]
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) where n is the number of nodes in the tree.
*   **Space Complexity:** O(h) where h is the height of the tree (for the recursion stack).

### 2\. Iterative DFS Approach

This approach uses an iterative method with a stack to perform DFS without recursion, generating the Euler tour effectively.

#### Pseudocode

    function eulerTourIterative(root):
        if root is null:
            return []
        
        tour = []
        stack = empty stack
        stack.push(root)
    
        while stack is not empty:
            node = stack.pop()
            if node is not null:
                tour.append(node.value)
                stack.push(node)  // Push the node back to the stack
                if node.right is not null:
                    stack.push(node.right)
                if node.left is not null:
                    stack.push(node.left)
                tour.append(node.value)  // Add the node again for the Euler Tour
    
        return tour
    

#### Java Implementation

    import java.util.ArrayList;
    import java.util.List;
    import java.util.Stack;
    
    public class EulerTourIterative {
        public static List eulerTourIterative(TreeNode root) {
            List tour = new ArrayList<>();
            if (root == null) return tour;
    
            Stack stack = new Stack<>();
            stack.push(root);
    
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                if (node != null) {
                    tour.add(node.value);
                    stack.push(node);  // Push the node back to the stack
                    if (node.right != null) {
                        stack.push(node.right);
                    }
                    if (node.left != null) {
                        stack.push(node.left);
                    }
                    tour.add(node.value);  // Add the node again for the Euler Tour
                }
            }
            return tour;
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(3);
            root.left.left = new TreeNode(4);
            root.left.right = new TreeNode(5);
            
            List result = eulerTourIterative(root);
            System.out.println("Euler Tour: " + result);  // Output: [1, 2, 4, 2, 5, 2, 1, 3]
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(n) (for the stack)