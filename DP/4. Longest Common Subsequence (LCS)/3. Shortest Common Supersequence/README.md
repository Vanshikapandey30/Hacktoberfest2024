Shortest Common Supersequence Problem
=====================================

Problem Definition
------------------

The **Shortest Common Supersequence** problem is to find the shortest sequence that has both strings as subsequences. In other words, it is the shortest string that contains both input strings as subsequences.

### Example

*   Input: `"abac"`, `"cab"`
*   Output: `"cabac"` or `"abacab"`
*   Explanation: Both "cabac" and "abacab" are shortest common supersequences of "abac" and "cab".

### Constraints

*   Input strings are non-empty.
*   Length of strings can vary.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach checks all possible combinations to build the supersequence by including characters from both strings.

#### Pseudocode

    function SCSRecursive(s1, s2, index1, index2):
        if index1 == 0: 
            return s2[0..index2 - 1]
        if index2 == 0:
            return s1[0..index1 - 1]
        
        if s1[index1 - 1] == s2[index2 - 1]:
            return SCSRecursive(s1, s2, index1 - 1, index2 - 1) + s1[index1 - 1]
        else:
            return min(SCSRecursive(s1, s2, index1 - 1, index2) + s1[index1 - 1], 
                       SCSRecursive(s1, s2, index1, index2 - 1) + s2[index2 - 1])
    

#### Java Implementation

    public class ShortestCommonSupersequence {
    
        public static String SCSRecursive(String s1, String s2, int index1, int index2) {
            if (index1 == 0) return s2.substring(0, index2);
            if (index2 == 0) return s1.substring(0, index1);
            
            if (s1.charAt(index1 - 1) == s2.charAt(index2 - 1)) {
                return SCSRecursive(s1, s2, index1 - 1, index2 - 1) + s1.charAt(index1 - 1);
            } else {
                String option1 = SCSRecursive(s1, s2, index1 - 1, index2) + s1.charAt(index1 - 1);
                String option2 = SCSRecursive(s1, s2, index1, index2 - 1) + s2.charAt(index2 - 1);
                return option1.length() < option2.length() ? option1 : option2;
            }
        }
    
        public static void main(String[] args) {
            String s1 = "abac";
            String s2 = "cab";
            System.out.println(SCSRecursive(s1, s2, s1.length(), s2.length()));  // Output: cabac or abacab
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing the results of subproblems (shortest common supersequences) in a memoization table to avoid recalculating them.

#### Pseudocode

    function SCSMemo(s1, s2, index1, index2, memo):
        if index1 == 0: 
            return s2[0..index2 - 1]
        if index2 == 0:
            return s1[0..index1 - 1]
        if memo[index1][index2] != "":
            return memo[index1][index2]
        
        if s1[index1 - 1] == s2[index2 - 1]:
            memo[index1][index2] = SCSMemo(s1, s2, index1 - 1, index2 - 1, memo) + s1[index1 - 1]
        else:
            option1 = SCSMemo(s1, s2, index1 - 1, index2, memo) + s1[index1 - 1]
            option2 = SCSMemo(s1, s2, index1, index2 - 1, memo) + s2[index2 - 1];
            memo[index1][index2] = option1.length() < option2.length() ? option1 : option2;
            
        return memo[index1][index2]
    

#### Java Implementation

    public class ShortestCommonSupersequence {
    
        public static String SCSMemo(String s1, String s2, int index1, int index2, String[][] memo) {
            if (index1 == 0) return s2.substring(0, index2);
            if (index2 == 0) return s1.substring(0, index1);
            if (!memo[index1][index2].equals("")) return memo[index1][index2];
    
            if (s1.charAt(index1 - 1) == s2.charAt(index2 - 1)) {
                memo[index1][index2] = SCSMemo(s1, s2, index1 - 1, index2 - 1, memo) + s1.charAt(index1 - 1);
            } else {
                String option1 = SCSMemo(s1, s2, index1 - 1, index2, memo) + s1.charAt(index1 - 1);
                String option2 = SCSMemo(s1, s2, index1, index2 - 1, memo) + s2.charAt(index2 - 1);
                memo[index1][index2] = option1.length() < option2.length() ? option1 : option2;
            }
            return memo[index1][index2];
        }
    
        public static void main(String[] args) {
            String s1 = "abac";
            String s2 = "cab";
            String[][] memo = new String[s1.length() + 1][s2.length() + 1];
            for (String[] row : memo) {
                Arrays.fill(row, "");
            }
            System.out.println(SCSMemo(s1, s2, s1.length(), s2.length(), memo));  // Output: cabac or abacab
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds up the solution iteratively, storing the lengths of the shortest common supersequences at each pair of indices in a DP table.

#### Pseudocode

    function SCS_DP(s1, s2):
        dp = array of size (len(s1)+1)(len(s2)+1)
        for i from 0 to len(s1):
            for j from 0 to len(s2):
                if i == 0:
                    dp[i][j] = j
                else if j == 0:
                    dp[i][j] = i
                else if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1
    
        return dp[len(s1)][len(s2)]
    

#### Java Implementation

    public class ShortestCommonSupersequence {
    
        public static int SCS_DP(String s1, String s2) {
            int m = s1.length();
            int n = s2.length();
            int[][] dp = new int[m + 1][n + 1];
    
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0) {
                        dp[i][j] = j;  // Fill first row
                    } else if (j == 0) {
                        dp[i][j] = i;  // Fill first column
                    } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + 1; // Match
                    } else {
                        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + 1; // No match
                    }
                }
            }
    
            return dp[m][n];
        }
    
        public static void main(String[] args) {
            String s1 = "abac";
            String s2 = "cab";
            System.out.println(SCS_DP(s1, s2));  // Output: Length of SCS
        }
    }
    

Complexity Analysis
-------------------

*   **Time Complexity:**
    *   Recursive: O(2<sup>(m+n)</sup>) where m and n are lengths of the input strings.
    *   Memoization: O(m \* n)
    *   Dynamic Programming: O(m \* n)
*   **Space Complexity:**
    *   Recursive: O(m+n) for the recursion stack.
    *   Memoization: O(m\*n) for the memoization table.
    *   Dynamic Programming: O(m\*n) for the DP table.