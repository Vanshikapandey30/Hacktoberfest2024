Longest Palindromic Substring
=============================

Problem Definition
------------------

The **Longest Palindromic Substring** (LPS) is the longest contiguous subsequence of a given string that is a palindrome. Unlike the longest palindromic subsequence, this problem requires the palindrome to be a substring, meaning the characters must appear consecutively.

### Example

*   Input: `"babad"`
*   Output: `"bab"` or `"aba"`
*   Explanation: Both "bab" and "aba" are valid palindromic substrings of the given string.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach checks every substring of the input string to determine if it is a palindrome and tracks the longest one.

#### Pseudocode

    function lpsRecursive(s, start, end):
        if start == end:
            return s[start]
        if start > end:
            return ""
        if s[start] == s[end] and isPalindrome(s, start, end):
            return s[start:end+1]
        else:
            left = lpsRecursive(s, start+1, end)
            right = lpsRecursive(s, start, end-1)
            return the longer of left and right
    

#### Java Implementation

    public class LongestPalindromicSubstring {
    
        public static String lpsRecursive(String s, int start, int end) {
            if (start == end) return s.substring(start, start + 1);
            if (start > end) return "";
    
            if (s.charAt(start) == s.charAt(end) && isPalindrome(s, start, end)) {
                return s.substring(start, end + 1);
            } else {
                String left = lpsRecursive(s, start + 1, end);
                String right = lpsRecursive(s, start, end - 1);
                return left.length() > right.length() ? left : right;
            }
        }
    
        private static boolean isPalindrome(String s, int start, int end) {
            while (start < end) {
                if (s.charAt(start) != s.charAt(end)) return false;
                start++;
                end--;
            }
            return true;
        }
    
        public static void main(String[] args) {
            String s = "babad";
            System.out.println(lpsRecursive(s, 0, s.length() - 1));  // Output: "bab" or "aba"
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing intermediate results (substrings that are palindromes) to avoid recomputation.

#### Pseudocode

    function lpsMemo(s, start, end, memo):
        if start == end:
            return s[start]
        if start > end:
            return ""
        if memo[start][end] != -1:
            return memo[start][end]
        
        if s[start] == s[end] and isPalindrome(s, start, end):
            memo[start][end] = s[start:end+1]
        else:
            left = lpsMemo(s, start+1, end, memo)
            right = lpsMemo(s, start, end-1, memo)
            memo[start][end] = the longer of left and right
        return memo[start][end]
    

#### Java Implementation

    public class LongestPalindromicSubstring {
    
        public static String lpsMemo(String s, int start, int end, String[][] memo) {
            if (start == end) return s.substring(start, start + 1);
            if (start > end) return "";
            if (memo[start][end] != null) return memo[start][end];
    
            if (s.charAt(start) == s.charAt(end) && isPalindrome(s, start, end)) {
                memo[start][end] = s.substring(start, end + 1);
            } else {
                String left = lpsMemo(s, start + 1, end, memo);
                String right = lpsMemo(s, start, end - 1, memo);
                memo[start][end] = left.length() > right.length() ? left : right;
            }
            return memo[start][end];
        }
    
        private static boolean isPalindrome(String s, int start, int end) {
            while (start < end) {
                if (s.charAt(start) != s.charAt(end)) return false;
                start++;
                end--;
            }
            return true;
        }
    
        public static void main(String[] args) {
            String s = "babad";
            String[][] memo = new String[s.length()][s.length()];
            System.out.println(lpsMemo(s, 0, s.length() - 1, memo));  // Output: "bab" or "aba"
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table to store whether a substring is a palindrome. It iteratively finds the longest palindromic substring by filling the table based on substring lengths.

#### Pseudocode

    function lpsDP(s):
        n = length of s
        dp = array of size (n)(n)
        start = 0
        maxLen = 1
        
        for i from 0 to n-1:
            dp[i][i] = true
        
        for len from 2 to n:
            for i from 0 to n-len:
                j = i + len - 1
                if s[i] == s[j] and (len == 2 or dp[i+1][j-1]):
                    dp[i][j] = true
                    if len > maxLen:
                        maxLen = len
                        start = i
                        
        return s[start:start + maxLen]
    

#### Java Implementation

    public class LongestPalindromicSubstring {
    
        public static String lpsDP(String s) {
            int n = s.length();
            boolean[][] dp = new boolean[n][n];
            int start = 0;
            int maxLength = 1;
    
            for (int i = 0; i < n; i++) {
                dp[i][i] = true;
            }
    
            for (int len = 2; len <= n; len++) {
                for (int i = 0; i < n - len + 1; i++) {
                    int j = i + len - 1;
                    if (s.charAt(i) == s.charAt(j)) {
                        if (len == 2 || dp[i + 1][j - 1]) {
                            dp[i][j] = true;
                            if (len > maxLength) {
                                start = i;
                                maxLength = len;
                            }
                        }
                    }
                }
            }
    
            return s.substring(start, start + maxLength);
        }
    
        public static void main(String[] args) {
            String s = "babad";
            System.out.println(lpsDP(s));  // Output: "bab" or "aba"
        }
    }
    

Complexity Analysis
-------------------

*   **Time Complexity:**
    *   Recursive: O(2<sup>n</sup>), as it explores all substrings.
    *   Memoization: O(n<sup>2</sup>), due to storing and using results of subproblems.
    *   Dynamic Programming: O(n<sup>2</sup>), as it builds a table of substrings.
*   **Space Complexity:**
    *   Recursive: O(n), for recursion stack.
    *   Memoization: O(n<sup>2</sup>), for memoization table.
    *   Dynamic Programming: O(n<sup>2</sup>), for the dp table.