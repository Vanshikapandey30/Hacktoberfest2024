Largest Repeating Subsequence
=============================

Problem Definition
------------------

The **Largest Repeating Subsequence** problem involves finding the longest subsequence that appears at least twice in a given sequence. Unlike the longest common subsequence, the characters must not occupy the same position in the original string.

### Example

*   Input: `str = "AABEBCDD"`
*   Output: `"ABD"`

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a simple recursive function to explore all possibilities of forming the largest repeating subsequence. It compares characters of the string and makes recursive calls accordingly.

#### Pseudocode

    function lrsRecursive(str, i, j, count):
        if i == length of str or j == length of str:
            return count
        if str[i] == str[j] and i != j:
            count = lrsRecursive(str, i + 1, j + 1, count + 1)
        count = max(count, lrsRecursive(str, i + 1, j, count), 
                             lrsRecursive(str, i, j + 1, count))
        return count
    

#### Java Implementation

    public class LargestRepeatingSubsequenceRecursive {
    
        public static int lrsRecursive(String str, int i, int j) {
            if (i == str.length() || j == str.length()) return 0;
            int count = 0;
            if (str.charAt(i) == str.charAt(j) && i != j) {
                count = 1 + lrsRecursive(str, i + 1, j + 1);
            }
            return Math.max(count, Math.max(lrsRecursive(str, i + 1, j), 
                                              lrsRecursive(str, i, j + 1)));
        }
    
        public static void main(String[] args) {
            String str = "AABEBCDD";
            int length = lrsRecursive(str, 0, 1);
            System.out.println("Length of Largest Repeating Subsequence is " + length);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (due to call stack)

### 2\. Memoization Approach

This approach uses memoization to store results of subproblems, improving efficiency by avoiding redundant calculations.

#### Pseudocode

    function lrsMemoization(str, i, j, memo):
        if i == length of str or j == length of str:
            return 0
        if memo[i][j] is not null:
            return memo[i][j]
        
        if str[i] == str[j] and i != j:
            memo[i][j] = 1 + lrsMemoization(str, i + 1, j + 1, memo)
        else:
            memo[i][j] = max(lrsMemoization(str, i + 1, j, memo), 
                             lrsMemoization(str, i, j + 1, memo))
        
        return memo[i][j]
    

#### Java Implementation

    public class LargestRepeatingSubsequenceMemoization {
    
        public static int lrsMemoization(String str, int i, int j, Integer[][] memo) {
            if (i == str.length() || j == str.length()) return 0;
            if (memo[i][j] != null) return memo[i][j];
    
            int count = 0;
            if (str.charAt(i) == str.charAt(j) && i != j) {
                count = 1 + lrsMemoization(str, i + 1, j + 1, memo);
            }
            memo[i][j] = Math.max(count, Math.max(lrsMemoization(str, i + 1, j, memo), 
                                                  lrsMemoization(str, i, j + 1, memo)));
            return memo[i][j];
        }
    
        public static void main(String[] args) {
            String str = "AABEBCDD";
            Integer[][] memo = new Integer[str.length()][str.length()];
            int length = lrsMemoization(str, 0, 1, memo);
            System.out.println("Length of Largest Repeating Subsequence is " + length);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n<sup>2</sup>) (for memoization table)

### 3\. Tabulation Approach

This approach utilizes a bottom-up dynamic programming table to compute the length of the largest repeating subsequence based on previously computed lengths of smaller subproblems.

#### Pseudocode

    function lrsTabulation(str):
        n = length of str
        dp = 2D array of size (n+1)(n+1)
    
        for i from 0 to n:
            for j from 0 to n:
                if i == 0 or j == 0:
                    dp[i][j] = 0
                else if str[i-1] == str[j-1] and i != j:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][n]
    

#### Java Implementation

    public class LargestRepeatingSubsequenceTabulation {
    
        public static int lrsTabulation(String str) {
            int n = str.length();
            int[][] dp = new int[n + 1][n + 1];
    
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (str.charAt(i - 1) == str.charAt(j - 1) && i != j) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            return dp[n][n];
        }
    
        public static void main(String[] args) {
            String str = "AABEBCDD";
            int length = lrsTabulation(str);
            System.out.println("Length of Largest Repeating Subsequence is " + length);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n<sup>2</sup>) (for the DP table)

Conclusion
----------

The Largest Repeating Subsequence problem can be approached in different ways. The recursive method is straightforward but least efficient, while memoization and tabulation offer significant improvements in efficiency through dynamic programming techniques.