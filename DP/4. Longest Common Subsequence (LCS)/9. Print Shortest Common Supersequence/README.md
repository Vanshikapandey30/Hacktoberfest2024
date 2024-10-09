Print Shortest Common Supersequence
===================================

Problem Definition
------------------

The **Shortest Common Supersequence (SCS)** problem involves finding the shortest string that contains both given strings `str1` and `str2` as subsequences. The objective is to find the SCS of the two strings.

### Example

*   Input: `str1 = "abac", str2 = "cab"`
*   Output: `"cabac"`
*   Explanation: The SCS for the two strings is "cabac".

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach utilizes a recursive function to explore all possibilities of forming the SCS. It checks characters of both strings and makes recursive calls accordingly.

#### Pseudocode

    function scsRecursive(str1, str2, m, n):
        if m == 0:
            return str2[0 to n-1]
        if n == 0:
            return str1[0 to m-1]
        
        if str1[m-1] == str2[n-1]:
            return scsRecursive(str1, str2, m-1, n-1) + str1[m-1]
        else:
            return min(scsRecursive(str1, str2, m-1, n) + str1[m-1], 
                       scsRecursive(str1, str2, m, n-1) + str2[n-1])
    

#### Java Implementation

    public class ShortestCommonSupersequenceRecursive {
    
        public static String scsRecursive(String str1, String str2, int m, int n) {
            if (m == 0) return str2.substring(0, n);
            if (n == 0) return str1.substring(0, m);
    
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                return scsRecursive(str1, str2, m - 1, n - 1) + str1.charAt(m - 1);
            } else {
                String left = scsRecursive(str1, str2, m - 1, n) + str1.charAt(m - 1);
                String right = scsRecursive(str1, str2, m, n - 1) + str2.charAt(n - 1);
                return left.length() < right.length() ? left : right;
            }
        }
    
        public static void main(String[] args) {
            String str1 = "abac";
            String str2 = "cab";
            System.out.println(scsRecursive(str1, str2, str1.length(), str2.length()));  // Output: "cabac"
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:**  O(2<sup>m+n</sup>)
*   **Space Complexity:** O(m+n) (due to call stack)

### 2\. Memoization Approach

This approach uses memoization to store the results of subproblems to avoid redundant computations, enhancing the recursive method's efficiency.

#### Pseudocode

    function scsMemoization(str1, str2, m, n, memo):
        if m == 0:
            return str2[0 to n-1]
        if n == 0:
            return str1[0 to m-1]
        if memo[m][n] is not null:
            return memo[m][n]
        
        if str1[m-1] == str2[n-1]:
            memo[m][n] = scsMemoization(str1, str2, m-1, n-1, memo) + str1[m-1]
        else:
            memo[m][n] = min(scsMemoization(str1, str2, m-1, n, memo) + str1[m-1], 
                             scsMemoization(str1, str2, m, n-1, memo) + str2[n-1])
        
        return memo[m][n]
    

#### Java Implementation

    public class ShortestCommonSupersequenceMemoization {
    
        public static String scsMemoization(String str1, String str2, int m, int n, String[][] memo) {
            if (m == 0) return str2.substring(0, n);
            if (n == 0) return str1.substring(0, m);
            if (memo[m][n] != null) return memo[m][n];
    
            if (str1.charAt(m - 1) == str2.charAt(n - 1)) {
                memo[m][n] = scsMemoization(str1, str2, m - 1, n - 1, memo) + str1.charAt(m - 1);
            } else {
                String left = scsMemoization(str1, str2, m - 1, n, memo) + str1.charAt(m - 1);
                String right = scsMemoization(str1, str2, m, n - 1, memo) + str2.charAt(n - 1);
                memo[m][n] = left.length() < right.length() ? left : right;
            }
    
            return memo[m][n];
        }
    
        public static void main(String[] args) {
            String str1 = "abac";
            String str2 = "cab";
            int m = str1.length(), n = str2.length();
            String[][] memo = new String[m + 1][n + 1];
            System.out.println(scsMemoization(str1, str2, m, n, memo));  // Output: "cabac"
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n)
*   **Space Complexity:** O(m\*n) (for memoization table)

### 3\. Tabulation Approach

This approach uses a bottom-up dynamic programming table to calculate the lengths of SCS based on previously computed lengths of smaller subproblems.

#### Pseudocode

    function scsTabulation(str1, str2):
        m = length of str1
        n = length of str2
        dp = 2D array of size (m+1)(n+1)
    
        for i from 0 to m:
            for j from 0 to n:
                if i == 0:
                    dp[i][j] = str2[0 to j-1]
                else if j == 0:
                    dp[i][j] = str1[0 to i-1]
                else if str1[i-1] == str2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + str1[i-1]
                else:
                    dp[i][j] = min(dp[i-1][j] + str1[i-1], dp[i][j-1] + str2[j-1])
        
        return dp[m][n]
    

#### Java Implementation

    public class ShortestCommonSupersequenceTabulation {
    
        public static String scsTabulation(String str1, String str2) {
            int m = str1.length();
            int n = str2.length();
            String[][] dp = new String[m + 1][n + 1];
    
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0) {
                        dp[i][j] = str2.substring(0, j);
                    } else if (j == 0) {
                        dp[i][j] = str1.substring(0, i);
                    } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1] + str1.charAt(i - 1);
                    } else {
                        String left = dp[i - 1][j] + str1.charAt(i - 1);
                        String right = dp[i][j - 1] + str2.charAt(j - 1);
                        dp[i][j] = left.length() < right.length() ? left : right;
                    }
                }
            }
    
            return dp[m][n];
        }
    
        public static void main(String[] args) {
            String str1 = "abac";
            String str2 = "cab";
            System.out.println(scsTabulation(str1, str2));  // Output: "cabac"
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n)
*   **Space Complexity:** O(m\*n) (for the DP table)