#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main() {
    vector<int> nums = {2, 2, 3, 2};
    cout << singleNumber(nums) << endl;
    return 0;
}

/*
Output:3
*/
