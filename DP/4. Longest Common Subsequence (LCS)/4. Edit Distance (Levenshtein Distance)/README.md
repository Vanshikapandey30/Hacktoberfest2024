Edit Distance Problem (Levenshtein Distance)
============================================

Problem Definition
------------------

The **Edit Distance** (also known as **Levenshtein Distance**) between two strings is the minimum number of operations (insertions, deletions, or substitutions) required to convert one string into the other.

### Example

*   Input: `"horse"`, `"ros"`
*   Output: 3
*   Explanation: "horse" → "rorse" (substitute 'r' for 'h') → "rose" (delete 'r') → "ros" (delete 'e').

### Allowed Operations

*   Insert a character
*   Delete a character
*   Substitute a character

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach explores all possible operations (insert, delete, substitute) recursively to find the minimum operations required to match the two strings.

#### Pseudocode

    function editDistanceRecursive(s1, s2, i, j):
        if i == 0:
            return j
        if j == 0:
            return i
        
        if s1[i-1] == s2[j-1]:
            return editDistanceRecursive(s1, s2, i-1, j-1)
        else:
            return 1 + min(editDistanceRecursive(s1, s2, i-1, j),  // Deletion
                           editDistanceRecursive(s1, s2, i, j-1),  // Insertion
                           editDistanceRecursive(s1, s2, i-1, j-1)) // Substitution
    

#### Java Implementation

    public class EditDistance {
    
        public static int editDistanceRecursive(String s1, String s2, int i, int j) {
            if (i == 0) return j;
            if (j == 0) return i;
    
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                return editDistanceRecursive(s1, s2, i - 1, j - 1);
            } else {
                return 1 + Math.min(editDistanceRecursive(s1, s2, i - 1, j), // Deletion
                                   Math.min(editDistanceRecursive(s1, s2, i, j - 1), // Insertion
                                            editDistanceRecursive(s1, s2, i - 1, j - 1))); // Substitution
            }
        }
    
        public static void main(String[] args) {
            String s1 = "horse";
            String s2 = "ros";
            System.out.println(editDistanceRecursive(s1, s2, s1.length(), s2.length())); // Output: 3
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing previously computed results in a memoization table to avoid redundant computations.

#### Pseudocode

    function editDistanceMemo(s1, s2, i, j, memo):
        if i == 0:
            return j
        if j == 0:
            return i
        if memo[i][j] != -1:
            return memo[i][j]
        
        if s1[i-1] == s2[j-1]:
            memo[i][j] = editDistanceMemo(s1, s2, i-1, j-1, memo)
        else:
            memo[i][j] = 1 + min(editDistanceMemo(s1, s2, i-1, j, memo),  // Deletion
                                 editDistanceMemo(s1, s2, i, j-1, memo),  // Insertion
                                 editDistanceMemo(s1, s2, i-1, j-1, memo)) // Substitution
        return memo[i][j]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class EditDistance {
    
        public static int editDistanceMemo(String s1, String s2, int i, int j, int[][] memo) {
            if (i == 0) return j;
            if (j == 0) return i;
            if (memo[i][j] != -1) return memo[i][j];
    
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                memo[i][j] = editDistanceMemo(s1, s2, i - 1, j - 1, memo);
            } else {
                memo[i][j] = 1 + Math.min(editDistanceMemo(s1, s2, i - 1, j, memo), // Deletion
                                          Math.min(editDistanceMemo(s1, s2, i, j - 1, memo), // Insertion
                                                   editDistanceMemo(s1, s2, i - 1, j - 1, memo))); // Substitution
            }
            return memo[i][j];
        }
    
        public static void main(String[] args) {
            String s1 = "horse";
            String s2 = "ros";
            int[][] memo = new int[s1.length() + 1][s2.length() + 1];
            for (int[] row : memo) Arrays.fill(row, -1);
            System.out.println(editDistanceMemo(s1, s2, s1.length(), s2.length(), memo)); // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach iteratively computes the edit distance by storing intermediate results in a table.

#### Pseudocode

    function editDistanceDP(s1, s2):
        dp = array of size (len(s1)+1)(len(s2)+1)
        for i from 0 to len(s1):
            for j from 0 to len(s2):
                if i == 0:
                    dp[i][j] = j
                else if j == 0:
                    dp[i][j] = i
                else if s1[i-1] == s2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
        
        return dp[len(s1)][len(s2)]
    

#### Java Implementation

    public class EditDistance {
    
        public static int editDistanceDP(String s1, String s2) {
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
                        dp[i][j] = dp[i - 1][j - 1]; // Match
                    } else {
                        dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])); // No match
                    }
                }
            }
    
            return dp[m][n];
        }
    
        public static void main(String[] args) {
            String s1 = "horse";
            String s2 = "ros";
            System.out.println(editDistanceDP(s1, s2));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Time Complexity:**
    *   Recursive: O(3<sup>(m+n)</sup>) due to the three recursive calls at each step.
    *   Memoization: O(m \* n) as each subproblem is computed once.
    *   Dynamic Programming: O(m \* n) due to filling the dp table.
*   **Space Complexity:**
    *   Recursive: O(m + n) for the recursion stack.
    *   Memoization: O(m \* n) for the memoization table.
    *   Dynamic Programming: O(m \* n) for the DP table.