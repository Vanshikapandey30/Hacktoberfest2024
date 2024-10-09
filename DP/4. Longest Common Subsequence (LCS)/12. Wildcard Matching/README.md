Wildcard Matching
=================

Problem Definition
------------------

The **Wildcard Matching** problem involves checking if a given string matches a pattern that may include wildcard characters. The characters '?' and '\*' can be used in the pattern, where '?' matches any single character and '\*' matches any sequence of characters (including an empty sequence).

### Example

*   Input: `s = "abcde"`, `p = "a?c*e"`
*   Output: `true`

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a recursive function to check character by character if the string matches the pattern, handling wildcards as necessary.

#### Pseudocode

    function isMatch(s, p, sIndex, pIndex):
        if pIndex == length of p:
            return sIndex == length of s
        if pIndex < length of p and p[pIndex] == '*':
            while sIndex < length of s and isMatch(s, p, sIndex, pIndex + 1) is false:
                sIndex += 1
            return isMatch(s, p, sIndex, pIndex + 1)
        if sIndex < length of s and (s[sIndex] == p[pIndex] or p[pIndex] == '?'):
            return isMatch(s, p, sIndex + 1, pIndex + 1)
        return false
    

#### Java Implementation

    public class WildcardMatchingRecursive {
    
        public static boolean isMatch(String s, String p, int sIndex, int pIndex) {
            if (pIndex == p.length()) {
                return sIndex == s.length();
            }
            if (pIndex < p.length() && p.charAt(pIndex) == '*') {
                while (sIndex < s.length() && !isMatch(s, p, sIndex, pIndex + 1)) {
                    sIndex++;
                }
                return isMatch(s, p, sIndex, pIndex + 1);
            }
            if (sIndex < s.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '?')) {
                return isMatch(s, p, sIndex + 1, pIndex + 1);
            }
            return false;
        }
    
        public static void main(String[] args) {
            String s = "abcde";
            String p = "a?c*e";
            boolean result = isMatch(s, p, 0, 0);
            System.out.println("Does the string match the pattern? " + result);  // Output: true
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (due to call stack)

### 2\. Memoization Approach

This approach optimizes the recursive solution using a memoization table to store results of previous computations, reducing the number of recursive calls.

#### Pseudocode

    function isMatch(s, p, sIndex, pIndex, memo):
        if (sIndex, pIndex) in memo:
            return memo[(sIndex, pIndex)]
        if pIndex == length of p:
            return sIndex == length of s
        if pIndex < length of p and p[pIndex] == '*':
            while sIndex < length of s and isMatch(s, p, sIndex, pIndex + 1, memo) is false:
                sIndex += 1
            memo[(sIndex, pIndex)] = isMatch(s, p, sIndex, pIndex + 1, memo)
            return memo[(sIndex, pIndex)]
        if sIndex < length of s and (s[sIndex] == p[pIndex] or p[pIndex] == '?'):
            memo[(sIndex, pIndex)] = isMatch(s, p, sIndex + 1, pIndex + 1, memo)
            return memo[(sIndex, pIndex)]
        memo[(sIndex, pIndex)] = false
        return false
    

#### Java Implementation

    import java.util.HashMap;
    
    public class WildcardMatchingMemoization {
    
        public static boolean isMatch(String s, String p, int sIndex, int pIndex, HashMap memo) {
            String key = sIndex + "-" + pIndex;
            if (memo.containsKey(key)) return memo.get(key);
            if (pIndex == p.length()) {
                return sIndex == s.length();
            }
            if (pIndex < p.length() && p.charAt(pIndex) == '*') {
                while (sIndex < s.length() && !isMatch(s, p, sIndex, pIndex + 1, memo)) {
                    sIndex++;
                }
                boolean result = isMatch(s, p, sIndex, pIndex + 1, memo);
                memo.put(key, result);
                return result;
            }
            if (sIndex < s.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '?')) {
                boolean result = isMatch(s, p, sIndex + 1, pIndex + 1, memo);
                memo.put(key, result);
                return result;
            }
            memo.put(key, false);
            return false;
        }
    
        public static void main(String[] args) {
            String s = "abcde";
            String p = "a?c*e";
            HashMap memo = new HashMap<>();
            boolean result = isMatch(s, p, 0, 0, memo);
            System.out.println("Does the string match the pattern? " + result);  // Output: true
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m) where n is the length of the string and m is the length of the pattern
*   **Space Complexity:** O(n \* m) (for memoization table)

### 3\. Tabulation Approach

This approach employs a bottom-up dynamic programming table to build up the solution based on smaller subproblems.

#### Pseudocode

    function isMatch(s, p):
        dp = 2D array of size (s.length + 1)(p.length + 1)
        dp[0][0] = true
        
        for j from 1 to length of p:
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-1]
        
        for i from 1 to length of s:
            for j from 1 to length of p:
                if p[j-1] == '*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                else if p[j-1] == '?' or s[i-1] == p[j-1]:
                    dp[i][j] = dp[i-1][j-1]
        
        return dp[s.length][p.length]
    

#### Java Implementation

    public class WildcardMatchingTabulation {
    
        public static boolean isMatch(String s, String p) {
            boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
            dp[0][0] = true;
    
            for (int j = 1; j <= p.length(); j++) {
                if (p.charAt(j - 1) == '*') {
                    dp[0][j] = dp[0][j - 1];
                }
            }
    
            for (int i = 1; i <= s.length(); i++) {
                for (int j = 1; j <= p.length(); j++) {
                    if (p.charAt(j - 1) == '*') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    } else if (p.charAt(j - 1) == '?' || s.charAt(i - 1) == p.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
    
            return dp[s.length()][p.length()];
        }
    
        public static void main(String[] args) {
            String s = "abcde";
            String p = "a?c*e";
            boolean result = isMatch(s, p);
            System.out.println("Does the string match the pattern? " + result);  // Output: true
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m) where n is the length of the string and m is the length of the pattern
*   **Space Complexity:** O(n \* m) (for the DP table)