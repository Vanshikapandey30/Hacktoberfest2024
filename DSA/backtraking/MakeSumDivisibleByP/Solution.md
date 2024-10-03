# Problem: Remove Smallest Subarray to Make Sum Divisible by `p`

## Problem Description
Given an array of integers `nums` and an integer `p`, the task is to remove the smallest subarray such that the sum of the remaining elements is divisible by `p`. If the sum of the entire array is divisible by `p`, no subarray needs to be removed. Otherwise, we need to find the smallest subarray that, when removed, reduces the sum to something divisible by `p`.

## Approach

### 1. **Calculate Total Sum Modulo `p`**
- Compute the sum of all elements in `nums`.
- Find the remainder `rem` when this sum is divided by `p` (`rem = totalSum % p`).
- If `rem == 0`, return `0` since no subarray needs to be removed.

### 2. **Track Prefix Sums**
- Use a hash map (`mp`) to store the prefix sums modulo `p` and the index at which they were seen.
- As we iterate through the array, compute the prefix sum modulo `p` and check if there exists an earlier prefix sum that would allow us to remove a subarray to make the remaining sum divisible by `p`.

### 3. **Use Modulo Arithmetic**
- The goal is to find a subarray whose removal results in the remainder `rem` being canceled out.
- We use modulo arithmetic to find the difference between the current prefix sum and the target remainder `rem`.

### 4. **Handle Negative Modulo**
- C++'s modulo operator can return negative values, so we adjust the result to always be positive using the formula: `(pS + p - rem) % p`.

### 5. **Return the Result**
- Keep track of the smallest subarray length and return it if found.
- If no such subarray exists, return `-1`.

## Time Complexity
- **O(n)**: We iterate through the array once, and hash map lookups and updates are performed in constant time.

## Space Complexity
- **O(n)**: We use a hash map to store prefix sums, which takes linear space in the worst case.

## Code

```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size();
        long long tt = accumulate(nums.begin(), nums.end(), 0LL);
        
        if (tt < p) return -1;

        long long rem = tt % p;

        if (rem == 0) return 0;

        unordered_map<long, long> mp;
        mp[0] = -1; // Initialize with prefix sum 0 at index -1

        long long pS = 0;
        long long mn = n;

        for (long long i = 0; i < n; i++) {
            // Update prefix sum modulo p
            pS = (pS + nums[i]) % p;

            // Target subarray to remove
            long long target = (pS + p - rem) % p;

            // If found, update the minimum subarray length
            if (mp.find(target) != mp.end()) {
                mn = min(mn, i - mp[target]);
            }

            // Store the current prefix sum modulo p with index
            mp[pS] = i;
        }

        // Return -1 if no valid subarray is found
        return mn == n ? -1 : mn;
    }
};
```

## Example

### Example 1:
**Input**:  
`nums = [4, 4, 2]`  
`p = 7`

**Output**:  
`-1`

**Explanation**:  
Total sum = 4 + 4 + 2 = 10, and 10 % 7 = 3. We need to remove a subarray that makes the sum divisible by 7. Using the prefix sum approach, the solution finds that no valid subarray can be removed without removing the entire array. So, the output is `-1`.

---

### Example 2:
**Input**:  
`nums = [3, 1, 4, 2]`  
`p = 6`

**Output**:  
`1`

**Explanation**:  
Total sum = 10, and 10 % 6 = 4. The solution finds that the smallest subarray to remove to make the sum divisible by 6 has length 1.

---

## Summary

This approach leverages the prefix sum and modulo arithmetic to efficiently solve the problem by keeping track of remainders and identifying the smallest subarray that can be removed to make the sum of the remaining elements divisible by `p`.