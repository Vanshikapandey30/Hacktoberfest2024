#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> tails; // This will store the smallest tail of all increasing subsequences
    for (int num : nums) {
        // Use binary search to find the insertion point
        auto it = std::lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num); // Extend the size of tails
        } else {
            *it = num; // Replace the found position with num
        }
    }
    return tails.size(); // The size of tails is the length of the LIS
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int length = lengthOfLIS(nums);
    std::cout << "Length of Longest Increasing Subsequence: " << length << std::endl;
    return 0;
}
