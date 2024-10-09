Decode Ways
===========

Problem Definition
------------------

The **Decode Ways** problem asks us to count the number of ways to decode a given string of digits, where each digit can be mapped to a letter according to the following mapping:

*   `'1' -> 'A'`
*   `'2' -> 'B'`
*   `'3' -> 'C'`
*   ...
*   `'26' -> 'Z'`

For example, given the string `"12"`, it can be decoded as either "AB" (1 2) or "L" (12), resulting in 2 possible decodings.

### Example

For the input `"226"`, the possible decodings are:

*   "BBF" (2 2 6)
*   "BZF" (2 26)
*   "VF" (22 6)

Thus, the total number of ways to decode `"226"` is `3`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach involves exploring each possible decoding option at every step. The base case checks if the string is empty or if it starts with a '0', which is invalid.

#### Pseudocode

    function numDecodingsRecursive(s):
        if s is empty:
            return 1
        if s starts with '0':
            return 0
        ways = numDecodingsRecursive(s[1:])  // Single digit
        if the first two characters form a valid letter (<= 26):
            ways += numDecodingsRecursive(s[2:])  // Double digit
        return ways
    

#### Java Implementation

    public class DecodeWays {
    
        public static int numDecodingsRecursive(String s) {
            if (s.isEmpty()) return 1;
            if (s.charAt(0) == '0') return 0;
            
            int ways = numDecodingsRecursive(s.substring(1));  // Single digit
            if (s.length() >= 2 && Integer.parseInt(s.substring(0, 2)) <= 26) {
                ways += numDecodingsRecursive(s.substring(2));  // Double digit
            }
            return ways;
        }
    
        public static void main(String[] args) {
            String s = "226";
            System.out.println(numDecodingsRecursive(s));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive solution by storing previously computed results to avoid redundant calculations.

#### Pseudocode

    function numDecodingsMemo(s, memo):
        if s is empty:
            return 1
        if s starts with '0':
            return 0
        if memo for s is not -1:
            return memo for s
        ways = numDecodingsMemo(s[1:], memo)  // Single digit
        if the first two characters form a valid letter (<= 26):
            ways += numDecodingsMemo(s[2:], memo)  // Double digit
        memo for s = ways
        return ways
    

#### Java Implementation

    import java.util.HashMap;
    
    public class DecodeWays {
    
        public static int numDecodingsMemo(String s, HashMap memo) {
            if (s.isEmpty()) return 1;
            if (s.charAt(0) == '0') return 0;
            if (memo.containsKey(s)) return memo.get(s);
            
            int ways = numDecodingsMemo(s.substring(1), memo);  // Single digit
            if (s.length() >= 2 && Integer.parseInt(s.substring(0, 2)) <= 26) {
                ways += numDecodingsMemo(s.substring(2), memo);  // Double digit
            }
            
            memo.put(s, ways);
            return ways;
        }
    
        public static void main(String[] args) {
            String s = "226";
            HashMap memo = new HashMap<>();
            System.out.println(numDecodingsMemo(s, memo));  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table iteratively to compute the number of ways to decode the string.

#### Pseudocode

    function numDecodingsDP(s):
        if s starts with '0':
            return 0
        dp = array of size s.length + 1
        dp[0] = 1
        dp[1] = 1
        for i from 2 to length of s:
            if s[i-1] is not '0':
                dp[i] += dp[i-1]
            if s[i-2] is valid (<= 26):
                dp[i] += dp[i-2]
        return dp[length of s]
    

#### Java Implementation

    public class DecodeWays {
    
        public static int numDecodingsDP(String s) {
            if (s.charAt(0) == '0') return 0;
            int[] dp = new int[s.length() + 1];
            dp[0] = 1;
            dp[1] = 1;
    
            for (int i = 2; i <= s.length(); i++) {
                if (s.charAt(i - 1) != '0') {
                    dp[i] += dp[i - 1];
                }
                if (i >= 2 && Integer.parseInt(s.substring(i - 2, i)) <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
            return dp[s.length()];
        }
    
        public static void main(String[] args) {
            String s = "226";
            System.out.println(numDecodingsDP(s));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n) time, O(n) space (for memoization map).
*   **Dynamic Programming Approach:** O(n) time, O(n) space (for DP table).