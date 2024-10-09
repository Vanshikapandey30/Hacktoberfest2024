Heap Sort in Java
=================

Table of Contents
-----------------

*   [Key Concepts of Heap Sort](#key-concepts-of-heap-sort)
*   [Algorithm Steps for Heap Sort](#algorithm-steps-for-heap-sort)
*   [Two Phases of Heap Sort](#two-phases-of-heap-sort)
*   [Java Implementation of Heap Sort](#java-implementation-of-heap-sort)
*   [Explanation of the Java Code](#explanation-of-the-java-code)
*   [Time Complexity](#time-complexity)
*   [Space Complexity](#space-complexity)
*   [Important Points about Heap Sort](#important-points-about-heap-sort)
*   [Advantages of Heap Sort](#advantages-of-heap-sort)
*   [Disadvantages of Heap Sort](#disadvantages-of-heap-sort)
*   [Interview Aspects](#interview-aspects)

Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It can be considered an optimized version of selection sort, where instead of scanning for the maximum or minimum element in each iteration, we use a binary heap to find the maximum or minimum in logarithmic time.

Key Concepts of Heap Sort
-------------------------

*   **Heap Definition**:
    *   A **Max Heap** is a complete binary tree where the value of each node is greater than or equal to the values of its children. The largest element is at the root.
    *   A **Min Heap** is a complete binary tree where the value of each node is less than or equal to the values of its children. The smallest element is at the root.
*   **Heap Properties**:
    *   For an element at index `i`:
        *   Left child is located at `2*i + 1`.
        *   Right child is located at `2*i + 2`.
        *   Parent can be found at `(i - 1) / 2`.

Algorithm Steps for Heap Sort
-----------------------------

1.  **Build a Max Heap** from the input data. The largest element is now at the root of the heap.
2.  **Swap** the root element (the largest) with the last element of the heap.
3.  **Reduce** the heap size by one.
4.  **Heapify** the root of the tree to ensure the heap property is maintained.
5.  Repeat steps 2 to 4 until the size of the heap is greater than one.

Two Phases of Heap Sort
-----------------------

The heap sort algorithm consists of two phases:

1.  **Building the Max Heap**: In this first phase, the array is converted into a max heap. This is done by heapifying each non-leaf node, starting from the last non-leaf node up to the root.
2.  **Sorting the Elements**: In the second phase, the highest element (i.e., the one at the tree root) is removed and swapped with the last element in the heap. The remaining elements are then used to create a new max heap, and this process is repeated until the heap size is reduced to one.

Java Implementation of Heap Sort
--------------------------------

    
    import java.util.Arrays;
    
    public class HeapSort {
    
        private void heapify(int[] arr, int n, int i) {
            int largest = i;
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
    
            if (leftChild < n && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }
    
            if (rightChild < n && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }
    
            if (largest != i) {
                swap(arr, i, largest);
                heapify(arr, n, largest);
            }
        }
    
        public void heapSort(int[] arr) {
            int n = arr.length;
    
            for (int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, n, i);
            }
    
            for (int i = n - 1; i >= 0; i--) {
                swap(arr, 0, i);
                heapify(arr, i, 0);
            }
        }
    
        private void swap(int[] arr, int i, int j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    
        public static void main(String[] args) {
            HeapSort heapSort = new HeapSort();
            int[] arr = {1, 14, 3, 7, 0};
    
            System.out.println("Unsorted array: " + Arrays.toString(arr));
            
            heapSort.heapSort(arr);
            
            System.out.println("Sorted array: " + Arrays.toString(arr));
        }
    }
        

Explanation of the Java Code
----------------------------

*   **Heapify Function**: This function is responsible for maintaining the heap property. It checks whether the current node is larger than its children and swaps them if necessary. It recursively applies the same logic to ensure all elements satisfy the heap property.
*   **Heap Sort Function**: The `heapSort` function first builds a max heap from the input array. Then it repeatedly swaps the root of the heap (the maximum value) with the last element in the heap and reduces the heap size by one, followed by calling `heapify` to maintain the heap property.
*   **Main Method**: This is the entry point of the program. It creates an instance of `HeapSort`, defines an unsorted array, and prints the sorted array after invoking the `heapSort` method.

Time Complexity
---------------

*   **Best Case**: `O(n log n)`
*   **Average Case**: `O(n log n)`
*   **Worst Case**: `O(n log n)`

Space Complexity
----------------

**Auxiliary Space**: `O(1)` for the iterative implementation, but can be `O(log n)` due to the recursive stack in a recursive implementation.

Important Points about Heap Sort
--------------------------------

*   Heap sort is an **in-place** algorithm.
*   It is **not stable**, meaning equal elements may not retain their original order.
*   Heap sort can be implemented using **arrays** or **linked lists**.
*   It performs well for large datasets.
*   Heap sort can be used in priority queues.

Advantages of Heap Sort
-----------------------

*   Good time complexity of `O(n log n)`.
*   Works well with large data sets.
*   Does not require additional space for sorting.

Disadvantages of Heap Sort
--------------------------

*   Not stable, meaning it does not preserve the relative order of equal elements.
*   Performance can be poor for small data sets compared to algorithms like quicksort or insertion sort.

Interview Aspects
-----------------

*   Understand the difference between max heaps and min heaps.
*   Be prepared to discuss time and space complexity.
*   Explain the heapify process in detail.
*   Real-World Applications: Be able to provide examples of where heap sort is applicable in real-world scenarios.
*   Two Phases of Heap Sort: Clearly explain the two phases of heap sort—building the max heap and sorting the elements by repeatedly extracting the highest element.