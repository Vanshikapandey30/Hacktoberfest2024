Regular Expression Matching
===========================

Problem Definition
------------------

The **Regular Expression Matching** problem involves checking if a given string matches a pattern that may contain special characters. The special characters include:

*   `.`: Matches any single character.
*   `*`: Matches zero or more of the preceding element.

The task is to implement a function that takes a string and a pattern and returns whether the string matches the pattern.

### Example

*   Input: `s = "aab"`, `p = "c*a*b"`
*   Output: `true`

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a recursive function to check character by character if the string matches the pattern, handling special characters as necessary.

#### Pseudocode

    function isMatch(s, p, sIndex, pIndex):
        if pIndex == length of p:
            return sIndex == length of s
        if pIndex + 1 < length of p and p[pIndex + 1] == '*':
            if isMatch(s, p, sIndex, pIndex + 2):
                return true
            while sIndex < length of s and (s[sIndex] == p[pIndex] or p[pIndex] == '.'):
                if isMatch(s, p, sIndex + 1, pIndex):
                    return true
                sIndex += 1
        if sIndex < length of s and (s[sIndex] == p[pIndex] or p[pIndex] == '.'):
            return isMatch(s, p, sIndex + 1, pIndex + 1)
        return false
    

#### Java Implementation

    public class RegularExpressionMatchingRecursive {
    
        public static boolean isMatch(String s, String p, int sIndex, int pIndex) {
            if (pIndex == p.length()) {
                return sIndex == s.length();
            }
            if (pIndex + 1 < p.length() && p.charAt(pIndex + 1) == '*') {
                if (isMatch(s, p, sIndex, pIndex + 2)) {
                    return true;
                }
                while (sIndex < s.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '.')) {
                    if (isMatch(s, p, sIndex + 1, pIndex)) {
                        return true;
                    }
                    sIndex++;
                }
            }
            if (sIndex < s.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '.')) {
                return isMatch(s, p, sIndex + 1, pIndex + 1);
            }
            return false;
        }
    
        public static void main(String[] args) {
            String s = "aab";
            String p = "c*a*b";
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
        if pIndex + 1 < length of p and p[pIndex + 1] == '*':
            if isMatch(s, p, sIndex, pIndex + 2, memo):
                memo[(sIndex, pIndex)] = true
                return true
            while sIndex < length of s and (s[sIndex] == p[pIndex] or p[pIndex] == '.'):
                if isMatch(s, p, sIndex + 1, pIndex, memo):
                    memo[(sIndex, pIndex)] = true
                    return true
                sIndex += 1
        if sIndex < length of s and (s[sIndex] == p[pIndex] or p[pIndex] == '.'):
            memo[(sIndex, pIndex)] = isMatch(s, p, sIndex + 1, pIndex + 1, memo)
            return memo[(sIndex, pIndex)]
        memo[(sIndex, pIndex)] = false
        return false
    

#### Java Implementation

    import java.util.HashMap;
    
    public class RegularExpressionMatchingMemoization {
    
        public static boolean isMatch(String s, String p, int sIndex, int pIndex, HashMap memo) {
            String key = sIndex + "-" + pIndex;
            if (memo.containsKey(key)) return memo.get(key);
            if (pIndex == p.length()) {
                return sIndex == s.length();
            }
            if (pIndex + 1 < p.length() && p.charAt(pIndex + 1) == '*') {
                if (isMatch(s, p, sIndex, pIndex + 2, memo)) {
                    memo.put(key, true);
                    return true;
                }
                while (sIndex < s.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '.')) {
                    if (isMatch(s, p, sIndex + 1, pIndex, memo)) {
                        memo.put(key, true);
                        return true;
                    }
                    sIndex++;
                }
            }
            if (sIndex < s.length() && (s.charAt(sIndex) == p.charAt(pIndex) || p.charAt(pIndex) == '.')) {
                memo.put(key, isMatch(s, p, sIndex + 1, pIndex + 1, memo));
                return memo.get(key);
            }
            memo.put(key, false);
            return false;
        }
    
        public static void main(String[] args) {
            String s = "aab";
            String p = "c*a*b";
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
                dp[0][j] = dp[0][j-2]
        
        for i from 1 to length of s:
            for j from 1 to length of p:
                if p[j-1] == '*':
                    dp[i][j] = dp[i][j-2] or (dp[i-1][j] and (s[i-1] == p[j-2] or p[j-2] == '.'))
                else if p[j-1] == '.' or s[i-1] == p[j-1]:
                    dp[i][j] = dp[i-1][j-1]
        
        return dp[s.length][p.length]
    

#### Java Implementation

    public class RegularExpressionMatchingTabulation {
    
        public static boolean isMatch(String s, String p) {
            boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
            dp[0][0] = true;
            
            for (int j = 1; j <= p.length(); j++) {
                if (p.charAt(j - 1) == '*') {
                    dp[0][j] = dp[0][j - 2];
                }
            }
            
            for (int i = 1; i <= s.length(); i++) {
                for (int j = 1; j <= p.length(); j++) {
                    if (p.charAt(j - 1) == '*') {
                        dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s.charAt(i - 1) == p.charAt(j - 2) || p.charAt(j - 2) == '.'));
                    } else if (p.charAt(j - 1) == '.' || s.charAt(i - 1) == p.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
            
            return dp[s.length()][p.length()];
        }
    
        public static void main(String[] args) {
            String s = "aab";
            String p = "c*a*b";
            boolean result = isMatch(s, p);
            System.out.println("Does the string match the pattern? " + result);  // Output: true
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m) where n is the length of the string and m is the length of the pattern
*   **Space Complexity:** O(n \* m) (for the DP table)