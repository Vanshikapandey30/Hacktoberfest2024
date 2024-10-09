Linear Search in Java
=====================

Table of Contents
-----------------

*   [Introduction](#introduction)
*   [Complexity Analysis](#complexity-analysis)
*   [Steps to Implement Linear Search](#steps)
*   [Java Code Example](#java-code)
*   [Example Output](#example-output)
*   [Comparison: Linear Search vs. Binary Search](#comparison)
*   [Summary of Time Complexity](#summary)
*   [Interview Tips](#interview-tips)

Introduction
------------

Linear Search is a basic algorithm used to locate a specific value within an array by checking each element one by one. Although straightforward, it can be slow for large datasets due to its linear nature.

Complexity Analysis
-------------------

*   **Time Complexity:** O(n) - In the worst-case scenario, every element must be checked.
*   **Best Case:** O(1) - The target value is at the first position.
*   **Worst Case:** O(n) - The target is not present, necessitating a complete scan.
*   **Space Complexity:** O(1) - Only a few variables are needed for execution.
*   **Average Comparisons:** (n + 1) / 2 - On average, half the array will be checked.

Steps to Implement Linear Search
--------------------------------

1.  Prompt the user for the array elements and the target value.
2.  Iterate through the array, comparing each item to the target.
3.  If a match is found, display the index and exit the loop.
4.  If the loop completes without finding a match, notify the user that the item was not found.

Java Code Example
-----------------

### Linear Search Program

    class Main {
        private static void performLinearSearch(int[] array, int target) {
            for (int index = 0; index < array.length; index++) {
                if (array[index] == target) {
                    System.out.println(target + " is located at index: " + index);
                    return;
                }
            }
            System.out.println("Item not found in the array.");
        }
    
        public static void main(String[] args) {
            int[] array = {12, 5, 18, 25, -3, 19};
            int target = 25;
            performLinearSearch(array, target);
        }
    }

Example Output
--------------

If the item is found:

    25 is located at index: 3

If the item is not found:

    Item not found in the array.

Comparison: Linear Search vs. Binary Search
-------------------------------------------

*   **Linear Search:**
    *   Time Complexity: O(n)
    *   Best for small, unsorted lists.
    *   Easy to implement.
*   **Binary Search:**
    *   Time Complexity: O(log n)
    *   Much faster, but requires sorted data.
    *   More complex to implement.

Summary of Time Complexity
--------------------------

## Summary of Time Complexity

| Search Method   | Best   | Average | Worst   | Space Complexity |
|------------------|--------|---------|---------|------------------|
| Linear Search    | O(1)   | O(n)    | O(n)    | O(1)             |


Interview Tips
--------------

*   Understand the basic algorithm and its application.
*   Be prepared to discuss time and space complexity.
*   Know the scenarios where linear search is preferred over binary search.
*   Explain how the algorithm works step-by-step during coding interviews.
*   Practice implementing the algorithm without using code completion tools.
*   Be ready to analyze and optimize the search for specific data structures.