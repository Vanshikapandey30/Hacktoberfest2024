Insertion Sort Overview
=======================

Table of Contents
-----------------

*   [Introduction to Insertion Sort](#introduction-to-insertion-sort)
*   [Working of Insertion Sort](#working-of-insertion-sort)
*   [Algorithm](#algorithm)
*   [Example](#example)
*   [Code Implementation](#code-implementation)
*   [Output](#output)
*   [Time Complexity](#time-complexity)
*   [Space Complexity](#space-complexity)
*   [Advantages of Insertion Sort](#advantages-of-insertion-sort)
*   [Disadvantages of Insertion Sort](#disadvantages-of-insertion-sort)
*   [Applications of Insertion Sort](#applications-of-insertion-sort)
*   [Important Points for Interviews](#important-points-for-interviews)

Introduction to Insertion Sort
----------------------------------

Insertion sort is an in-place comparison-based sorting algorithm that works efficiently for small datasets. It resembles the process of sorting playing cards in your hand. The algorithm builds the final sorted array by inserting one element at a time into its correct position in a sorted portion of the array.

Working of Insertion Sort
-----------------------------

Insertion sort divides the array into two parts: the sorted part and the unsorted part. Initially, the first element is considered sorted, and each new element from the unsorted part is compared to the elements in the sorted part to find its correct position. This process continues until all elements are sorted.

Algorithm
-------------

The algorithm follows these steps:

1.  Start with the second element (the first element is considered sorted).
2.  Compare the current element with the elements in the sorted part of the array.
3.  Shift all elements greater than the current element one position to the right.
4.  Insert the current element in its correct position.
5.  Repeat the process until the entire array is sorted.

Example
-----------

Consider the array: `{23, 1, 10, 5, 2}`

### Steps:

*   Initial: Sorted part: `[23]`
*   First Pass: `[1, 23]`
*   Second Pass: `[1, 10, 23]`
*   Third Pass: `[1, 5, 10, 23]`
*   Fourth Pass: `[1, 2, 5, 10, 23]`

Code Implementation
-----------------------

    
    public class InsertionSort {
        /* Function to sort array using insertion sort */
        void sort(int arr[]) {
            int n = arr.length;
            for (int i = 1; i < n; ++i) {
                int key = arr[i];
                int j = i - 1;
    
                /* Move elements of arr[0..i-1], that are greater than key,
                   to one position ahead of their current position */
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }
    
        /* A utility function to print array of size n */
        static void printArray(int arr[]) {
            int n = arr.length;
            for (int i = 0; i < n; ++i)
                System.out.print(arr[i] + " ");
            System.out.println();
        }
    
        // Driver method
        public static void main(String args[]) {
            int arr[] = { 12, 11, 13, 5, 6 };
    
            InsertionSort ob = new InsertionSort();
            ob.sort(arr);
    
            printArray(arr);
        }
    }
    

Output
----------

    
    Array Before Insertion Sort: 
    12 11 13 5 6 
    Array After Insertion Sort: 
    5 6 11 12 13
    

Time Complexity
-------------------

*   **Best Case**: O(n) - When the array is already sorted.
*   **Average Case**: O(n²) - For a randomly ordered array.
*   **Worst Case**: O(n²) - When the array is sorted in reverse order.

Space Complexity
--------------------

*   **Auxiliary Space**: O(1) - Insertion sort is an in-place algorithm, meaning it requires no extra space other than the input array.

Advantages of Insertion Sort
--------------------------------

*   Simple and easy to implement.
*   Efficient for small and nearly sorted datasets.
*   Space-efficient with O(1) auxiliary space.
*   Stable sorting algorithm (maintains the relative order of equal elements).
*   Adaptive in nature, which means fewer inversions lead to fewer swaps.

Disadvantages of Insertion Sort
------------------------------------

*   Inefficient for large datasets.
*   Average and worst-case time complexity of O(n²), making it slower compared to other sorting algorithms like quicksort or mergesort.

Applications of Insertion Sort
-----------------------------------

*   **Small or Nearly Sorted Arrays**: Insertion sort is often used for small datasets or when the array is almost sorted.
*   **Hybrid Algorithms**: Used in algorithms like Timsort or introsort for small data chunks within recursive calls.
*   **Stability and Simplicity**: When simplicity and maintaining relative order of equal elements is important.

Important Points for Interviews
------------------------------------

*   **In-place Algorithm**: It doesn’t require extra memory (only O(1) space).
*   **Stable Sorting**: Retains the relative order of equal elements.
*   **Best for Small Arrays**: Insertion sort performs well on small datasets and is faster than more complex algorithms for small arrays.
*   **Adaptive**: Efficient when the array is nearly sorted, with a best-case time complexity of O(n).
*   **Worst-case Time Complexity**: O(n²) when the input array is in reverse order.
*   **Insertion Sort vs. Other Algorithms**: Although it’s slower than algorithms like quicksort or mergesort for large datasets, it's simpler and useful when efficiency isn't critical.
*   **Hybrid Algorithms**: Insertion sort is used within more complex algorithms (e.g., Timsort) for small portions of data.
*   **Real-world Application**: Suitable for scenarios where data is almost sorted or for small-scale sorting tasks in hybrid systems.