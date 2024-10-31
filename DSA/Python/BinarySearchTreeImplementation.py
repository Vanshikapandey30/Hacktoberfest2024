class Node:
    def __init__(self, data):
        """Initialize a BST node with data and null left/right pointers"""
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        """Initialize an empty BST"""
        self.root = None
    
    def insert(self, data):
        """Insert a new node with given data"""
        if not self.root:
            self.root = Node(data)
        else:
            self._insert_recursive(self.root, data)
    
    def _insert_recursive(self, node, data):
        """Helper method for recursive insertion"""
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert_recursive(node.left, data)
        else:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert_recursive(node.right, data)
    
    def search(self, data):
        """Search for a value in the BST"""
        return self._search_recursive(self.root, data)
    
    def _search_recursive(self, node, data):
        """Helper method for recursive search"""
        if node is None or node.data == data:
            return node
        
        if data < node.data:
            return self._search_recursive(node.left, data)
        return self._search_recursive(node.right, data)
    
    def delete(self, data):
        """Delete a node with given data"""
        self.root = self._delete_recursive(self.root, data)
    
    def _delete_recursive(self, node, data):
        """Helper method for recursive deletion"""
        if node is None:
            return node
        
        # Find the node to delete
        if data < node.data:
            node.left = self._delete_recursive(node.left, data)
        elif data > node.data:
            node.right = self._delete_recursive(node.right, data)
        else:
            # Node with only one child or no child
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            
            # Node with two children
            # Get the inorder successor (smallest in the right subtree)
            temp = self._min_value_node(node.right)
            node.data = temp.data
            node.right = self._delete_recursive(node.right, temp.data)
        
        return node
    
    def _min_value_node(self, node):
        """Helper method to find the minimum value node in a subtree"""
        current = node
        while current.left:
            current = current.left
        return current
    
    # Tree Traversal Methods
    def inorder(self):
        """Inorder traversal: Left -> Root -> Right"""
        result = []
        self._inorder_recursive(self.root, result)
        return result
    
    def _inorder_recursive(self, node, result):
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.data)
            self._inorder_recursive(node.right, result)
    
    def preorder(self):
        """Preorder traversal: Root -> Left -> Right"""
        result = []
        self._preorder_recursive(self.root, result)
        return result
    
    def _preorder_recursive(self, node, result):
        if node:
            result.append(node.data)
            self._preorder_recursive(node.left, result)
            self._preorder_recursive(node.right, result)
    
    def postorder(self):
        """Postorder traversal: Left -> Right -> Root"""
        result = []
        self._postorder_recursive(self.root, result)
        return result
    
    def _postorder_recursive(self, node, result):
        if node:
            self._postorder_recursive(node.left, result)
            self._postorder_recursive(node.right, result)
            result.append(node.data)
    
    def height(self):
        """Get the height of the tree"""
        return self._height_recursive(self.root)
    
    def _height_recursive(self, node):
        if not node:
            return 0
        left_height = self._height_recursive(node.left)
        right_height = self._height_recursive(node.right)
        return max(left_height, right_height) + 1
        
# Create a new BST
bst = BinarySearchTree()

# Insert some values
bst.insert(50)
bst.insert(30)
bst.insert(70)
bst.insert(20)
bst.insert(40)
bst.insert(60)
bst.insert(80)

# Different tree traversals
print("Inorder traversal:", bst.inorder())       # [20, 30, 40, 50, 60, 70, 80]
print("Preorder traversal:", bst.preorder())     # [50, 30, 20, 40, 70, 60, 80]
print("Postorder traversal:", bst.postorder())   # [20, 40, 30, 60, 80, 70, 50]

# Search for a value
node = bst.search(30)
print("Found:", node.data if node else "Not found")  # Found: 30

# Get tree height
print("Tree height:", bst.height())  # 3

# Delete a node
bst.delete(30)
print("After deletion:", bst.inorder())  # [20, 40, 50, 60, 70, 80]
