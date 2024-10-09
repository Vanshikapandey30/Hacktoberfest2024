Minimum Insertions to Sort Array
================================

Problem Definition
------------------

The Minimum Insertions to Sort Array problem involves finding the minimum number of insertions needed to sort a given array of integers. An insertion is defined as placing an element at its correct position to maintain sorted order.

### Example

*   Input: `[3, 1, 2, 5, 4]`
*   Output: `3` (Insert 1 before 3, 2 before 3, and 4 before 5)

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach uses dynamic programming to find the minimum insertions needed by leveraging the length of the longest increasing subsequence (LIS).

#### Pseudocode

    function minInsertions(arr):
        n = length of arr
        lisLength = length of longestIncreasingSubsequence(arr)
        return n - lisLength
    
    function longestIncreasingSubsequence(arr):
        dp = array of size n initialized to 1
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] > arr[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    

#### Java Implementation

    public class MinimumInsertionsToSortArray {
        public static int longestIncreasingSubsequence(int[] arr) {
            int n = arr.length;
            int[] dp = new int[n];
            Arrays.fill(dp, 1);
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                    }
                }
            }
    
            int maxLength = 0;
            for (int length : dp) {
                maxLength = Math.max(maxLength, length);
            }
            return maxLength;
        }
    
        public static int minInsertions(int[] arr) {
            int n = arr.length;
            int lisLength = longestIncreasingSubsequence(arr);
            return n - lisLength;
        }
    
        public static void main(String[] args) {
            int[] arr = {3, 1, 2, 5, 4};
            int result = minInsertions(arr);
            System.out.println("Minimum Insertions to Sort Array: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for dp array)

### 2\. Recursive Approach with Memoization

This approach employs recursion with memoization to find the minimum insertions needed.

#### Pseudocode

    function minInsertionsRecursive(arr, index, prevIndex, memo):
        if index == length of arr:
            return 0
        if memo[index][prevIndex + 1] is not -1:
            return memo[index][prevIndex + 1]
    
        if prevIndex == -1 or arr[index] > arr[prevIndex]:
            include = minInsertionsRecursive(arr, index + 1, index, memo)
        else:
            include = Integer.MAX_VALUE
    
        exclude = 1 + minInsertionsRecursive(arr, index + 1, prevIndex, memo)
        memo[index][prevIndex + 1] = Math.min(include, exclude)
        return memo[index][prevIndex + 1]
    
    function minInsertions(arr):
        memo = array of size n x (n + 1) initialized to -1
        return minInsertionsRecursive(arr, 0, -1, memo)
    

#### Java Implementation

    public class MinimumInsertionsToSortArrayRecursive {
        public static int minInsertionsRecursive(int[] arr, int index, int prevIndex, int[][] memo) {
            if (index == arr.length) return 0;
            if (prevIndex != -1 && memo[index][prevIndex + 1] != -1) return memo[index][prevIndex + 1];
    
            int include = Integer.MAX_VALUE;
            if (prevIndex == -1 || arr[index] > arr[prevIndex]) {
                include = minInsertionsRecursive(arr, index + 1, index, memo);
            }
            int exclude = 1 + minInsertionsRecursive(arr, index + 1, prevIndex, memo);
            
            if (prevIndex != -1) {
                memo[index][prevIndex + 1] = Math.min(include, exclude);
                return memo[index][prevIndex + 1];
            }
            return Math.min(include, exclude);
        }
    
        public static int minInsertions(int[] arr) {
            int n = arr.length;
            int[][] memo = new int[n][n + 1];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
            return minInsertionsRecursive(arr, 0, -1, memo);
        }
    
        public static void main(String[] args) {
            int[] arr = {3, 1, 2, 5, 4};
            int result = minInsertions(arr);
            System.out.println("Minimum Insertions to Sort Array: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n<sup>2</sup>) (for memo array)