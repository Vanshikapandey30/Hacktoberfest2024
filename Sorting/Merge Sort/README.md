Merge Sort
==========

Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays, sorting those subarrays, and then merging them back together to obtain the sorted array.

In simple terms, we can say that the process of merge sort is to divide the array into two halves, sort each half, and then merge the sorted halves back together. This process is repeated until the entire array is sorted.

Merge Sort Algorithm
--------------------

### Table of Content

*   [How does Merge Sort work?](#how-does-merge-sort-work)
*   [Illustration of Merge Sort](#illustration-of-merge-sort)
*   [Implementation of Merge Sort](#implementation-of-merge-sort)
*   [Recurrence Relation of Merge Sort](#recurrence-relation-of-merge-sort)
*   [Complexity Analysis of Merge Sort](#complexity-analysis-of-merge-sort)
*   [Applications of Merge Sort](#applications-of-merge-sort)
*   [Advantages & Disadvantages of Merge Sort](#advantages--disadvantages-of-merge-sort)
*   [Important Points for Interviews](#important-points-for-interviews)

How does Merge Sort work?
-------------------------

Merge sort is a popular sorting algorithm known for its efficiency and stability. It follows the divide-and-conquer approach to sort a given array of elements.

Here’s a step-by-step explanation of how merge sort works:

1.  **Divide**: Divide the list or array recursively into two halves until it can no more be divided.
2.  **Conquer**: Each subarray is sorted individually using the merge sort algorithm.
3.  **Merge**: The sorted subarrays are merged back together in sorted order. The process continues until all elements from both subarrays have been merged.

Illustration of Merge Sort
--------------------------

Let’s sort the array or list \[38, 27, 43, 10\] using Merge Sort:

1.  **Divide**:
    *   \[38, 27\] and \[43, 10\]
    *   \[38\] and \[27\]
    *   \[43\] and \[10\]
2.  **Conquer**:
    *   \[38\] is already sorted.
    *   \[27\] is already sorted.
    *   \[43\] is already sorted.
    *   \[10\] is already sorted.
3.  **Merge**:
    *   Merge \[38\] and \[27\] to get \[27, 38\].
    *   Merge \[43\] and \[10\] to get \[10, 43\].
    *   Merge \[27, 38\] and \[10, 43\] to get the final sorted list \[10, 27, 38, 43\].

Therefore, the sorted list is \[10, 27, 38, 43\].

Implementation of Merge Sort
----------------------------

     // Java program for Merge Sort
    import java.io.*;
    
    class GfG {
    
        static void merge(int arr[], int l, int m, int r) {
            int n1 = m - l + 1;
            int n2 = r - m;
    
            int L[] = new int[n1];
            int R[] = new int[n2];
    
            for (int i = 0; i < n1; ++i)
                L[i] = arr[l + i];
            for (int j = 0; j < n2; ++j)
                R[j] = arr[m + 1 + j];
    
            int i = 0, j = 0;
            int k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
    
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }
    
            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }
    
        static void sort(int arr[], int l, int r) {
            if (l < r) {
                int m = l + (r - l) / 2;
    
                sort(arr, l, m);
                sort(arr, m + 1, r);
    
                merge(arr, l, m, r);
            }
        }
    
        static void printArray(int arr[]) {
            int n = arr.length;
            for (int i = 0; i < n; ++i)
                System.out.print(arr[i] + " ");
            System.out.println();
        }
    
        public static void main(String args[]) {
            int arr[] = { 12, 11, 13, 5, 6, 7 };
    
            System.out.println("Given array is");
            printArray(arr);
    
            sort(arr, 0, arr.length - 1);
    
            System.out.println("\nSorted array is");
            printArray(arr);
        }
    }
    

### Output:

Given array is  
12 11 13 5 6 7  
  
Sorted array is  
5 6 7 11 12 13

Recurrence Relation of Merge Sort
---------------------------------

The recurrence relation of merge sort is:

     
    T(n) = 
    {
        Θ(1) if n = 1 
        2T(n/2) + Θ(n) if n > 1 
    } 
    

*   **T(n)** represents the total time taken by the algorithm to sort an array of size **n**.
*   **2T(n/2)** represents the time taken by the algorithm to recursively sort the two halves of the array. Since each half has **n/2** elements, we have two recursive calls with input size as **(n/2)**.
*   **O(n)** represents the time taken to merge the two sorted halves.

Complexity Analysis of Merge Sort
---------------------------------

*   **Time Complexity:**
    *   Best Case: O(n log n) when the array is already sorted or nearly sorted.
    *   Average Case: O(n log n) when the array is randomly ordered.
    *   Worst Case: O(n log n) when the array is sorted in reverse order.
*   **Auxiliary Space:** O(n), additional space is required for the temporary array used during merging.

Applications of Merge Sort
--------------------------

*   Sorting large datasets
*   External sorting (when the dataset is too large to fit in memory)
*   Inversion counting
*   Variants like TimSort are used in Python's built-in sorting algorithms
*   Linked lists: Merge sort is the best choice for sorting linked lists due to its efficient handling of pointers.

Advantages & Disadvantages of Merge Sort
----------------------------------------

### Advantages:

*   Stable sorting algorithm (preserves the relative order of equal elements).
*   Works well with large data sets and is very efficient for linked lists.
*   Predictable O(n log n) time complexity in all cases.

### Disadvantages:

*   Requires additional space for temporary arrays, making it less space-efficient compared to other algorithms like quicksort.
*   Slower than in-memory sorting algorithms like quicksort for smaller arrays.

Important Points for Interviews
-------------------------------

*   Understand the divide-and-conquer approach used in merge sort.
*   Be able to explain the time and space complexity of merge sort.
*   Know how merge sort differs from other sorting algorithms like quicksort and heapsort.
*   Discuss the stability of merge sort and its importance in certain applications.
*   Be prepared to write code for merge sort in your preferred programming language.
*   Understand the applications of merge sort, particularly in sorting linked lists.