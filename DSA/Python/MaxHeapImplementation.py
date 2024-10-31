
class MaxHeap:
    def __init__(self):
        """Initialize an empty max heap"""
        self.heap = []
    
    def parent(self, i):
        """Get the parent index of node at index i"""
        return (i - 1) // 2
    
    def left_child(self, i):
        """Get the left child index of node at index i"""
        return 2 * i + 1
    
    def right_child(self, i):
        """Get the right child index of node at index i"""
        return 2 * i + 2
    
    def swap(self, i, j):
        """Swap elements at indices i and j"""
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    
    def insert(self, key):
        """Insert a new key into the max heap"""
        self.heap.append(key)
        self._sift_up(len(self.heap) - 1)
    
    def _sift_up(self, i):
        """Move a node up the heap until heap property is restored"""
        parent = self.parent(i)
        if i > 0 and self.heap[i] > self.heap[parent]:
            self.swap(i, parent)
            self._sift_up(parent)
    
    def extract_max(self):
        """
        Remove and return the maximum element from the heap
        Returns None if heap is empty
        """
        if len(self.heap) == 0:
            return None
        
        if len(self.heap) == 1:
            return self.heap.pop()
        
        max_val = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._sift_down(0)
        
        return max_val
    
    def _sift_down(self, i):
        """Move a node down the heap until heap property is restored"""
        max_index = i
        size = len(self.heap)
        
        left = self.left_child(i)
        if left < size and self.heap[left] > self.heap[max_index]:
            max_index = left
        
        right = self.right_child(i)
        if right < size and self.heap[right] > self.heap[max_index]:
            max_index = right
        
        if i != max_index:
            self.swap(i, max_index)
            self._sift_down(max_index)
    
    def get_max(self):
        """
        Return the maximum element without removing it
        Returns None if heap is empty
        """
        if len(self.heap) == 0:
            return None
        return self.heap[0]
    
    def remove(self, i):
        """Remove element at index i"""
        if i < 0 or i >= len(self.heap):
            return
        
        # Set the value to infinity and sift up
        self.heap[i] = float('inf')
        self._sift_up(i)
        
        # Extract the max (which will be our infinity value)
        self.extract_max()
    
    def build_heap(self, array):
        """Build a max heap from an array"""
        self.heap = array.copy()
        # Start from last non-leaf node and heapify down
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self._sift_down(i)
    
    def heap_sort(self):
        """Sort an array using heap sort"""
        sorted_array = []
        heap_size = len(self.heap)
        
        # Extract max element repeatedly
        for _ in range(heap_size):
            sorted_array.insert(0, self.extract_max())
            
        return sorted_array
    
    def size(self):
        """Return the size of the heap"""
        return len(self.heap)
    
    def is_empty(self):
        """Check if the heap is empty"""
        return len(self.heap) == 0
    
    def clear(self):
        """Clear the heap"""
        self.heap = []
    
    def __str__(self):
        """String representation of the heap"""
        return str(self.heap)
# Create a new max heap
heap = MaxHeap()

# Insert some values
heap.insert(4)
heap.insert(10)
heap.insert(8)
heap.insert(5)
heap.insert(1)

print("Heap after insertions:", heap)  # [10, 5, 8, 4, 1]

# Get maximum value
print("Maximum value:", heap.get_max())  # 10

# Extract maximum value
max_val = heap.extract_max()
print("Extracted max:", max_val)  # 10
print("Heap after extraction:", heap)  # [8, 5, 1, 4]

# Build heap from array
array = [3, 7, 2, 11, 9, 4]
heap.build_heap(array)
print("Heap from array:", heap)  # [11, 9, 4, 3, 7, 2]

# Heap sort
sorted_array = heap.heap_sort()
print("Sorted array:", sorted_array)  # [2, 3, 4, 7, 9, 11]

# Check size and emptiness
print("Heap size:", heap.size())  # 0 (after heap sort)
print("Is heap empty?", heap.is_empty())  # True
