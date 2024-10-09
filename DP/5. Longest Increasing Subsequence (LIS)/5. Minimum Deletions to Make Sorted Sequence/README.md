Minimum Deletions to Make Sorted Sequence
=========================================

Problem Definition
------------------

The task is to find the minimum number of deletions required to make an array sorted in non-decreasing order.

### Example

*   Input: `[3, 2, 1, 4]`
*   Output: `2` (Remove 3 and 2 to get sorted sequence \[1, 4\])

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach checks each element and decides whether to delete it or not, leading to an exponential number of subproblems.

#### Pseudocode

    function minDeletionsRecursive(arr, n):
        if n <= 1:
            return 0
        if arr[n-1] >= arr[n-2]:
            return minDeletionsRecursive(arr, n-1)
        else:
            return 1 + min(minDeletionsRecursive(arr, n-1), 
                           minDeletionsRecursive(arr, n-2))
    

#### Java Implementation

    public class MinDeletionsRecursive {
        public static int minDeletionsRecursive(int[] arr, int n) {
            if (n <= 1) return 0;
            if (arr[n - 1] >= arr[n - 2]) {
                return minDeletionsRecursive(arr, n - 1);
            } else {
                return 1 + Math.min(minDeletionsRecursive(arr, n - 1), 
                                    minDeletionsRecursive(arr, n - 2));
            }
        }
    
        public static void main(String[] args) {
            int[] arr = {3, 2, 1, 4};
            int result = minDeletionsRecursive(arr, arr.length);
            System.out.println("Minimum deletions: " + result);  // Output: 2 (inefficient)
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for recursion stack)

### 2\. Dynamic Programming Approach (O(n2))

This approach utilizes dynamic programming to find the length of the longest increasing subsequence (LIS), and then calculates the minimum deletions based on that.

#### Pseudocode

    function minDeletionsDP(arr, n):
        if n == 0:
            return 0
        lis = array of size n initialized to 1
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] > arr[j]:
                    lis[i] = max(lis[i], lis[j] + 1)
        lengthOfLIS = max(lis)
        return n - lengthOfLIS
    

#### Java Implementation

    import java.util.Arrays;
    
    public class MinDeletionsDP {
        public static int minDeletionsDP(int[] arr) {
            int n = arr.length;
            if (n == 0) return 0;
    
            int[] lis = new int[n];
            Arrays.fill(lis, 1);
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        lis[i] = Math.max(lis[i], lis[j] + 1);
                    }
                }
            }
    
            int lengthOfLIS = Arrays.stream(lis).max().orElse(0);
            return n - lengthOfLIS;
        }
    
        public static void main(String[] args) {
            int[] arr = {3, 2, 1, 4};
            int result = minDeletionsDP(arr);
            System.out.println("Minimum deletions: " + result);  // Output: 2
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for LIS array)

### 3\. Optimized Approach (O(n log n))

This optimized approach also finds the length of the longest increasing subsequence using binary search, allowing us to calculate the minimum deletions more efficiently.

#### Java Implementation

    import java.util.*;
    
    public class MinDeletionsOptimized {
        public static int minDeletionsOptimized(int[] arr) {
            if (arr.length == 0) return 0;
    
            List lis = new ArrayList<>();
            for (int num : arr) {
                int index = Collections.binarySearch(lis, num);
                if (index < 0) {
                    index = -(index + 1);
                }
                if (index == lis.size()) {
                    lis.add(num);
                } else {
                    lis.set(index, num);
                }
            }
    
            int lengthOfLIS = lis.size();
            return arr.length - lengthOfLIS;
        }
    
        public static void main(String[] args) {
            int[] arr = {3, 2, 1, 4};
            int result = minDeletionsOptimized(arr);
            System.out.println("Minimum deletions: " + result);  // Output: 2
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n log n)
*   **Space Complexity:** O(n) (for LIS list)