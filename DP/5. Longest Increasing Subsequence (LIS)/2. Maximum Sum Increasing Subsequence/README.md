Maximum Sum Increasing Subsequence (MSIS)
=========================================

Problem Definition
------------------

The **Maximum Sum Increasing Subsequence (MSIS)** problem asks for the maximum sum of an increasing subsequence in a given array of integers.

### Example

*   Input: `[1, 101, 2, 3, 100, 4, 5]`
*   Output: `106` (MSIS is `[1, 2, 3, 100]`)

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach recursively computes all subsequences, checks if they are increasing, and calculates the sum for each valid subsequence.

#### Pseudocode

    function msisRecursive(arr, n, prev, sum):
        if n == 0:
            return sum
        exclude = msisRecursive(arr, n-1, prev, sum)
        include = 0
        if arr[n-1] > prev:
            include = msisRecursive(arr, n-1, arr[n-1], sum + arr[n-1])
        return max(include, exclude)
    

#### Java Implementation

    public class MSISRecursive {
        public static int msisRecursive(int[] arr, int n, int prev, int sum) {
            if (n == 0) return sum;
            int exclude = msisRecursive(arr, n - 1, prev, sum);
            int include = 0;
            if (arr[n - 1] > prev) {
                include = msisRecursive(arr, n - 1, arr[n - 1], sum + arr[n - 1]);
            }
            return Math.max(include, exclude);
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 101, 2, 3, 100, 4, 5};
            int result = msisRecursive(arr, arr.length, Integer.MIN_VALUE, 0);
            System.out.println("Maximum Sum of Increasing Subsequence: " + result);  // Output: 106
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for recursion stack)

### 2\. Dynamic Programming Approach (O(n<sup>2</sup>))

We use dynamic programming to store the maximum sum of increasing subsequences ending at each index.

#### Pseudocode

    function msisDP(arr, n):
        dp = copy of arr
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] > arr[j]:
                    dp[i] = max(dp[i], dp[j] + arr[i])
        return max(dp)
    

#### Java Implementation

    public class MSISDP {
        public static int msisDP(int[] arr) {
            int n = arr.length;
            int[] dp = new int[n];
            System.arraycopy(arr, 0, dp, 0, n);
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        dp[i] = Math.max(dp[i], dp[j] + arr[i]);
                    }
                }
            }
    
            int maxSum = dp[0];
            for (int i = 1; i < n; i++) {
                maxSum = Math.max(maxSum, dp[i]);
            }
    
            return maxSum;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 101, 2, 3, 100, 4, 5};
            int result = msisDP(arr);
            System.out.println("Maximum Sum of Increasing Subsequence: " + result);  // Output: 106
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for the dp array)

### 3\. Optimized Approach (Binary Search and DP)

This optimized approach uses a combination of dynamic programming and binary search to speed up the process of finding the maximum sum increasing subsequence. This reduces the time complexity to `O(n log n)`.

#### Java Implementation

    import java.util.TreeMap;
    
    public class MSISOptimized {
        public static int msisOptimized(int[] arr) {
            TreeMap map = new TreeMap<>();
            int maxSum = 0;
    
            for (int num : arr) {
                Integer lowerKey = map.lowerKey(num);
                int newSum = (lowerKey == null ? 0 : map.get(lowerKey)) + num;
                map.put(num, newSum);
                maxSum = Math.max(maxSum, newSum);
            }
    
            return maxSum;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 101, 2, 3, 100, 4, 5};
            int result = msisOptimized(arr);
            System.out.println("Maximum Sum of Increasing Subsequence: " + result);  // Output: 106
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n log n)
*   **Space Complexity:** O(n) (for storing the map)