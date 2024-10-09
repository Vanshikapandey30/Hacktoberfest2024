Subsequence Counting
====================

Problem Definition
------------------

The **Subsequence Counting** problem involves counting the number of distinct subsequences of a given string. A subsequence is a sequence derived from another sequence where some elements may be deleted without changing the order of the remaining elements.

Given a string, the goal is to find the count of distinct subsequences.

### Example

*   Input: `s = "aba"`
*   Output: `6` (distinct subsequences: "", "a", "b", "ab", "a", "aa", "ba", "aba")

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses a recursive function to generate all subsequences and count them. However, it may generate duplicate subsequences for characters that repeat.

#### Pseudocode

    function countSubsequences(s, index):
        if index == length of s:
            return 1
        count = countSubsequences(s, index + 1)
        if s[index] is not in subsequences counted so far:
            count += countSubsequences(s, index + 1)
        return count
    

#### Java Implementation

    import java.util.HashSet;
    
    public class SubsequenceCountingRecursive {
    
        public static int countSubsequences(String s, int index, HashSet subsequences) {
            if (index == s.length()) {
                return 1; // Count empty subsequence
            }
            
            // Count subsequences including the current character
            String currentChar = String.valueOf(s.charAt(index));
            int count = countSubsequences(s, index + 1, subsequences);
            
            // Count subsequences excluding the current character
            if (!subsequences.contains(currentChar)) {
                subsequences.add(currentChar);
                count += countSubsequences(s, index + 1, subsequences);
            }
            
            return count;
        }
    
        public static void main(String[] args) {
            String s = "aba";
            HashSet subsequences = new HashSet<>();
            int result = countSubsequences(s, 0, subsequences);
            System.out.println("Count of distinct subsequences: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for the recursion stack)

### 2\. Dynamic Programming Approach

This approach utilizes dynamic programming to count distinct subsequences while storing intermediate results to avoid duplicates.

#### Pseudocode

    function countDistinctSubsequences(s):
        dp = array of size (n + 1) initialized to 0
        dp[0] = 1 // Empty string has one subsequence
        
        for i from 1 to n:
            dp[i] = 2 * dp[i - 1] // Count including and excluding s[i-1]
            if s[i-1] exists in s[0:i-1]:
                dp[i] -= dp[last occurrence of s[i-1] in s[0:i-1]]
        
        return dp[n]
    

#### Java Implementation

    import java.util.HashMap;
    
    public class SubsequenceCountingDP {
    
        public static int countDistinctSubsequences(String s) {
            int n = s.length();
            int[] dp = new int[n + 1];
            dp[0] = 1; // Count of empty string
            
            HashMap lastOccurrence = new HashMap<>();
            
            for (int i = 1; i <= n; i++) {
                dp[i] = 2 * dp[i - 1]; // Count subsequences with current character
                
                if (lastOccurrence.containsKey(s.charAt(i - 1))) {
                    int lastIndex = lastOccurrence.get(s.charAt(i - 1));
                    dp[i] -= dp[lastIndex - 1]; // Remove duplicates
                }
                lastOccurrence.put(s.charAt(i - 1), i);
            }
            
            return dp[n] - 1; // Subtract the empty subsequence
        }
    
        public static void main(String[] args) {
            String s = "aba";
            int result = countDistinctSubsequences(s);
            System.out.println("Count of distinct subsequences: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(n) (for the dp array)

### 3\. Bitmask Approach

This approach uses a bitmask to represent all possible combinations of characters and counts the distinct subsequences.

#### Pseudocode

    function countDistinctSubsequences(s):
        n = length of s
        set subsequences = empty set
        
        for i from 0 to (1 << n) - 1:
            subsequence = ""
            for j from 0 to n - 1:
                if (i & (1 << j)) != 0:
                    subsequence += s[j]
            subsequences.add(subsequence)
        
        return size of subsequences - 1 // Subtract the empty subsequence
    

#### Java Implementation

    import java.util.HashSet;
    
    public class SubsequenceCountingBitmask {
    
        public static int countDistinctSubsequences(String s) {
            int n = s.length();
            HashSet subsequences = new HashSet<>();
            
            for (int i = 0; i < (1 << n); i++) {
                StringBuilder subsequence = new StringBuilder();
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        subsequence.append(s.charAt(j));
                    }
                }
                subsequences.add(subsequence.toString());
            }
            
            return subsequences.size() - 1; // Subtract the empty subsequence
        }
    
        public static void main(String[] args) {
            String s = "aba";
            int result = countDistinctSubsequences(s);
            System.out.println("Count of distinct subsequences: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n * 2<sup>n</sup>)
*   **Space Complexity:** O(2<sup>n</sup>) (for storing subsequences)