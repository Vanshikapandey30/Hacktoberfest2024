# Problem: Trapping Rain Water

## Description
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## Problem Statement
You are given an array height of integers where each element represents the height of a bar in an elevation map. Your task is to calculate how many units of water can be trapped between these bars after a rainfall.

## Example 1
![Example Illustration](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
**Input:** `height = [0,1,0,2,1,0,1,3,2,1,2,1]`

**Output:** `6`

## Approach: Two-Pointer Technique

### Explanation
1. We can optimize the solution with a two-pointer approach by maintaining `left` and `right` pointers at the start and end of the array, respectively.
2. We also maintain two variables, `leftMax` and `rightMax`, to store the maximum height from the left and right sides.
3. By comparing `leftMax` and `rightMax` at each step, we determine the potential water level and move the pointers toward the center, calculating trapped water based on the minimum of `leftMax` and `rightMax` at each position.

### Time Complexity
- **O(n)**: We traverse the array only once with two pointers.

### Space Complexity
- **O(1)**: Only a few extra variables are used, making this an in-place approach.
