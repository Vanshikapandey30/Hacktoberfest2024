Selection Sort
==============

Table of Contents
-----------------

*   [How Does Selection Sort Work?](#how-does-selection-sort-work)
*   [Java Implementation of Selection Sort](#java-implementation-of-selection-sort)
*   [Output](#output)
*   [Complexity Analysis of Selection Sort](#complexity-analysis-of-selection-sort)
*   [Advantages of Selection Sort](#advantages-of-selection-sort)
*   [Disadvantages of Selection Sort](#disadvantages-of-selection-sort)
*   [Applications of Selection Sort](#applications-of-selection-sort)
*   [Key Points for Interviews](#key-points-for-interviews)

Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.

How Does Selection Sort Work?
-----------------------------

First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position. Then we find the smallest among remaining elements (or second smallest) and move it to its correct position by swapping. We keep doing this until we get all elements moved to correct position.

Java Implementation of Selection Sort
-------------------------------------

    
    // Java program for implementation of Selection Sort
    import java.util.Arrays;
    
    class GfG {
    
        static void selectionSort(int[] arr){
            int n = arr.length;
            for (int i = 0; i < n - 1; i++) {
                int min_idx = i;
                for (int j = i + 1; j < n; j++) {
                    if (arr[j] < arr[min_idx]) {
                        min_idx = j;
                    }
                }
                if (min_idx != i) {
                    int temp = arr[i];
                    arr[i] = arr[min_idx];
                    arr[min_idx] = temp;
                }
            }
        }
    
        static void printArray(int[] arr){
            for (int val : arr) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
      
        public static void main(String[] args){
            int[] arr = { 64, 25, 12, 22, 11 };
    
            System.out.print("Original array: ");
            printArray(arr);
    
            selectionSort(arr);
    
            System.out.print("Sorted array: ");
            printArray(arr);
        }
    }
        

Output
------

    
    Original array: 64 25 12 22 11 
    Sorted array:   11 12 22 25 64 
        

Complexity Analysis of Selection Sort
-------------------------------------

Time Complexity: O(n2) as there are two nested loops:

*   One loop to select an element of the array one by one = O(n)
*   Another loop to compare that element with every other array element = O(n)

Therefore overall complexity = O(n) \* O(n) = O(n2)

Auxiliary Space: O(1) as the only extra memory used is for temporary variables.

Advantages of Selection Sort
----------------------------

*   Easy to understand and implement, making it ideal for teaching basic sorting concepts.
*   Requires only a constant O(1) extra memory space.
*   It requires fewer memory writes compared to many other standard algorithms.

Disadvantages of Selection Sort
-------------------------------

*   Time complexity of O(n2) makes it slower compared to algorithms like Quick Sort or Merge Sort.
*   Does not maintain the relative order of equal elements (not stable).

Applications of Selection Sort
------------------------------

*   Perfect for teaching fundamental sorting mechanisms and algorithm design.
*   Suitable for small lists where the overhead of more complex algorithms isn’t justified.
*   Ideal for systems with limited memory due to its in-place sorting capability.
*   Used in simple embedded systems where resource availability is limited and simplicity is important.

### Key Points for Interviews

*   Selection Sort has a time complexity of O(n2) in all cases, making it inefficient for large datasets.
*   It is an in-place sorting algorithm, requiring O(1) additional space.
*   Selection Sort is not stable and can change the order of equal elements.
*   It's best suited for small arrays or for educational purposes.
*   Understand the differences between Selection Sort and other sorting algorithms like Bubble Sort and Insertion Sort.