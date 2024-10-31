
class Node:
    def __init__(self, data):
        """Initialize a node with data and null next pointer"""
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        """Initialize an empty linked list"""
        self.head = None
    
    def append(self, data):
        """Add a new node at the end of the linked list"""
        new_node = Node(data)
        
        # If list is empty, make new node the head
        if not self.head:
            self.head = new_node
            return
            
        # Traverse to the last node
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def prepend(self, data):
        """Add a new node at the beginning of the linked list"""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
    
    def delete(self, data):
        """Delete first occurrence of a node with given data"""
        if not self.head:
            return
            
        # If head node itself holds the data to be deleted
        if self.head.data == data:
            self.head = self.head.next
            return
            
        # Search for the node to be deleted
        current = self.head
        while current.next and current.next.data != data:
            current = current.next
            
        # If data was found, delete it
        if current.next:
            current.next = current.next.next
    
    def display(self):
        """Return list of all values in the linked list"""
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        return elements
    
    def search(self, data):
        """Search for a node with given data"""
        current = self.head
        position = 0
        while current:
            if current.data == data:
                return position
            current = current.next
            position += 1
        return -1
    
    def length(self):
        """Return the length of the linked list"""
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count


# Create a new linked list
ll = LinkedList()

# Add elements
ll.append(1)    # List: 1
ll.append(2)    # List: 1 -> 2
ll.prepend(0)   # List: 0 -> 1 -> 2

# Display the list
print(ll.display())  # [0, 1, 2]

# Search for an element
print(ll.search(0))  # 1 (position of element 1)

# Delete an element
ll.delete(1)
print(ll.display())  # [0, 2]

# Get length
print(ll.length())   # 2
