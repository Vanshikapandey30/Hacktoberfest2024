Maximum Ribbon Cut Problem
==========================

Problem Definition
------------------

The **Maximum Ribbon Cut Problem** involves cutting a ribbon of a given length into as many pieces of given sizes as possible. The goal is to determine the maximum number of pieces that the ribbon can be cut into, provided that the sizes of the pieces are given as an array.

### Problem Statement

You are given a ribbon of length `N` and an array `ribbons[]` where each element represents a possible size for cutting the ribbon. Your task is to determine the maximum number of pieces you can obtain by cutting the ribbon into the given sizes.

### Example

For a ribbon of length `7` and possible cuts of size `{2, 3, 5}`:

*   Cutting it into pieces of `2 + 2 + 3` gives a total of `3` pieces.
*   If the ribbon length cannot be cut exactly using the given sizes, the answer will be `-1`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach explores all possible cuts recursively, trying to maximize the number of pieces.

#### Pseudocode

    function maxRibbonCutRecursive(ribbons, length):
        if length == 0:
            return 0
        if length < 0:
            return -1
        maxPieces = -1
        for each ribbon in ribbons:
            result = maxRibbonCutRecursive(ribbons, length - ribbon)
            if result != -1:
                maxPieces = max(maxPieces, result + 1)
        return maxPieces
    

#### Java Implementation

    public class MaximumRibbonCut {
    
        public static int maxRibbonCutRecursive(int[] ribbons, int length) {
            if (length == 0) {
                return 0;
            }
            if (length < 0) {
                return -1;
            }
            int maxPieces = -1;
            for (int ribbon : ribbons) {
                int result = maxRibbonCutRecursive(ribbons, length - ribbon);
                if (result != -1) {
                    maxPieces = Math.max(maxPieces, result + 1);
                }
            }
            return maxPieces;
        }
    
        public static void main(String[] args) {
            int[] ribbons = {2, 3, 5};
            int length = 7;
            System.out.println(maxRibbonCutRecursive(ribbons, length));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems to avoid redundant calculations, improving performance.

#### Pseudocode

    function maxRibbonCutMemo(ribbons, length, memo):
        if length == 0:
            return 0
        if length < 0:
            return -1
        if memo[length] != -1:
            return memo[length]
        maxPieces = -1
        for each ribbon in ribbons:
            result = maxRibbonCutMemo(ribbons, length - ribbon, memo)
            if result != -1:
                maxPieces = max(maxPieces, result + 1)
        memo[length] = maxPieces
        return memo[length]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class MaximumRibbonCut {
    
        public static int maxRibbonCutMemo(int[] ribbons, int length, int[] memo) {
            if (length == 0) {
                return 0;
            }
            if (length < 0) {
                return -1;
            }
            if (memo[length] != -1) {
                return memo[length];
            }
            int maxPieces = -1;
            for (int ribbon : ribbons) {
                int result = maxRibbonCutMemo(ribbons, length - ribbon, memo);
                if (result != -1) {
                    maxPieces = Math.max(maxPieces, result + 1);
                }
            }
            memo[length] = maxPieces;
            return memo[length];
        }
    
        public static void main(String[] args) {
            int[] ribbons = {2, 3, 5};
            int length = 7;
            int[] memo = new int[length + 1];
            Arrays.fill(memo, -1);
            System.out.println(maxRibbonCutMemo(ribbons, length, memo));  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table to iteratively compute the solution, ensuring optimal results with less time complexity.

#### Pseudocode

    function maxRibbonCutDP(ribbons, length):
        dp = array of size length + 1
        dp[0] = 0
        for each i from 1 to length:
            for each ribbon in ribbons:
                if i >= ribbon:
                    if dp[i - ribbon] != -1:
                        dp[i] = max(dp[i], dp[i - ribbon] + 1)
        return dp[length]
    

#### Java Implementation

    public class MaximumRibbonCut {
    
        public static int maxRibbonCutDP(int[] ribbons, int length) {
            int[] dp = new int[length + 1];
            Arrays.fill(dp, -1);
            dp[0] = 0;
    
            for (int i = 1; i <= length; i++) {
                for (int ribbon : ribbons) {
                    if (i >= ribbon && dp[i - ribbon] != -1) {
                        dp[i] = Math.max(dp[i], dp[i - ribbon] + 1);
                    }
                }
            }
            return dp[length];
        }
    
        public static void main(String[] args) {
            int[] ribbons = {2, 3, 5};
            int length = 7;
            System.out.println(maxRibbonCutDP(ribbons, length));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* m) time, O(n) space (for the memoization table), where `n` is the ribbon length and `m` is the number of ribbon cuts.
*   **Dynamic Programming:** O(n \* m) time, O(n) space (for the DP table)