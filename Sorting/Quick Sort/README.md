Quick Sort
==========

QuickSort is a sorting algorithm based on the Divide and Conquer principle that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

Table of Content
----------------

*   [How does QuickSort Algorithm work?](#how-does-quicksort-algorithm-work)
*   [Working of Partition Algorithm with Illustration](#working-of-partition-algorithm-with-illustration)
*   [Illustration of QuickSort Algorithm](#illustration-of-quicksort-algorithm)
*   [Complexity Analysis of Quick Sort](#complexity-analysis-of-quick-sort)
*   [Advantages of Quick Sort](#advantages-of-quick-sort)
*   [Disadvantages of Quick Sort](#disadvantages-of-quick-sort)
*   [Applications of Quick Sort](#applications-of-quick-sort)
*   [Important Points for Interview](#important-points-for-interview)

How does QuickSort Algorithm work?
----------------------------------

QuickSort works on the principle of divide and conquer, breaking down the problem into smaller sub-problems.

There are mainly three steps in the algorithm:

1.  **Choose a Pivot:** Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
2.  **Partition the Array:** Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct position, and we obtain the index of the pivot.
3.  **Recursively Call:** Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).

**Base Case:** The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.

Here’s a basic overview of how the QuickSort algorithm works.

### Choice of Pivot

There are many different choices for picking pivots:

*   **Always pick the first (or last) element** as a pivot. The below implementation picks the last element as pivot. The problem with this approach is it ends up in the worst case when the array is already sorted.
*   **Pick a random element as a pivot.** This is a preferred approach because it does not have a pattern for which the worst case happens.
*   **Pick the median element as pivot.** This is an ideal approach in terms of time complexity as we can find the median in linear time and the partition function will always divide the input array into two halves. But it is low on average as median finding has high constants.

Partition Algorithm
-------------------

The key process in QuickSort is a `partition()`. There are three common algorithms to partition. All these algorithms have O(n) time complexity.

*   **Naive Partition:** Here we create a copy of the array. First, put all smaller elements and then all greater. Finally, we copy the temporary array back to the original array. This requires O(n) extra space.
*   **Lomuto Partition:** We have used this partition in this article. This is a simple algorithm; we keep track of the index of smaller elements and keep swapping. We have used it here in this article because of its simplicity.
*   **Hoare’s Partition:** This is the fastest of all. Here we traverse the array from both sides and keep swapping the greater element on the left with the smaller on the right while the array is not partitioned. Please refer Hoare’s vs Lomuto for details.

### Working of Partition Algorithm with Illustration

The logic is simple; we start from the leftmost element and keep track of the index of smaller (or equal) elements as `i`. While traversing, if we find a smaller element, we swap the current element with `arr[i]`. Otherwise, we ignore the current element.

**Recommended Problem:** Quick Sort

**Companies:** VMWare, Amazon, +11 more

Illustration of QuickSort Algorithm
-----------------------------------

In the previous step, we looked at how the partitioning process rearranges the array based on the chosen pivot. Next, we apply the same method recursively to the smaller sub-arrays on the left and right of the pivot. Each time, we select new pivots and partition the arrays again. This process continues until only one element is left, which is always sorted. Once every element is in its correct position, the entire array is sorted.

Complexity Analysis of Quick Sort
---------------------------------

*   **Time Complexity:**
    *   Best Case: `Ω(n log n)`, occurs when the pivot element divides the array into two equal halves.
    *   Average Case: `θ(n log n)`, on average, the pivot divides the array into two parts, but not necessarily equal.
    *   Worst Case: `O(n²)`, occurs when the smallest or largest element is always chosen as the pivot (e.g., sorted arrays).
*   **Auxiliary Space:**
    *   Average Case Space Complexity: `O(log n)`
    *   Worst Case Space Complexity: `O(n)`

Advantages of Quick Sort
------------------------

*   It is a divide-and-conquer algorithm that makes it easier to solve problems.
*   It is efficient on large data sets.
*   It has a low overhead, as it only requires a small amount of memory to function.
*   It is Cache Friendly, as we work on the same array to sort and do not copy data to any auxiliary array.
*   Fastest general-purpose algorithm for large data when stability is not required.
*   It is tail recursive, hence all the tail call optimization can be done.

Disadvantages of Quick Sort
---------------------------

*   It has a worst-case time complexity of `O(n²)`, which occurs when the pivot is chosen poorly.
*   It is not a good choice for small data sets.
*   It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output.

Applications of Quick Sort
--------------------------

*   Efficient for sorting large datasets with `O(n log n)` average-case time complexity.
*   Used in partitioning problems like finding the k-th smallest element or dividing arrays by pivot.
*   Integral to randomized algorithms, offering better performance than deterministic approaches.
*   Applied in cryptography for generating random permutations and unpredictable encryption keys.
*   Partition-based problems where data needs to be split efficiently.

### Example Implementation

    
    public class QuickSort {
        public static void quickSort(int[] arr, int low, int high) {
            if (low < high) {
                int partitionIndex = partition(arr, low, high);
                quickSort(arr, low, partitionIndex - 1);
                quickSort(arr, partitionIndex + 1, high);
            }
        }
    
        private static int partition(int[] arr, int low, int high) {
            int pivot = arr[high];
            int swapIndex = low - 1;
            for (int i = low; i < high; i++) {
                if (arr[i] <= pivot) {
                    swapIndex++;
                    int temp = arr[swapIndex];
                    arr[swapIndex] = arr[i];
                    arr[i] = temp;
                }
            }
            int temp = arr[swapIndex + 1];
            arr[swapIndex + 1] = arr[high];
            arr[high] = temp;
            return swapIndex + 1;
        }
    }
    

### Output

12 11 13 5 6 7 
5 6 7 11 12 13 

Conclusion
----------

The QuickSort algorithm is efficient for large datasets and can outperform other sorting algorithms, particularly when implemented carefully and with a good pivot selection strategy. Understanding the mechanism of QuickSort is essential for its efficient implementation in real-world applications.

Important Points for Interview
------------------------------

*   **Explain the QuickSort Algorithm:** Be prepared to explain how QuickSort works, including the partitioning process and the recursive nature of the algorithm.
*   **Time Complexity Discussion:** Understand and explain the time complexities (best, average, and worst cases) and factors affecting them, especially the impact of pivot selection.
*   **Space Complexity:** Be ready to discuss the space complexity of QuickSort, including average case `O(log n)` and worst case `O(n)`, and how it differs from other sorting algorithms like MergeSort.
*   **Implementation in Various Languages:** Practice implementing QuickSort in different programming languages (e.g., Java, Python, C++).
*   **Comparison with Other Sorting Algorithms:** Be able to compare QuickSort with other sorting algorithms (like MergeSort and HeapSort) in terms of time complexity, space complexity, and stability.
*   **Use Cases:** Be familiar with scenarios where QuickSort is preferable over other algorithms, such as in-place sorting of large datasets.
*   **Common Pitfalls:** Be aware of common pitfalls, such as the worst-case scenario of QuickSort and ways to mitigate it (like using randomized pivot selection).