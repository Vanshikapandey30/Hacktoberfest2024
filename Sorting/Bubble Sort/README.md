Bubble Sort
=============================

Table of Contents
-----------------

*   [Description](#description)
*   [Algorithm](#algorithm)
*   [Time Complexity](#time-complexity)
*   [Space Complexity](#space-complexity)
*   [Optimized Bubble Sort](#optimized-bubble-sort)
*   [Advantages](#advantages)
*   [Disadvantages](#disadvantages)
*   [Java Implementation](#java-implementation)
*   [Key Points for Interviews](#key-points-for-interviews)

Description
-----------

Bubble Sort is a simple comparison-based sorting algorithm where each pair of adjacent elements is compared and swapped if they are not in the correct order. The process is repeated until the array is sorted. The algorithm gets its name because the largest unsorted element "bubbles" up to its correct position in each pass.

Algorithm
---------

The Bubble Sort algorithm can be broken down into the following steps:

1.  Compare the first pair of elements.
2.  If they are out of order, swap them.
3.  Move to the next pair and repeat the comparison and swapping process.
4.  Repeat this for the entire array, bubbling the largest unsorted element to its correct position at the end.
5.  Continue this process until the array is fully sorted.

Time Complexity
---------------

The time complexity of Bubble Sort varies depending on the case:

*   **Best Case:** O(n) (when the array is already sorted)
*   **Worst Case:** O(n²) (when the array is sorted in reverse order)
*   **Average Case:** O(n²)

Space Complexity
----------------

Bubble Sort works in-place, meaning it does not require additional memory beyond the input array, so the space complexity is:

*   **Space Complexity:** O(1)

Optimized Bubble Sort
---------------------

In the optimized version of Bubble Sort, we introduce a \`swapped\` flag. If no elements are swapped during a pass, it means the array is already sorted, and the algorithm can terminate early, reducing the number of passes.

Advantages
----------

*   **Simplicity:** The algorithm is simple to understand and implement.
*   **Low Memory Usage:** Requires only a constant amount of additional memory (O(1)).
*   **Educational Value:** A good introductory algorithm for understanding sorting concepts.

Disadvantages
-------------

*   **Inefficiency:** Bubble Sort has a time complexity of O(n²), making it inefficient for large datasets.
*   **Poor Performance:** It performs poorly compared to other algorithms like Quick Sort or Merge Sort, especially when dealing with large arrays.
*   **Worst Case:** Sorting an array that is sorted in reverse takes the maximum number of operations.

Java Implementation
-------------------

### Method 1: Basic Bubble Sort

    class Main {
        static void bubbleSort(int a[]) {
            int len = a.length;
            for (int i = 0; i < len-1; i++) {
                for (int j = 0; j < len-i-1; j++) {
                    if (a[j] > a[j+1]) {
                        int temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
        }
    
        static void printArray(int a[]) {
            for (int element : a) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    
        public static void main(String args[]) {
            int arr[] = {64, 34, 25, 12, 22, 11, 90};
            bubbleSort(arr);
            System.out.println("Sorted array:");
            printArray(arr);
        }
    }

### Method 2: Optimized Bubble Sort

    class Main {
        static void bubbleSort(int a[]) {
            int len = a.length;
            for (int i = 0; i < len-1; i++) {
                boolean swapped = false;
                for (int j = 0; j < len-i-1; j++) {
                    if (a[j] > a[j+1]) {
                        int temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                        swapped = true;
                    }
                }
                if (!swapped) break;
            }
        }
    
        static void printArray(int a[]) {
            for (int element : a) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    
        public static void main(String args[]) {
            int arr[] = {1, 2, 3, 4, 5, 6, 7};
            bubbleSort(arr);
            System.out.println("Sorted array:");
            printArray(arr);
        }
    }

Key Points for Interviews
-------------------------

*   **Time Complexity:** Remember that the time complexity of Bubble Sort is O(n²) in the worst and average cases, but can be O(n) in the best case (when the array is already sorted).
*   **Space Complexity:** Bubble Sort has a space complexity of O(1) since it is an in-place sorting algorithm.
*   **Stability:** Bubble Sort is a stable sorting algorithm, meaning it maintains the relative order of elements with equal values.
*   **Optimized Version:** Be prepared to explain the optimized version of Bubble Sort, where you can terminate early if no swaps are made during a pass.
*   **Not Suitable for Large Datasets:** Bubble Sort is inefficient for large datasets and should be used only for small arrays or educational purposes.
*   **Simple to Implement:** Despite its inefficiency, Bubble Sort is easy to implement and can be used as a learning tool for understanding basic sorting algorithms.
*   **In-Place Sorting:** Since Bubble Sort does not require additional memory for another array or data structure, it sorts the input array itself.