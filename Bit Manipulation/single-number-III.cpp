#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorr ^= nums[i];
        }
        int rightMostBit = xorr & -xorr;  // Get the rightmost set bit
        int b1 = 0, b2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (rightMostBit & nums[i]) {
                b1 ^= nums[i];
            } else {
                b2 ^= nums[i];
            }
        }
        return {b1, b2};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = solution.singleNumber(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

/*
Output: 3 5
*/
