#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    std::vector<int> dp(n, 1); // Initialize DP array with 1

    // Fill the DP array
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    // The length of the longest increasing subsequence is the max in dp array
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int length = lengthOfLIS(nums);
    std::cout << "Length of Longest Increasing Subsequence: " << length << std::endl;
    return 0;
}
