Number of Longest Increasing Subsequences (LIS)
===============================================

Problem Definition
------------------

The task is to find the number of distinct Longest Increasing Subsequences (LIS) in a given array.

### Example

*   Input: `[1, 3, 5, 4, 7]`
*   Output: `2` (There are two LIS: `[1, 3, 5, 7]` and `[1, 3, 4, 7]`)

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach uses recursion to find the longest increasing subsequences. However, due to overlapping subproblems, this is highly inefficient.

#### Pseudocode

    function countLISRecursive(arr, n):
        if n == 1:
            return 1
        count = 1
        for i from 0 to n-2:
            if arr[i] < arr[n-1]:
                count += countLISRecursive(arr, i+1)
        return count
    

#### Java Implementation

    public class LISRecursive {
        public static int countLISRecursive(int[] arr, int n) {
            if (n == 1) return 1;
    
            int count = 1;
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] < arr[n - 1]) {
                    count += countLISRecursive(arr, i + 1);
                }
            }
    
            return count;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 3, 5, 4, 7};
            int result = countLISRecursive(arr, arr.length);
            System.out.println("Number of LIS: " + result);  // Output: (inefficient)
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for recursion stack)

### 2\. Dynamic Programming Approach (O(n<sup>2</sup>))

This approach uses dynamic programming to track the length of the LIS ending at each index and the count of LIS for that length. We iterate through the array and, for each element, compute how many LIS can end at that element.

#### Pseudocode

    function countLISDP(arr, n):
        lengths = array of size n initialized to 1
        counts = array of size n initialized to 1
        maxLen = 0
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] > arr[j]:
                    if lengths[j] + 1 > lengths[i]:
                        lengths[i] = lengths[j] + 1
                        counts[i] = counts[j]
                    elif lengths[j] + 1 == lengths[i]:
                        counts[i] += counts[j]
            maxLen = max(maxLen, lengths[i])
        result = 0
        for i from 0 to n:
            if lengths[i] == maxLen:
                result += counts[i]
        return result
    

#### Java Implementation

    public class LISDP {
        public static int countLISDP(int[] arr) {
            int n = arr.length;
            if (n == 0) return 0;
    
            int[] lengths = new int[n];  // lengths[i] will store the length of LIS ending at index i
            int[] counts = new int[n];   // counts[i] will store the number of LIS ending at index i
            Arrays.fill(lengths, 1);
            Arrays.fill(counts, 1);
    
            int maxLength = 0;
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        if (lengths[j] + 1 > lengths[i]) {
                            lengths[i] = lengths[j] + 1;
                            counts[i] = counts[j];
                        } else if (lengths[j] + 1 == lengths[i]) {
                            counts[i] += counts[j];
                        }
                    }
                }
                maxLength = Math.max(maxLength, lengths[i]);
            }
    
            int result = 0;
            for (int i = 0; i < n; i++) {
                if (lengths[i] == maxLength) {
                    result += counts[i];
                }
            }
    
            return result;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 3, 5, 4, 7};
            int result = countLISDP(arr);
            System.out.println("Number of LIS: " + result);  // Output: 2
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for lengths and counts arrays)

### 3\. Optimized Approach (O(n log n))

An optimized solution uses patience sorting and binary search to compute the LIS lengths more efficiently, similar to the approach used in finding the length of LIS but adapted to count all LIS.

#### Java Implementation

    import java.util.*;
    
    public class LISOptimized {
        public static int countLISOptimized(int[] arr) {
            if (arr.length == 0) return 0;
    
            int n = arr.length;
            List subsequences = new ArrayList<>();
            subsequences.add(new int[]{arr[0], 1});
    
            for (int i = 1; i < n; i++) {
                int num = arr[i];
                int left = 0, right = subsequences.size();
    
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (subsequences.get(mid)[0] >= num) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
    
                if (left == subsequences.size()) {
                    subsequences.add(new int[]{num, 1});
                } else {
                    subsequences.set(left, new int[]{num, subsequences.get(left)[1] + 1});
                }
            }
    
            int maxLIS = subsequences.size();
            int count = 0;
            for (int[] subseq : subsequences) {
                if (subseq[0] == maxLIS) count += subseq[1];
            }
    
            return count;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 3, 5, 4, 7};
            int result = countLISOptimized(arr);
            System.out.println("Number of LIS: " + result);  // Output: Optimized approach (binary search)
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n log n)
*   **Space Complexity:** O(n) (for subsequences)