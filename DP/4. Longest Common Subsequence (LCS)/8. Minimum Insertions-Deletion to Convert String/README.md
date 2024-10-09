Minimum Insertions/Deletions to Convert String
==============================================

Problem Definition
------------------

The **Minimum Insertions/Deletions to Convert String** problem involves converting one string `str1` into another string `str2` using the minimum number of insertions and deletions. The task is to compute the minimum number of these operations needed to transform `str1` into `str2`.

### Example

*   Input: `str1 = "heap", str2 = "pea"`
*   Output: `3`
*   Explanation: We can delete 'h' from "heap" and insert 'p' to get "pea".

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach uses the idea of finding the longest common subsequence (LCS) between `str1` and `str2`. Based on the LCS, we compute the number of deletions and insertions required.

#### Pseudocode

    function lcsRecursive(str1, str2, m, n):
        if m == 0 or n == 0:
            return 0
        if str1[m-1] == str2[n-1]:
            return 1 + lcsRecursive(str1, str2, m-1, n-1)
        else:
            return max(lcsRecursive(str1, str2, m, n-1), lcsRecursive(str1, str2, m-1, n))
    
    function minInsertionsDeletions(str1, str2, m, n):
        lcs_len = lcsRecursive(str1, str2, m, n)
        deletions = m - lcs_len
        insertions = n - lcs_len
        return deletions + insertions
    

#### Java Implementation

    public class MinInsertionsDeletions {
    
        public static int lcsRecursive(String str1, String str2, int m, int n) {
            if (m == 0 || n == 0) return 0;
            
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                return 1 + lcsRecursive(str1, str2, m - 1, n - 1);
            } else {
                return Math.max(lcsRecursive(str1, str2, m, n - 1), lcsRecursive(str1, str2, m - 1, n));
            }
        }
    
        public static int minInsertionsDeletions(String str1, String str2) {
            int m = str1.length();
            int n = str2.length();
            int lcsLength = lcsRecursive(str1, str2, m, n);
            
            int deletions = m - lcsLength;
            int insertions = n - lcsLength;
            
            return deletions + insertions;
        }
    
        public static void main(String[] args) {
            String str1 = "heap";
            String str2 = "pea";
            System.out.println(minInsertionsDeletions(str1, str2));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive solution by storing intermediate results in a 2D table to avoid recomputing subproblems.

#### Pseudocode

    function lcsMemo(str1, str2, m, n, memo):
        if m == 0 or n == 0:
            return 0
        if memo[m][n] != -1:
            return memo[m][n]
        if str1[m-1] == str2[n-1]:
            memo[m][n] = 1 + lcsMemo(str1, str2, m-1, n-1, memo)
        else:
            memo[m][n] = max(lcsMemo(str1, str2, m, n-1, memo), lcsMemo(str1, str2, m-1, n, memo))
        return memo[m][n]
        
    function minInsertionsDeletionsMemo(str1, str2, m, n):
        lcs_len = lcsMemo(str1, str2, m, n, memo)
        deletions = m - lcs_len
        insertions = n - lcs_len
        return deletions + insertions
    

#### Java Implementation

    public class MinInsertionsDeletions {
    
        public static int lcsMemo(String str1, String str2, int m, int n, int[][] memo) {
            if (m == 0 || n == 0) return 0;
            if (memo[m][n] != -1) return memo[m][n];
            
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                memo[m][n] = 1 + lcsMemo(str1, str2, m - 1, n - 1, memo);
            } else {
                memo[m][n] = Math.max(lcsMemo(str1, str2, m, n - 1, memo), lcsMemo(str1, str2, m - 1, n, memo));
            }
            
            return memo[m][n];
        }
    
        public static int minInsertionsDeletionsMemo(String str1, String str2) {
            int m = str1.length();
            int n = str2.length();
            int[][] memo = new int[m + 1][n + 1];
            
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    memo[i][j] = -1;
                }
            }
    
            int lcsLength = lcsMemo(str1, str2, m, n, memo);
            
            int deletions = m - lcsLength;
            int insertions = n - lcsLength;
            
            return deletions + insertions;
        }
    
        public static void main(String[] args) {
            String str1 = "heap";
            String str2 = "pea";
            System.out.println(minInsertionsDeletionsMemo(str1, str2));  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach uses a 2D table to compute the LCS length iteratively and derive the number of insertions and deletions required.

#### Pseudocode

    function lcsDP(str1, str2):
        m = length of str1
        n = length of str2
        dp = 2D array of size (m+1)(n+1)
        
        for i from 1 to m:
            for j from 1 to n:
                if str1[i-1] == str2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        lcs_len = dp[m][n]
        deletions = m - lcs_len
        insertions = n - lcs_len
        return deletions + insertions
    

#### Java Implementation

    public class MinInsertionsDeletions {
    
        public static int lcsDP(String str1, String str2) {
            int m = str1.length();
            int n = str2.length();
            int[][] dp = new int[m + 1][n + 1];
    
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            int lcsLength = dp[m][n];
            
            int deletions = m - lcsLength;
            int insertions = n - lcsLength;
            
            return deletions + insertions;
        }
    
        public static void main(String[] args) {
            String str1 = "heap";
            String str2 = "pea";
            System.out.println(minInsertionsDeletions(str1, str2));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach**:
    *   Time Complexity: O(2<sup>(m + n)</sup>), exponential time complexity.
    *   Space Complexity: O(m + n), due to the recursion stack.
*   **Memoization Approach**:
    *   Time Complexity: O(m \* n), with memoization table storage.
    *   Space Complexity: O(m \* n), due to the memoization table.
*   **Dynamic Programming Approach**:
    *   Time Complexity: O(m \* n), with DP table storage.
    *   Space Complexity: O(m \* n), due to the DP table.