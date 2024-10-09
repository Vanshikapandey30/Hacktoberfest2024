Radix Sort
==========

Radix Sort is a linear sorting algorithm that processes elements digit by digit. It is particularly effective for sorting integers and strings with fixed-size keys. This algorithm is efficient and often outperforms comparison-based sorting algorithms, especially for large datasets.

Table of Contents
-----------------

*   [Introduction](#introduction)
*   [Time and Space Complexity](#time-and-space-complexity)
*   [How Radix Sort Works](#how-radix-sort-works)
*   [Pseudocode](#pseudocode)
*   [Implementation](#implementation)
*   [Complexity Analysis](#complexity-analysis)
*   [FAQs](#faqs)
*   [Important Key Points for Interviews](#important-key-points-for-interviews)

Introduction
------------

Radix Sort sorts a list of numbers by distributing the numbers into buckets based on their individual digits. It repeatedly sorts the numbers by their significant digits, starting from the least significant digit (LSD) to the most significant digit (MSD).

Time and Space Complexity
-------------------------

*   **Time Complexity:** O(d \* (n + b)), where:
    *   `d` is the number of digits,
    *   `n` is the number of elements,
    *   `b` is the base of the number system.
*   **Space Complexity:** O(n + b).

How Radix Sort Works
--------------------

The key idea behind Radix Sort is to exploit the concept of place value. Instead of comparing elements directly, Radix Sort distributes elements into buckets based on the digits’ values.

Pseudocode
----------

### Pseudocode for Radix Sort:

    function radixSort(array):
        max = getMax(array)
        for exp from 1 to max:
            countingSort(array, exp)
    
    function countingSort(array, exp):
        n = length of array
        output = new array of size n
        count = new array of size 10 initialized to 0
    
        for i from 0 to n-1:
            index = array[i] / exp
            count[index % 10]++
    
        for i from 1 to 9:
            count[i] += count[i - 1]
    
        for i from n-1 down to 0:
            index = array[i] / exp
            output[count[index % 10] - 1] = array[i]
            count[index % 10]--
    
        for i from 0 to n-1:
            array[i] = output[i]
    
    function getMax(array):
        max = array[0]
        for i from 1 to length of array - 1:
            if array[i] > max:
                max = array[i]
        return max

Implementation
--------------

### Java Implementation

    import java.util.Arrays;
    
    public class RadixSort {
    
        public static void countingSort(int[] arr, int exp) {
            int n = arr.length;
            int[] output = new int[n];
            int[] count = new int[10];
    
            for (int i = 0; i < n; i++) {
                int index = arr[i] / exp;
                count[index % 10]++;
            }
    
            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
    
            for (int i = n - 1; i >= 0; i--) {
                int index = arr[i] / exp;
                output[count[index % 10] - 1] = arr[i];
                count[index % 10]--;
            }
    
            for (int i = 0; i < n; i++) {
                arr[i] = output[i];
            }
        }
    
        public static void radixSort(int[] arr) {
            int max = Arrays.stream(arr).max().getAsInt();
            for (int exp = 1; max / exp > 0; exp *= 10) {
                countingSort(arr, exp);
            }
        }
    
        public static void main(String[] args) {
            int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
            radixSort(arr);
            System.out.println("Sorted array: " + Arrays.toString(arr));
        }
    }

Complexity Analysis
-------------------

*   **Time Complexity:** O(d \* (n + b))
*   **Space Complexity:** O(n + b)

In practical implementations, Radix Sort is often faster than comparison-based sorting algorithms like Quick Sort or Merge Sort for large datasets, particularly when the keys have many digits.

FAQs
----

### Is Radix Sort better than Quick Sort?

Radix Sort can be faster for large inputs, but Quick Sort is often more efficient in memory usage.

### Can Radix Sort handle numbers up to n2?

Yes, it sorts large numbers effectively by processing their digits individually.

Important Key Points for Interviews
-----------------------------------

*   **Algorithm Type:** Non-comparison-based sorting for integers and strings.
*   **Efficiency:** Outperforms comparison sorts like Quick Sort for large datasets.
*   **Complexity:** O(d \* (n + b)) time; O(n + b) space.
*   **Use Cases:** Suitable for fast sorting in databases and data processing.