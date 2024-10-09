Tree Flattening Problem
=======================

Problem Definition
------------------

The Tree Flattening Problem involves transforming a binary tree into a flat linked list. The linked list should represent the tree's nodes in a specific order, typically pre-order traversal. This is commonly done by rearranging the pointers of the nodes without using extra space for additional nodes.

### Example

*   Input:
    
        
                        1
                       / \
                      2   5
                     / \
                    3   4
                
    
*   Output:
    
        
                1 -> 2 -> 3 -> 4 -> 5
                
    

Solution Approaches
-------------------

### 1\. Recursive Approach

In this approach, we recursively visit each node and rearrange the pointers to flatten the tree.

#### Pseudocode

    function flatten(node):
        if node is null:
            return
        
        flatten(node.left)
        flatten(node.right)
    
        if node.left is not null:
            temp = node.right
            node.right = node.left
            node.left = null
            while node.right is not null:
                node = node.right
            node.right = temp
    

#### Java Implementation

    class TreeNode {
        int value;
        TreeNode left, right;
    
        TreeNode(int val) {
            value = val;
            left = right = null;
        }
    }
    
    public class TreeFlattening {
        public static void flatten(TreeNode root) {
            if (root == null) return;
    
            flatten(root.left);
            flatten(root.right);
    
            if (root.left != null) {
                TreeNode temp = root.right;
                root.right = root.left;
                root.left = null;
    
                TreeNode current = root.right;
                while (current.right != null) {
                    current = current.right;
                }
                current.right = temp;
            }
        }
    
        public static void printList(TreeNode node) {
            while (node != null) {
                System.out.print(node.value + " -> ");
                node = node.right;
            }
            System.out.println("null");
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(5);
            root.left.left = new TreeNode(3);
            root.left.right = new TreeNode(4);
            
            flatten(root);
            printList(root); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> null
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n), where n is the number of nodes in the tree.
*   **Space Complexity:** O(h), where h is the height of the tree due to recursive call stack.

### 2\. Iterative Approach (Using Stack)

This approach uses a stack to simulate the recursive behavior of tree traversal. It processes nodes in pre-order and rearranges their pointers.

#### Pseudocode

    function flatten(root):
        if root is null:
            return
        
        stack = []
        stack.push(root)
        
        while stack is not empty:
            node = stack.pop()
            
            if node.right is not null:
                stack.push(node.right)
            if node.left is not null:
                stack.push(node.left)
            
            if stack is not empty:
                node.right = stack.peek()
            node.left = null
    

#### Java Implementation

    import java.util.Stack;
    
    public class TreeFlatteningIterative {
        public static void flatten(TreeNode root) {
            if (root == null) return;
    
            Stack stack = new Stack<>();
            stack.push(root);
            
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                
                if (node.right != null) {
                    stack.push(node.right);
                }
                if (node.left != null) {
                    stack.push(node.left);
                }
                
                if (!stack.isEmpty()) {
                    node.right = stack.peek();
                }
                node.left = null;
            }
        }
    
        public static void main(String[] args) {
            TreeNode root = new TreeNode(1);
            root.left = new TreeNode(2);
            root.right = new TreeNode(5);
            root.left.left = new TreeNode(3);
            root.left.right = new TreeNode(4);
            
            flatten(root);
            printList(root); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> null
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n), where n is the number of nodes in the tree.
*   **Space Complexity:** O(h), where h is the height of the tree due to the stack used for traversal.