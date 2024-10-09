Longest Divisible Subsequence
=============================

Problem Definition
------------------

The Longest Divisible Subsequence problem involves finding the longest subsequence in a given sequence of integers where every element in the subsequence is divisible by the previous element. The subsequence does not need to be contiguous.

### Example

*   Input: `[1, 2, 3, 4, 6, 12]`
*   Output: `5` (The subsequence `[1, 2, 4, 12]` is divisible)

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a simple recursion to find the longest divisible subsequence.

#### Pseudocode

    function longestDivisibleSubsequenceRecursive(arr, index):
        if index == 0:
            return 1
        maxLength = 1
        for j from 0 to index - 1:
            if arr[index] % arr[j] == 0:
                maxLength = max(maxLength, 1 + longestDivisibleSubsequenceRecursive(arr, j))
        return maxLength
    
    function longestDivisibleSubsequence(arr):
        n = length of arr
        result = 0
        for i from 0 to n - 1:
            result = max(result, longestDivisibleSubsequenceRecursive(arr, i))
        return result
    

#### Java Implementation

    public class LongestDivisibleSubsequenceRecursive {
        public static int longestDivisibleSubsequenceRecursive(int[] arr, int index) {
            if (index == 0) return 1;
            int maxLength = 1;
            for (int j = 0; j < index; j++) {
                if (arr[index] % arr[j] == 0) {
                    maxLength = Math.max(maxLength, 1 + longestDivisibleSubsequenceRecursive(arr, j));
                }
            }
            return maxLength;
        }
    
        public static int longestDivisibleSubsequence(int[] arr) {
            int n = arr.length;
            int result = 0;
            for (int i = 0; i < n; i++) {
                result = Math.max(result, longestDivisibleSubsequenceRecursive(arr, i));
            }
            return result;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 2, 3, 4, 6, 12};
            int result = longestDivisibleSubsequence(arr);
            System.out.println("Length of Longest Divisible Subsequence: " + result);  // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(1) (no extra space required)

### 2\. Dynamic Programming Approach (O(n<sup>2</sup>))

This approach uses dynamic programming to find the longest divisible subsequence by checking each element against all previous elements.

#### Pseudocode

    function longestDivisibleSubsequence(arr):
        n = length of arr
        dp = array of size n initialized to 1
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] % arr[j] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    

#### Java Implementation

    public class LongestDivisibleSubsequenceDP {
        public static int longestDivisibleSubsequence(int[] arr) {
            int n = arr.length;
            int[] dp = new int[n];
            Arrays.fill(dp, 1);
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] % arr[j] == 0) {
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
    
        public static void main(String[] args) {
            int[] arr = {1, 2, 3, 4, 6, 12};
            int result = longestDivisibleSubsequence(arr);
            System.out.println("Length of Longest Divisible Subsequence: " + result);  // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for dp array)

### 3\. Memoization Approach (Top-Down) (O(n<sup>2</sup>))

This approach uses recursion with memoization to avoid recomputing results for already computed subproblems.

#### Pseudocode

    function longestDivisibleSubsequenceMemo(arr, index, dp):
        if index == 0:
            return 1
        if dp[index] is not -1:
            return dp[index]
    
        maxLength = 1
        for j from 0 to index - 1:
            if arr[index] % arr[j] == 0:
                maxLength = max(maxLength, 1 + longestDivisibleSubsequenceMemo(arr, j, dp))
        dp[index] = maxLength
        return maxLength
    
    function longestDivisibleSubsequence(arr):
        n = length of arr
        dp = array of size n initialized to -1
        result = 0
        for i from 0 to n - 1:
            result = max(result, longestDivisibleSubsequenceMemo(arr, i, dp))
        return result
    

#### Java Implementation

    public class LongestDivisibleSubsequenceMemo {
        public static int longestDivisibleSubsequenceMemo(int[] arr, int index, int[] dp) {
            if (index == 0) return 1;
            if (dp[index] != -1) return dp[index];
    
            int maxLength = 1;
            for (int j = 0; j < index; j++) {
                if (arr[index] % arr[j] == 0) {
                    maxLength = Math.max(maxLength, 1 + longestDivisibleSubsequenceMemo(arr, j, dp));
                }
            }
            dp[index] = maxLength;
            return maxLength;
        }
    
        public static int longestDivisibleSubsequence(int[] arr) {
            int n = arr.length;
            int[] dp = new int[n];
            Arrays.fill(dp, -1);
            int result = 0;
    
            for (int i = 0; i < n; i++) {
                result = Math.max(result, longestDivisibleSubsequenceMemo(arr, i, dp));
            }
            return result;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 2, 3, 4, 6, 12};
            int result = longestDivisibleSubsequence(arr);
            System.out.println("Length of Longest Divisible Subsequence: " + result);  // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for dp array)

### 4\. Tabulation Approach (Bottom-Up) (O(n2))

This approach uses a bottom-up technique to build the solution iteratively.

#### Pseudocode

    function longestDivisibleSubsequence(arr):
        n = length of arr
        dp = array of size n initialized to 1
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] % arr[j] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    

#### Java Implementation

    public class LongestDivisibleSubsequenceTabulation {
        public static int longestDivisibleSubsequence(int[] arr) {
            int n = arr.length;
            int[] dp = new int[n];
            Arrays.fill(dp, 1);
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] % arr[j] == 0) {
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
    
        public static void main(String[] args) {
            int[] arr = {1, 2, 3, 4, 6, 12};
            int result = longestDivisibleSubsequence(arr);
            System.out.println("Length of Longest Divisible Subsequence: " + result);  // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for dp array)