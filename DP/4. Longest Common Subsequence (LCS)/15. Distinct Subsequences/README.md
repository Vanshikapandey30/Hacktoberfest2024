Distinct Subsequences
=====================

Problem Definition
------------------

The **Distinct Subsequences** problem involves counting the number of distinct subsequences of a string `S` that equal another string `T`. A subsequence is derived from another string by deleting some or no characters without changing the order of the remaining characters.

Given two strings `S` and `T`, the goal is to find the number of distinct subsequences of `S` that equal `T`.

### Example

*   Input: `S = "rabbbit", T = "rabbit"`
*   Output: `3` (distinct subsequences: "rabbbit" -> "rabbit", "rabbbit" -> "rabbit", "rabbbit" -> "rabbit")

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a recursive function to explore all possible subsequences of `S` and count how many equal `T`.

#### Pseudocode

    function countDistinctSubsequences(S, T, i, j):
        if j == 0:
            return 1 // T is empty
        if i == 0:
            return 0 // S is empty
        if S[i-1] == T[j-1]:
            return countDistinctSubsequences(S, T, i-1, j-1) + countDistinctSubsequences(S, T, i-1, j)
        else:
            return countDistinctSubsequences(S, T, i-1, j)
    

#### Java Implementation

    public class DistinctSubsequencesRecursive {
    
        public static int countDistinctSubsequences(String s, String t, int i, int j) {
            if (j == 0) return 1;
            if (i == 0) return 0;
            if (s.charAt(i - 1) == t.charAt(j - 1)) {
                return countDistinctSubsequences(s, t, i - 1, j - 1) + countDistinctSubsequences(s, t, i - 1, j);
            } else {
                return countDistinctSubsequences(s, t, i - 1, j);
            }
        }
    
        public static void main(String[] args) {
            String s = "rabbbit";
            String t = "rabbit";
            int result = countDistinctSubsequences(s, t, s.length(), t.length());
            System.out.println("Count of distinct subsequences: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for the recursion stack)

### 2\. Dynamic Programming Approach

This approach uses dynamic programming to build a solution by storing results in a table to avoid redundant calculations.

#### Pseudocode

    function countDistinctSubsequences(S, T):
        dp = array of size (m + 1) x (n + 1) initialized to 0
        dp[0][0] = 1 // Empty T is a subsequence of empty S
        
        for i from 0 to m:
            dp[i][0] = 1 // Empty T can be formed by any prefix of S
        
        for i from 1 to m:
            for j from 1 to n:
                if S[i-1] == T[j-1]:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[m][n]
    

#### Java Implementation

    public class DistinctSubsequencesDP {
    
        public static int countDistinctSubsequences(String s, String t) {
            int m = s.length();
            int n = t.length();
            int[][] dp = new int[m + 1][n + 1];
            
            dp[0][0] = 1; // Empty T is a subsequence of empty S
            
            for (int i = 0; i <= m; i++) {
                dp[i][0] = 1; // Empty T can be formed by any prefix of S
            }
            
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s.charAt(i - 1) == t.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            
            return dp[m][n];
        }
    
        public static void main(String[] args) {
            String s = "rabbbit";
            String t = "rabbit";
            int result = countDistinctSubsequences(s, t);
            System.out.println("Count of distinct subsequences: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m \* n)
*   **Space Complexity:** O(m \* n) (for the dp array)

### 3\. Optimized Dynamic Programming Approach

This approach reduces space complexity by using a single array instead of a 2D array.

#### Pseudocode

    function countDistinctSubsequences(S, T):
        dp = array of size (n + 1) initialized to 0
        dp[0] = 1 // Empty T can be formed by any prefix of S
        
        for i from 1 to m:
            current = dp[0]
            for j from 1 to n:
                temp = dp[j]
                if S[i-1] == T[j-1]:
                    dp[j] = current + dp[j]
                current = temp
        
        return dp[n]
    

#### Java Implementation

    public class DistinctSubsequencesOptimized {
    
        public static int countDistinctSubsequences(String s, String t) {
            int m = s.length();
            int n = t.length();
            int[] dp = new int[n + 1];
            
            dp[0] = 1; // Empty T is a subsequence of any prefix of S
            
            for (int i = 1; i <= m; i++) {
                int current = dp[0];
                for (int j = 1; j <= n; j++) {
                    int temp = dp[j];
                    if (s.charAt(i - 1) == t.charAt(j - 1)) {
                        dp[j] = current + dp[j];
                    }
                    current = temp;
                }
            }
            
            return dp[n];
        }
    
        public static void main(String[] args) {
            String s = "rabbbit";
            String t = "rabbit";
            int result = countDistinctSubsequences(s, t);
            System.out.println("Count of distinct subsequences: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m \* n)
*   **Space Complexity:** O(n) (for the dp array)