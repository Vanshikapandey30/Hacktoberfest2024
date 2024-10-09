Longest Chain of Pairs
======================

Problem Definition
------------------

The **Longest Chain of Pairs** problem is to find the maximum length of a chain of pairs such that the second element of one pair is less than the first element of the next pair.

### Example

*   Input: `[(5, 24), (15, 25), (27, 40), (50, 60)]`
*   Output: `3` (The longest chain is `[(5, 24), (27, 40), (50, 60)]`)

Solution Approaches
-------------------

### 1\. Brute Force Approach (Exponential Time)

This approach checks all possible pairs recursively to find the longest chain.

#### Pseudocode

    function longestChainBruteForce(pairs, n, prevIndex):
            if n == 0:
                return 0
            exclude = longestChainBruteForce(pairs, n-1, prevIndex)
            include = 0
            if prevIndex == -1 or pairs[n-1][0] > pairs[prevIndex][1]:
                include = 1 + longestChainBruteForce(pairs, n-1, n-1)
            return max(include, exclude)
        

#### Java Implementation

    public class LongestChainBruteForce {
            public static int longestChainBruteForce(int[][] pairs, int n, int prevIndex) {
                if (n == 0) return 0;
                int exclude = longestChainBruteForce(pairs, n - 1, prevIndex);
                int include = 0;
                if (prevIndex == -1 || pairs[n - 1][0] > pairs[prevIndex][1]) {
                    include = 1 + longestChainBruteForce(pairs, n - 1, n - 1);
                }
                return Math.max(include, exclude);
            }
    
            public static void main(String[] args) {
                int[][] pairs = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
                int result = longestChainBruteForce(pairs, pairs.length, -1);
                System.out.println("Length of Longest Chain: " + result);  // Output: 3
            }
        }

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for the recursion stack)

### 2\. Dynamic Programming Approach (O(n<sup>2</sup>))

This approach uses dynamic programming to store the maximum length of the chain ending at each pair.

#### Pseudocode

    function longestChainDP(pairs, n):
            dp = array of size n initialized to 1
            for i from 1 to n:
                for j from 0 to i-1:
                    if pairs[i][0] > pairs[j][1]:
                        dp[i] = max(dp[i], dp[j] + 1)
            return max(dp)
        

#### Java Implementation

    public class LongestChainDP {
            public static int longestChainDP(int[][] pairs) {
                int n = pairs.length;
                int[] dp = new int[n];
                for (int i = 0; i < n; i++) dp[i] = 1;
    
                for (int i = 1; i < n; i++) {
                    for (int j = 0; j < i; j++) {
                        if (pairs[i][0] > pairs[j][1]) {
                            dp[i] = Math.max(dp[i], dp[j] + 1);
                        }
                    }
                }
    
                int maxLength = 0;
                for (int i = 0; i < n; i++) {
                    maxLength = Math.max(maxLength, dp[i]);
                }
    
                return maxLength;
            }
    
            public static void main(String[] args) {
                int[][] pairs = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
                int result = longestChainDP(pairs);
                System.out.println("Length of Longest Chain: " + result);  // Output: 3
            }
        }

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for the dp array)

### 3\. Greedy Approach (O(n log n))

This approach first sorts the pairs based on the second element and then uses a greedy method to find the longest chain.

#### Pseudocode

    function longestChainGreedy(pairs):
            sort pairs by the second element
            end = -infinity
            count = 0
            for each pair in pairs:
                if pair[0] > end:
                    end = pair[1]
                    count += 1
            return count
        

#### Java Implementation

    import java.util.Arrays;
    import java.util.Comparator;
    
    public class LongestChainGreedy {
        public static int longestChainGreedy(int[][] pairs) {
            Arrays.sort(pairs, Comparator.comparingInt(a -> a[1]));
            int count = 0;
            int end = Integer.MIN_VALUE;
    
            for (int[] pair : pairs) {
                if (pair[0] > end) {
                    end = pair[1];
                    count++;
                }
            }
            return count;
        }
    
        public static void main(String[] args) {
            int[][] pairs = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
            int result = longestChainGreedy(pairs);
            System.out.println("Length of Longest Chain: " + result);  // Output: 3
        }
    }
        

#### Time and Space Complexity

*   **Time Complexity:** O(n log n) (for sorting)
*   **Space Complexity:** O(1) (if sorting in-place)