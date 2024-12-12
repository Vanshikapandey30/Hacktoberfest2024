Permutations and Combinations
=============================

Definitions
-----------

**Permutations** refer to the different ways in which a set of objects can be arranged in a sequence or order. The order matters in permutations.

**Combinations** refer to the selection of objects from a larger set where the order does not matter.

Formulas
--------

### 1\. Permutations

The number of ways to arrange `n` objects taken `r` at a time is given by:

    P(n, r) = n! / (n - r)!
    

### 2\. Combinations

The number of ways to choose `r` objects from `n` objects without regard to the order is given by:

    C(n, r) = n! / (r! * (n - r)!)
    

Examples
--------

### 1\. Permutations Example

*   Input: `n = 3, r = 2`
*   Output: `P(3, 2) = 3! / (3 - 2)! = 6`

### 2\. Combinations Example

*   Input: `n = 5, r = 2`
*   Output: `C(5, 2) = 5! / (2! * (5 - 2)!) = 10`

Approaches
----------

### 1\. Recursive Approach

#### Permutations

The permutations can be generated recursively by swapping elements.

#### Pseudocode

    function permute(arr, l, r):
        if l == r:
            print arr
        else:
            for i from l to r:
                swap arr[l] with arr[i]
                permute(arr, l + 1, r)
                swap arr[l] back with arr[i]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class Permutations {
        public static void permute(int[] arr, int left, int right) {
            if (left == right) {
                System.out.println(Arrays.toString(arr));
            } else {
                for (int i = left; i <= right; i++) {
                    swap(arr, left, i);
                    permute(arr, left + 1, right);
                    swap(arr, left, i); // backtrack
                }
            }
        }
    
        private static void swap(int[] arr, int i, int j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 2, 3};
            permute(arr, 0, arr.length - 1);
        }
    }
    

#### Combinations

Combinations can be generated recursively by choosing elements.

#### Pseudocode

    function combine(arr, r, index, data, i):
        if index == r:
            print data
            return
        if i >= len(arr):
            return
        data[index] = arr[i]
        combine(arr, r, index + 1, data, i + 1)
        combine(arr, r, index, data, i + 1)
    

#### Java Implementation

    import java.util.Arrays;
    
    public class Combinations {
        public static void combine(int[] arr, int r, int index, int[] data, int i) {
            if (index == r) {
                System.out.println(Arrays.toString(data));
                return;
            }
            if (i >= arr.length) {
                return;
            }
            data[index] = arr[i];
            combine(arr, r, index + 1, data, i + 1);
            combine(arr, r, index, data, i + 1);
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 2, 3, 4};
            int r = 2; // size of combination
            int[] data = new int[r];
            combine(arr, r, 0, data, 0);
        }
    }
    

Time and Space Complexity
-------------------------

### Permutations

*   **Time Complexity:** O(n \* n!) - There are n! permutations and each permutation takes O(n) time to generate.
*   **Space Complexity:** O(n) - Space used by the recursion stack.

### Combinations

*   **Time Complexity:** O(C(n, r) \* r) - C(n, r) combinations, each taking O(r) time to generate.
*   **Space Complexity:** O(r) - Space used for storing the current combination.

Conclusion
----------

Permutations and combinations are essential concepts in combinatorics, with numerous applications in probability, statistics, and various mathematical problems. Understanding the difference between the two and the methods to calculate them is crucial for solving related problems effectively.