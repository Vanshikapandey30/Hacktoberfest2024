The first question mentioned here that is 
1) Given an array of integers, find the length of the longest subsequence that is strictly increasing.
 For example, in the sequence [10, 22, 9, 33, 21, 50, 41, 60, 80], the longest increasing subsequence is [10, 22, 33, 50, 60, 80], and its length is 6.

    the porblem can be solved using two approaches:
     1)using binary search
        Maintain an array tails where tails[i] holds the smallest tail value for all increasing subsequences of length i+1.
        Use binary search to find the position to replace or extend the tails array.

     2)using dynamic programming
        Create a DP array dp where dp[i] will hold the length of the longest increasing subsequence ending at index i.
        Initialize all entries of dp as 1 (every element is an increasing subsequence of length 1).
        For each element, check all previous elements to see if you can extend the subsequence. 