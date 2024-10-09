Print Longest Common Subsequence
================================

Problem Definition
------------------

The **Longest Common Subsequence (LCS)** problem involves finding the longest subsequence present in two sequences. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, the LCS of "AGGTAB" and "GXTXAYB" is "GTAB".

### Example

*   Input: `str1 = "AGGTAB", str2 = "GXTXAYB"`
*   Output: `"GTAB"`

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a simple recursive function to explore all possibilities of forming the LCS. It compares characters of both strings and makes recursive calls accordingly.

#### Pseudocode

    function lcsRecursive(str1, str2, m, n):
        if m == 0 or n == 0:
            return 0
        if str1[m-1] == str2[n-1]:
            return 1 + lcsRecursive(str1, str2, m-1, n-1)
        else:
            return max(lcsRecursive(str1, str2, m-1, n), lcsRecursive(str1, str2, m, n-1))
    

#### Java Implementation

    public class LongestCommonSubsequenceRecursive {
    
        public static int lcsRecursive(String str1, String str2, int m, int n) {
            if (m == 0 || n == 0) return 0;
            if (str1.charAt(m - 1) == str2.charAt(n - 1) ) {
                return 1 + lcsRecursive(str1, str2, m - 1, n - 1);
            } else {
                return Math.max(lcsRecursive(str1, str2, m - 1, n), 
                                lcsRecursive(str1, str2, m, n - 1));
            }
        }
    
        public static void main(String[] args) {
            String str1 = "AGGTAB";
            String str2 = "GXTXAYB";
            int length = lcsRecursive(str1, str2, str1.length(), str2.length());
            System.out.println("Length of LCS is " + length);  // Output: 4
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>m+n</sup>)
*   **Space Complexity:** O(m+n) (due to call stack)

### 2\. Memoization Approach

This approach uses memoization to store results of subproblems, improving efficiency by avoiding redundant calculations.

#### Pseudocode

    function lcsMemoization(str1, str2, m, n, memo):
        if m == 0 or n == 0:
            return 0
        if memo[m][n] is not null:
            return memo[m][n]
        
        if str1[m-1] == str2[n-1]:
            memo[m][n] = 1 + lcsMemoization(str1, str2, m-1, n-1, memo)
        else:
            memo[m][n] = max(lcsMemoization(str1, str2, m-1, n, memo), 
                             lcsMemoization(str1, str2, m, n-1, memo))
        
        return memo[m][n]
    

#### Java Implementation

    public class LongestCommonSubsequenceMemoization {
    
        public static int lcsMemoization(String str1, String str2, int m, int n, int[][] memo) {
            if (m == 0 || n == 0) return 0;
            if (memo[m][n] != -1) return memo[m][n];
    
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                memo[m][n] = 1 + lcsMemoization(str1, str2, m - 1, n - 1, memo);
            } else {
                memo[m][n] = Math.max(lcsMemoization(str1, str2, m - 1, n, memo), 
                                      lcsMemoization(str1, str2, m, n - 1, memo));
            }
    
            return memo[m][n];
        }
    
        public static void main(String[] args) {
            String str1 = "AGGTAB";
            String str2 = "GXTXAYB";
            int m = str1.length(), n = str2.length();
            int[][] memo = new int[m + 1][n + 1];
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    memo[i][j] = -1;
                }
            }
            int length = lcsMemoization(str1, str2, m, n, memo);
            System.out.println("Length of LCS is " + length);  // Output: 4
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n)
*   **Space Complexity:** O(m\*n) (for memoization table)

### 3\. Tabulation Approach

This approach utilizes a bottom-up dynamic programming table to compute the length of LCS based on previously computed lengths of smaller subproblems.

#### Pseudocode

    function lcsTabulation(str1, str2):
        m = length of str1
        n = length of str2
        dp = 2D array of size (m+1)(n+1)
    
        for i from 0 to m:
            for j from 0 to n:
                if i == 0 or j == 0:
                    dp[i][j] = 0
                else if str1[i-1] == str2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[m][n]
    

#### Java Implementation

    public class LongestCommonSubsequenceTabulation {
    
        public static int lcsTabulation(String str1, String str2) {
            int m = str1.length();
            int n = str2.length();
            int[][] dp = new int[m + 1][n + 1];
    
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 0;
                    } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            return dp[m][n];
        }
    
        public static void main(String[] args) {
            String str1 = "AGGTAB";
            String str2 = "GXTXAYB";
            int length = lcsTabulation(str1, str2);
            System.out.println("Length of LCS is " + length);  // Output: 4
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n)
*   **Space Complexity:** O(m\*n) (for the DP table)

Conclusion
----------

The Longest Common Subsequence problem can be approached in different ways. The recursive method is the simplest but least efficient, while memoization and tabulation offer significant improvements in efficiency through the use of dynamic programming techniques.