Sequence Pattern Matching
=========================

Problem Definition
------------------

The **Sequence Pattern Matching** problem checks whether a given string `str1` is a subsequence of another string `str2`. The task is to determine if all characters of `str1` appear in `str2`, in the same order but not necessarily consecutively.

### Example

*   Input: `str1 = "abc", str2 = "ahbgdc"`
*   Output: `true`
*   Explanation: The string "abc" is a subsequence of "ahbgdc".

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach checks if the last character of `str1` matches with the last character of `str2`. If it matches, we recursively check for the remaining characters; otherwise, we continue by reducing the length of `str2`.

#### Pseudocode

    function isSubsequenceRecursive(str1, str2, m, n):
        if m == 0:
            return true
        if n == 0:
            return false
        if str1[m-1] == str2[n-1]:
            return isSubsequenceRecursive(str1, str2, m-1, n-1)
        else:
            return isSubsequenceRecursive(str1, str2, m, n-1)
    

#### Java Implementation

    public class SequencePatternMatching {
    
        public static boolean isSubsequenceRecursive(String str1, String str2, int m, int n) {
            if (m == 0) return true;
            if (n == 0) return false;
            
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                return isSubsequenceRecursive(str1, str2, m - 1, n - 1);
            } else {
                return isSubsequenceRecursive(str1, str2, m, n - 1);
            }
        }
    
        public static void main(String[] args) {
            String str1 = "abc";
            String str2 = "ahbgdc";
            System.out.println(isSubsequenceRecursive(str1, str2, str1.length(), str2.length()));  // Output: true
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing intermediate results in a 2D memoization table. It avoids recomputing results for the same subproblems.

#### Pseudocode

    function isSubsequenceMemo(str1, str2, m, n, memo):
        if m == 0:
            return true
        if n == 0:
            return false
        if memo[m][n] != -1:
            return memo[m][n]
        if str1[m-1] == str2[n-1]:
            memo[m][n] = isSubsequenceMemo(str1, str2, m-1, n-1, memo)
        else:
            memo[m][n] = isSubsequenceMemo(str1, str2, m, n-1, memo)
        return memo[m][n]
    

#### Java Implementation

    public class SequencePatternMatching {
    
        public static boolean isSubsequenceMemo(String str1, String str2, int m, int n, int[][] memo) {
            if (m == 0) return true;
            if (n == 0) return false;
            if (memo[m][n] != -1) return memo[m][n] == 1;
            
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                memo[m][n] = isSubsequenceMemo(str1, str2, m - 1, n - 1, memo) ? 1 : 0;
            } else {
                memo[m][n] = isSubsequenceMemo(str1, str2, m, n - 1, memo) ? 1 : 0;
            }
            return memo[m][n] == 1;
        }
    
        public static void main(String[] args) {
            String str1 = "abc";
            String str2 = "ahbgdc";
            int[][] memo = new int[str1.length() + 1][str2.length() + 1];
            for (int i = 0; i <= str1.length(); i++) {
                for (int j = 0; j <= str2.length(); j++) {
                    memo[i][j] = -1;
                }
            }
            System.out.println(isSubsequenceMemo(str1, str2, str1.length(), str2.length(), memo));  // Output: true
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a 2D table to check if `str1` is a subsequence of `str2`. The table is filled based on whether the characters of the strings match or not.

#### Pseudocode

    function isSubsequenceDP(str1, str2):
        m = length of str1
        n = length of str2
        dp = 2D array of size (m+1)(n+1)
        
        for i from 0 to m:
            dp[i][0] = false
        for j from 0 to n:
            dp[0][j] = true
        
        for i from 1 to m:
            for j from 1 to n:
                if str1[i-1] == str2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i][j-1]
        
        return dp[m][n]
    

#### Java Implementation

    public class SequencePatternMatching {
    
        public static boolean isSubsequenceDP(String str1, String str2) {
            int m = str1.length();
            int n = str2.length();
            boolean[][] dp = new boolean[m + 1][n + 1];
    
            for (int i = 0; i <= m; i++) {
                dp[i][0] = false;
            }
            for (int j = 0; j <= n; j++) {
                dp[0][j] = true;
            }
    
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
    
            return dp[m][n];
        }
    
        public static void main(String[] args) {
            String str1 = "abc";
            String str2 = "ahbgdc";
            System.out.println(isSubsequenceDP(str1, str2));  // Output: true
        }
    }
    

Complexity Analysis
-------------------

*   **Time Complexity:**
    *   Recursive: O(2<sup>n</sup>), as it explores multiple paths in the recursive tree.
    *   Memoization: O(m \* n), due to memoization storing intermediate results.
    *   Dynamic Programming: O(m \* n), as it builds the table of subsequences.
*   **Space Complexity:**
    *   Recursive: O(m + n), for recursion stack.
    *   Memoization: O(m \* n), for storing memoization table.
    *   Dynamic Programming: O(m \* n), for DP table storage.