Russian Doll Envelopes
======================

Problem Definition
------------------

The Russian Doll Envelopes problem involves finding the maximum number of envelopes that can be Russian dolled (nested) within each other. Each envelope can fit into another envelope if and only if both its width and height are strictly smaller than the other envelope's width and height.

### Example

*   Input: `[[5,4],[6,4],[6,7],[2,3]]`
*   Output: `3` (The envelopes `[2,3] -> [5,4] -> [6,7]` can be nested)

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach (O(n2))

This approach sorts the envelopes and uses dynamic programming to find the longest increasing subsequence based on height.

#### Pseudocode

    function maxEnvelopesDP(envelopes):
        sort envelopes by width and height
        n = length of envelopes
        dp = array of size n initialized to 1
        for i from 1 to n:
            for j from 0 to i-1:
                if envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
    

#### Java Implementation

    import java.util.Arrays;
    
    public class RussianDollEnvelopesDP {
        public static int maxEnvelopes(int[][] envelopes) {
            Arrays.sort(envelopes, (a, b) -> {
                if (a[0] != b[0]) return a[0] - b[0];
                return a[1] - b[1];
            });
    
            int n = envelopes.length;
            int[] dp = new int[n];
            Arrays.fill(dp, 1);
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (envelopes[i][1] > envelopes[j][1]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                    }
                }
            }
    
            int maxEnvelopes = 0;
            for (int count : dp) {
                maxEnvelopes = Math.max(maxEnvelopes, count);
            }
            return maxEnvelopes;
        }
    
        public static void main(String[] args) {
            int[][] envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
            int result = maxEnvelopes(envelopes);
            System.out.println("Maximum number of envelopes: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for dp array)

### 2\. Binary Search with Dynamic Programming (O(n log n))

This approach sorts the envelopes and uses binary search to maintain an array representing the increasing sequence of heights, allowing for a more efficient solution.

#### Pseudocode

    function maxEnvelopesBinarySearch(envelopes):
        sort envelopes by width and height
        heights = empty list
        for each envelope in envelopes:
            height = envelope[1]
            position = binary search position in heights for height
            if position equals size of heights:
                append height to heights
            else:
                replace heights[position] with height
        return size of heights
    

#### Java Implementation

    import java.util.*;
    
    public class RussianDollEnvelopesBinarySearch {
        public static int maxEnvelopes(int[][] envelopes) {
            Arrays.sort(envelopes, (a, b) -> {
                if (a[0] != b[0]) return a[0] - b[0];
                return a[1] - b[1];
            });
    
            List heights = new ArrayList<>();
            for (int[] envelope : envelopes) {
                int height = envelope[1];
                int position = Collections.binarySearch(heights, height);
                if (position < 0) {
                    position = -(position + 1);
                }
                if (position == heights.size()) {
                    heights.add(height);
                } else {
                    heights.set(position, height);
                }
            }
    
            return heights.size();
        }
    
        public static void main(String[] args) {
            int[][] envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
            int result = maxEnvelopes(envelopes);
            System.out.println("Maximum number of envelopes: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n log n)
*   **Space Complexity:** O(n) (for heights list)

### 3\. Optimized Approach (O(n log n))

This approach combines the sorting and binary search techniques effectively, leading to optimal performance for this problem.

#### Java Implementation

    import java.util.*;
    
    public class RussianDollEnvelopesOptimized {
        public static int maxEnvelopes(int[][] envelopes) {
            Arrays.sort(envelopes, (a, b) -> {
                if (a[0] != b[0]) return a[0] - b[0];
                return b[1] - a[1]; // Sort by height in descending order
            });
    
            List heights = new ArrayList<>();
            for (int[] envelope : envelopes) {
                int height = envelope[1];
                int position = Collections.binarySearch(heights, height);
                if (position < 0) {
                    position = -(position + 1);
                }
                if (position == heights.size()) {
                    heights.add(height);
                } else {
                    heights.set(position, height);
                }
            }
    
            return heights.size();
        }
    
        public static void main(String[] args) {
            int[][] envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
            int result = maxEnvelopes(envelopes);
            System.out.println("Maximum number of envelopes: " + result);  // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n log n)
*   **Space Complexity:** O(n) (for heights list)