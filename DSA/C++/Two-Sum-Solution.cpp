#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map;  // Map to store values and their indices
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        // Check if complement exists in map
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        // Store the index of the current number
        num_map[nums[i]] = i;
    }
    return {};  // Return empty vector if no solution is found (shouldn't happen here)
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
