Longest Palindromic Subsequence
===============================

Problem Definition
------------------

The **Longest Palindromic Subsequence** (LPS) is the longest subsequence of a given string that is a palindrome. A subsequence is a sequence that can be derived from another string by deleting some or no elements, without changing the order of the remaining elements.

### Example

*   Input: `"bbbab"`
*   Output: 4
*   Explanation: One possible LPS is "bbbb".

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach explores every subsequence to find the longest palindromic one.

#### Pseudocode

    function lpsRecursive(s, start, end):
        if start == end:
            return 1
        if start > end:
            return 0
        if s[start] == s[end]:
            return 2 + lpsRecursive(s, start+1, end-1)
        else:
            return max(lpsRecursive(s, start+1, end), lpsRecursive(s, start, end-1))
    

#### Java Implementation

    public class LongestPalindromicSubsequence {
    
        public static int lpsRecursive(String s, int start, int end) {
            if (start == end) return 1;
            if (start > end) return 0;
    
            if (s.charAt(start) == s.charAt(end)) {
                return 2 + lpsRecursive(s, start + 1, end - 1);
            } else {
                return Math.max(lpsRecursive(s, start + 1, end), lpsRecursive(s, start, end - 1));
            }
        }
    
        public static void main(String[] args) {
            String s = "bbbab";
            System.out.println(lpsRecursive(s, 0, s.length() - 1)); // Output: 4
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing the results of subproblems to avoid redundant calculations.

#### Pseudocode

    function lpsMemo(s, start, end, memo):
        if start == end:
            return 1
        if start > end:
            return 0
        if memo[start][end] != -1:
            return memo[start][end]
        
        if s[start] == s[end]:
            memo[start][end] = 2 + lpsMemo(s, start+1, end-1, memo)
        else:
            memo[start][end] = max(lpsMemo(s, start+1, end, memo), lpsMemo(s, start, end-1, memo))
        return memo[start][end]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class LongestPalindromicSubsequence {
    
        public static int lpsMemo(String s, int start, int end, int[][] memo) {
            if (start == end) return 1;
            if (start > end) return 0;
            if (memo[start][end] != -1) return memo[start][end];
    
            if (s.charAt(start) == s.charAt(end)) {
                memo[start][end] = 2 + lpsMemo(s, start + 1, end - 1, memo);
            } else {
                memo[start][end] = Math.max(lpsMemo(s, start + 1, end, memo),
                                            lpsMemo(s, start, end - 1, memo));
            }
            return memo[start][end];
        }
    
        public static void main(String[] args) {
            String s = "bbbab";
            int[][] memo = new int[s.length()][s.length()];
            for (int[] row : memo) Arrays.fill(row, -1);
            System.out.println(lpsMemo(s, 0, s.length() - 1, memo)); // Output: 4
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table to iteratively calculate the LPS length for every substring of the given string.

#### Pseudocode

    function lpsDP(s):
        n = length of s
        dp = array of size (n)(n)
        
        for i from n-1 to 0:
            dp[i][i] = 1
            for j from i+1 to n-1:
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i+1][j-1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        
        return dp[0][n-1]
    

#### Java Implementation

    public class LongestPalindromicSubsequence {
    
        public static int lpsDP(String s) {
            int n = s.length();
            int[][] dp = new int[n][n];
    
            for (int i = n - 1; i >= 0; i--) {
                dp[i][i] = 1;
                for (int j = i + 1; j < n; j++) {
                    if (s.charAt(i) == s.charAt(j)) {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            return dp[0][n - 1];
        }
    
        public static void main(String[] args) {
            String s = "bbbab";
            System.out.println(lpsDP(s));  // Output: 4
        }
    }
    

Complexity Analysis
-------------------

*   **Time Complexity:**
    *   Recursive: O(2<sup>n</sup>), as it explores every possible subsequence.
    *   Memoization: O(n<sup>2</sup>), due to storing and using results of subproblems.
    *   Dynamic Programming: O(n<sup>2</sup>), as it fills an n x n table.
*   **Space Complexity:**
    *   Recursive: O(n), for recursion stack.
    *   Memoization: O(n<sup>2</sup>), for memoization table.
    *   Dynamic Programming: O(n<sup>2</sup>), for the dp table.