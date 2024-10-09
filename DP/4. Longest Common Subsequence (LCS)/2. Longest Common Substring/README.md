Longest Common Substring Problem
================================

Problem Definition
------------------

The **Longest Common Substring** problem is to find the longest substring present in two strings. Unlike the longest common subsequence problem, the characters in the substring must be contiguous.

### Example

*   Input: `"abcde"`, `"abfce"`
*   Output: `2`
*   Explanation: The longest common substring is `"ab"`.

### Constraints

*   Input strings are non-empty.
*   Length of strings can vary.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach checks all possible substrings and recursively computes the longest common substring.

#### Pseudocode

    function LCSRecursive(s1, s2, index1, index2, count):
        if index1 == 0 or index2 == 0:
            return count
        if s1[index1 - 1] == s2[index2 - 1]:
            count = LCSRecursive(s1, s2, index1 - 1, index2 - 1, count + 1)
        count1 = LCSRecursive(s1, s2, index1 - 1, index2, 0)
        count2 = LCSRecursive(s1, s2, index1, index2 - 1, 0)
        return max(count, max(count1, count2))
    

#### Java Implementation

    public class LongestCommonSubstring {
    
        public static int LCSRecursive(String s1, String s2, int index1, int index2, int count) {
            if (index1 == 0 || index2 == 0) return count;
    
            if (s1.charAt(index1 - 1) == s2.charAt(index2 - 1)) {
                count = LCSRecursive(s1, s2, index1 - 1, index2 - 1, count + 1);
            }
            int count1 = LCSRecursive(s1, s2, index1 - 1, index2, 0);
            int count2 = LCSRecursive(s1, s2, index1, index2 - 1, 0);
            
            return Math.max(count, Math.max(count1, count2));
        }
    
        public static void main(String[] args) {
            String s1 = "abcde";
            String s2 = "abfce";
            System.out.println(LCSRecursive(s1, s2, s1.length(), s2.length(), 0));  // Output: 2
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing the results of subproblems (lengths of common substrings) in a memoization table to avoid recalculating them.

#### Pseudocode

    function LCSMemo(s1, s2, index1, index2, count, memo):
        if index1 == 0 or index2 == 0:
            return count
        if memo[index1][index2] != -1:
            return memo[index1][index2]
        
        if s1[index1 - 1] == s2[index2 - 1]:
            count = LCSMemo(s1, s2, index1 - 1, index2 - 1, count + 1, memo)
        else:
            count = 0
    
        memo[index1][index2] = max(count, max(LCSMemo(s1, s2, index1 - 1, index2, 0, memo),
                                              LCSMemo(s1, s2, index1, index2 - 1, 0, memo)))
        return memo[index1][index2]
    

#### Java Implementation

    public class LongestCommonSubstring {
    
        public static int LCSMemo(String s1, String s2, int index1, int index2, int count, int[][] memo) {
            if (index1 == 0 || index2 == 0) return count;
            if (memo[index1][index2] != -1) return memo[index1][index2];
    
            if (s1.charAt(index1 - 1) == s2.charAt(index2 - 1)) {
                count = LCSMemo(s1, s2, index1 - 1, index2 - 1, count + 1, memo);
            } else {
                count = 0;
            }
    
            memo[index1][index2] = Math.max(count, Math.max(LCSMemo(s1, s2, index1 - 1, index2, 0, memo),
                                                             LCSMemo(s1, s2, index1, index2 - 1, 0, memo)));
            return memo[index1][index2];
        }
    
        public static void main(String[] args) {
            String s1 = "abcde";
            String s2 = "abfce";
            int[][] memo = new int[s1.length() + 1][s2.length() + 1];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
            System.out.println(LCSMemo(s1, s2, s1.length(), s2.length(), 0, memo));  // Output: 2
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds up the solution iteratively, storing the lengths of common substrings at each pair of indices in a DP table.

#### Pseudocode

    function LCSDP(s1, s2):
        dp = array of size (len(s1)+1)(len(s2)+1)
        maxLength = 0
        for i from 1 to len(s1):
            for j from 1 to len(s2):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    maxLength = max(maxLength, dp[i][j])
                else:
                    dp[i][j] = 0
        return maxLength
    

#### Java Implementation

    public class LongestCommonSubstring {
    
        public static int LCSDP(String s1, String s2) {
            int[][] dp = new int[s1.length() + 1][s2.length() + 1];
            int maxLength = 0;
    
            for (int i = 1; i <= s1.length(); i++) {
                for (int j = 1; j <= s2.length(); j++) {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        maxLength = Math.max(maxLength, dp[i][j]);
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
            return maxLength;
        }
    
        public static void main(String[] args) {
            String s1 = "abcde";
            String s2 = "abfce";
            System.out.println(LCSDP(s1, s2));  // Output: 2
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n \* m) time, O(n \* m) space (due to memoization array).
*   **Dynamic Programming (Tabulation) Approach:** O(n \* m) time, O(n \* m) space (due to DP table).