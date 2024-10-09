Longest Common Subsequence (LCS) Problem
========================================

Problem Definition
------------------

The **Longest Common Subsequence (LCS)** problem is to find the longest subsequence present in two sequences (strings). A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, `"abc"` is a subsequence of `"aebdc"`, while `"abdc"` is not.

### Example

*   Input: `"abcde"`, `"ace"`
*   Output: `3`
*   Explanation: The longest common subsequence is `"ace"`.

### Constraints

*   Input strings are non-empty.
*   Length of strings can vary.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach checks the last characters of both strings and recursively computes the LCS length.

#### Pseudocode

    function LCSRecursive(s1, s2, index1, index2):
        if index1 == 0 or index2 == 0:
            return 0
        if s1[index1 - 1] == s2[index2 - 1]:
            return 1 + LCSRecursive(s1, s2, index1 - 1, index2 - 1)
        else:
            return max(LCSRecursive(s1, s2, index1, index2 - 1), LCSRecursive(s1, s2, index1 - 1, index2))
    

#### Java Implementation

    public class LCS {
    
        public static int LCSRecursive(String s1, String s2, int index1, int index2) {
            if (index1 == 0 || index2 == 0) return 0;
            if (s1.charAt(index1 - 1) == s2.charAt(index2 - 1)) {
                return 1 + LCSRecursive(s1, s2, index1 - 1, index2 - 1);
            } else {
                return Math.max(LCSRecursive(s1, s2, index1, index2 - 1),
                                 LCSRecursive(s1, s2, index1 - 1, index2));
            }
        }
    
        public static void main(String[] args) {
            String s1 = "abcde";
            String s2 = "ace";
            System.out.println(LCSRecursive(s1, s2, s1.length(), s2.length()));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing the results of subproblems (LCS lengths for different indices) in a memoization table to avoid recalculating them.

#### Pseudocode

    function LCSMemo(s1, s2, index1, index2, memo):
        if memo[index1][index2] != -1:
            return memo[index1][index2]
        if index1 == 0 or index2 == 0:
            return 0
        if s1[index1 - 1] == s2[index2 - 1]:
            memo[index1][index2] = 1 + LCSMemo(s1, s2, index1 - 1, index2 - 1, memo)
        else:
            memo[index1][index2] = max(LCSMemo(s1, s2, index1, index2 - 1, memo),
                                        LCSMemo(s1, s2, index1 - 1, index2, memo))
        return memo[index1][index2]
    

#### Java Implementation

    public class LCS {
    
        public static int LCSMemo(String s1, String s2, int index1, int index2, int[][] memo) {
            if (memo[index1][index2] != -1) return memo[index1][index2];
            if (index1 == 0 || index2 == 0) return 0;
    
            if (s1.charAt(index1 - 1) == s2.charAt(index2 - 1)) {
                memo[index1][index2] = 1 + LCSMemo(s1, s2, index1 - 1, index2 - 1, memo);
            } else {
                memo[index1][index2] = Math.max(LCSMemo(s1, s2, index1, index2 - 1, memo),
                                                  LCSMemo(s1, s2, index1 - 1, index2, memo));
            }
            return memo[index1][index2];
        }
    
        public static void main(String[] args) {
            String s1 = "abcde";
            String s2 = "ace";
            int[][] memo = new int[s1.length() + 1][s2.length() + 1];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
            System.out.println(LCSMemo(s1, s2, s1.length(), s2.length(), memo));  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds up the solution iteratively, storing the LCS length at each pair of indices in a DP table.

#### Pseudocode

    function LCSDP(s1, s2):
        dp = array of size (len(s1)+1)(len(s2)+1)
        for i from 0 to len(s1):
            for j from 0 to len(s2):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                else if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[len(s1)][len(s2)]
    

#### Java Implementation

    public class LCS {
    
        public static int LCSDP(String s1, String s2) {
            int[][] dp = new int[s1.length() + 1][s2.length() + 1];
    
            for (int i = 0; i <= s1.length(); i++) {
                for (int j = 0; j <= s2.length(); j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 0;
                    } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[s1.length()][s2.length()];
        }
    
        public static void main(String[] args) {
            String s1 = "abcde";
            String s2 = "ace";
            System.out.println(LCSDP(s1, s2));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n \* m) time, O(n \* m) space (due to memoization array).
*   **Dynamic Programming (Tabulation) Approach:** O(n \* m) time, O(n \* m) space (due to DP table).