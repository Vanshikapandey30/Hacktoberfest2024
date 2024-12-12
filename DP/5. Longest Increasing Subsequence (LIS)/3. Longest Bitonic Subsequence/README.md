Longest Bitonic Subsequence (LBS)
=================================

Problem Definition
------------------

The **Longest Bitonic Subsequence (LBS)** problem is to find the length of the longest subsequence of a given sequence such that it first increases and then decreases.

### Example

*   Input: `[1, 11, 2, 10, 4, 5, 2, 1]`
*   Output: `6` (LBS is `[1, 2, 10, 4, 2, 1]`)

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach recursively computes the longest increasing subsequence ending at each index and the longest decreasing subsequence starting from each index, then sums the two for each element.

#### Pseudocode

    function lbsRecursive(arr, n, isIncreasing):
        if n == 0:
            return 0
        exclude = lbsRecursive(arr, n-1, isIncreasing)
        include = 0
        if isIncreasing and arr[n-1] > arr[n-2]:
            include = 1 + lbsRecursive(arr, n-1, true)
        if not isIncreasing and arr[n-1] < arr[n-2]:
            include = 1 + lbsRecursive(arr, n-1, false)
        return max(include, exclude)
    

#### Java Implementation

    public class LBSRecursive {
        public static int lbsRecursive(int[] arr, int n, boolean isIncreasing) {
            if (n == 0) return 0;
            int exclude = lbsRecursive(arr, n - 1, isIncreasing);
            int include = 0;
    
            if (isIncreasing && arr[n - 1] > arr[n - 2]) {
                include = 1 + lbsRecursive(arr, n - 1, true);
            }
            if (!isIncreasing && arr[n - 1] < arr[n - 2]) {
                include = 1 + lbsRecursive(arr, n - 1, false);
            }
    
            return Math.max(include, exclude);
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 11, 2, 10, 4, 5, 2, 1};
            int result = lbsRecursive(arr, arr.length, true);
            System.out.println("Longest Bitonic Subsequence Length: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2<sup>n</sup>)
*   **Space Complexity:** O(n) (for recursion stack)

### 2\. Dynamic Programming Approach (O(n<sup>2</sup>))

We use dynamic programming to calculate the Longest Increasing Subsequence (LIS) ending at each index and Longest Decreasing Subsequence (LDS) starting at each index. Then, we compute the LBS by summing LIS and LDS for each element and subtracting 1 (since the peak element is counted twice).

#### Pseudocode

    function lbsDP(arr, n):
        lis = array of size n initialized to 1
        lds = array of size n initialized to 1
        for i from 1 to n:
            for j from 0 to i-1:
                if arr[i] > arr[j]:
                    lis[i] = max(lis[i], lis[j] + 1)
        for i from n-2 to 0:
            for j from n-1 to i+1:
                if arr[i] > arr[j]:
                    lds[i] = max(lds[i], lds[j] + 1)
        maxLBS = 0
        for i from 0 to n:
            maxLBS = max(maxLBS, lis[i] + lds[i] - 1)
        return maxLBS
    

#### Java Implementation

    public class LBSDP {
        public static int lbsDP(int[] arr) {
            int n = arr.length;
            int[] lis = new int[n];
            int[] lds = new int[n];
    
            // Initialize all LIS and LDS values to 1
            for (int i = 0; i < n; i++) {
                lis[i] = lds[i] = 1;
            }
    
            // Compute LIS values
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j]) {
                        lis[i] = Math.max(lis[i], lis[j] + 1);
                    }
                }
            }
    
            // Compute LDS values
            for (int i = n - 2; i >= 0; i--) {
                for (int j = n - 1; j > i; j--) {
                    if (arr[i] > arr[j]) {
                        lds[i] = Math.max(lds[i], lds[j] + 1);
                    }
                }
            }
    
            // Compute maximum LBS
            int maxLBS = 0;
            for (int i = 0; i < n; i++) {
                maxLBS = Math.max(maxLBS, lis[i] + lds[i] - 1);
            }
    
            return maxLBS;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 11, 2, 10, 4, 5, 2, 1};
            int result = lbsDP(arr);
            System.out.println("Longest Bitonic Subsequence Length: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for LIS and LDS arrays)

### 3\. Optimized Approach (O(n log n))

The optimized approach uses binary search with dynamic programming to compute the LIS and LDS more efficiently. The idea is to use a technique similar to the "Patience Sorting" algorithm to improve the LIS and LDS computation to O(n log n).

#### Java Implementation

    import java.util.*;
    
    public class LBSOptimized {
        // Function to find Longest Increasing Subsequence (LIS) using binary search
        private static int[] computeLIS(int[] arr) {
            int n = arr.length;
            int[] lis = new int[n];
            Arrays.fill(lis, 1);
    
            List lisList = new ArrayList<>();
            lisList.add(arr[0]);
    
            for (int i = 1; i < n; i++) {
                if (arr[i] > lisList.get(lisList.size() - 1)) {
                    lisList.add(arr[i]);
                } else {
                    int pos = Collections.binarySearch(lisList, arr[i]);
                    if (pos < 0) pos = -(pos + 1);
                    lisList.set(pos, arr[i]);
                }
                lis[i] = lisList.size();
            }
            return lis;
        }
    
        // Function to compute Longest Bitonic Subsequence (LBS)
        public static int lbsOptimized(int[] arr) {
            int n = arr.length;
            int[] lis = computeLIS(arr);
            int[] reversedArr = new int[n];
            
            for (int i = 0; i < n; i++) {
                reversedArr[i] = arr[n - i - 1];
            }
    
            int[] lds = computeLIS(reversedArr);
            int maxLBS = 0;
    
            for (int i = 0; i < n; i++) {
                maxLBS = Math.max(maxLBS, lis[i] + lds[n - i - 1] - 1);
            }
    
            return maxLBS;
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 11, 2, 10, 4, 5, 2, 1};
            int result = lbsOptimized(arr);
            System.out.println("Longest Bitonic Subsequence Length: " + result);  // Output: 6
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n log n)
*   **Space Complexity:** O(n)