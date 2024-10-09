Scrambled String Problem
========================

Problem Definition
------------------

The **Scrambled String Problem** involves determining whether one string is a scrambled version of another.

### Example

*   Input: `s1 = "great"`, `s2 = "rgeat"`
*   Output: `true`

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach checks if the two strings are scrambled by recursively dividing them into halves.

#### Pseudocode

    function isScramble(s1, s2):
            if s1 equals s2:
                return true
            if sorted(s1) != sorted(s2):
                return false
            n = length(s1)
            for i from 1 to n - 1:
                if (isScramble(s1[0:i], s2[0:i]) and isScramble(s1[i:n], s2[i:n]) or
                    isScramble(s1[0:i], s2[n-i:n]) and isScramble(s1[i:n], s2[0:n-i]):
                    return true
            return false
        

#### Java Implementation

    public class ScrambledString {
            public static boolean isScramble(String s1, String s2) {
                if (s1.equals(s2)) return true;
                if (s1.length() != s2.length()) return false;
                char[] arr1 = s1.toCharArray();
                char[] arr2 = s2.toCharArray();
                Arrays.sort(arr1);
                Arrays.sort(arr2);
                if (!Arrays.equals(arr1, arr2)) return false;
    
                int n = s1.length();
                for (int i = 1; i < n; i++) {
                    if ((isScramble(s1.substring(0, i), s2.substring(0, i)) &&
                         isScramble(s1.substring(i), s2.substring(i))) ||
                        (isScramble(s1.substring(0, i), s2.substring(n - i)) &&
                         isScramble(s1.substring(i), s2.substring(0, n - i)))) {
                        return true;
                    }
                }
                return false;
            }
        }
        

### Time and Space Complexity (Recursive Approach)

*   **Time Complexity:** O(n^4) - Due to the exponential nature of recursive calls and sorting strings.
*   **Space Complexity:** O(n) - For recursive stack space.