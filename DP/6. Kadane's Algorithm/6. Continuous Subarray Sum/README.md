Continuous Subarray Sum
=======================

Problem Definition
------------------

The **Continuous Subarray Sum** problem involves determining if a contiguous subarray of a given size sums up to a multiple of a specified integer.

### Example

*   Input: `nums = [23, 2, 4, 6, 7], k = 6`
*   Output: `true` (The subarray \[2, 4\] sums up to 6)

Solution Approaches
-------------------

### 1\. Brute Force Approach (O(n<sup>2</sup>))

This approach iterates over all possible subarrays and checks if their sum is a multiple of `k`.

#### Pseudocode

    function checkSubarraySum(nums, k):
            for i from 0 to length(nums) - 1:
                for j from i + 1 to length(nums):
                    sum = 0
                    for l from i to j - 1:
                        sum += nums[l]
                    if k != 0 and sum % k == 0:
                        return true
                    else if k == 0 and sum == 0:
                        return true
            return false
        

#### Java Implementation

    public class ContinuousSubarraySumBruteForce {
            public static boolean checkSubarraySum(int[] nums, int k) {
                for (int i = 0; i < nums.length; i++) {
                    int sum = 0;
                    for (int j = i + 1; j < nums.length; j++) {
                        sum += nums[j];
                        if (k != 0 && sum % k == 0) {
                            return true;
                        } else if (k == 0 && sum == 0) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        

### Time and Space Complexity (Brute Force)

*   **Time Complexity:** O(n<sup>2</sup>) - Due to nested loops iterating through all subarrays.
*   **Space Complexity:** O(1) - Only a few variables are used for computation.

### 2\. HashMap Approach (O(n))

This approach uses a HashMap to store the cumulative sum modulo `k`. If the same modulo value appears again, it means there is a subarray whose sum is a multiple of `k`.

#### Pseudocode

    function checkSubarraySum(nums, k):
            map = empty HashMap
            map[0] = -1
            sum = 0
            for i from 0 to length(nums):
                sum += nums[i]
                if k != 0:
                    sum = sum % k
                if sum in map:
                    if i - map[sum] > 1:
                        return true
                else:
                    map[sum] = i
            return false
        

#### Java Implementation

    import java.util.HashMap;
    
        public class ContinuousSubarraySumHashMap {
            public static boolean checkSubarraySum(int[] nums, int k) {
                HashMap map = new HashMap<>();
                map.put(0, -1);
                int sum = 0;
                
                for (int i = 0; i < nums.length; i++) {
                    sum += nums[i];
                    if (k != 0) {
                        sum = sum % k;
                    }
                    if (map.containsKey(sum)) {
                        if (i - map.get(sum) > 1) {
                            return true;
                        }
                    } else {
                        map.put(sum, i);
                    }
                }
                return false;
            }
        }
        

### Time and Space Complexity (HashMap Approach)

*   **Time Complexity:** O(n) - One pass through the array and constant time operations for HashMap.
*   **Space Complexity:** O(n) - Space used by the HashMap to store cumulative sums.

### 3\. Prefix Sum Approach (O(n))

This approach uses the concept of prefix sums to track the cumulative sum of the array elements. It checks if any two prefix sums are equal modulo `k`.

#### Pseudocode

    function checkSubarraySum(nums, k):
            if length(nums) < 2:
                return false
            prefixSum = 0
            set = empty HashSet
            set.add(0)
            for i from 0 to length(nums):
                prefixSum += nums[i]
                if k != 0:
                    prefixSum = prefixSum % k
                if set.contains(prefixSum):
                    return true
                set.add(prefixSum)
            return false
        

#### Java Implementation

    import java.util.HashSet;
    
        public class ContinuousSubarraySumPrefixSum {
            public static boolean checkSubarraySum(int[] nums, int k) {
                if (nums.length < 2) return false;
                HashSet set = new HashSet<>();
                int prefixSum = 0;
                set.add(0);
                
                for (int i = 0; i < nums.length; i++) {
                    prefixSum += nums[i];
                    if (k != 0) {
                        prefixSum = prefixSum % k;
                    }
                    if (set.contains(prefixSum)) {
                        return true;
                    }
                    set.add(prefixSum);
                }
                return false;
            }
        }
        

### Time and Space Complexity (Prefix Sum Approach)

*   **Time Complexity:** O(n) - One pass through the array and constant time operations for HashSet.
*   **Space Complexity:** O(n) - Space used by the HashSet to store prefix sums.