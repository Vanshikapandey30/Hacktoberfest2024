#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int numSubsets = 1 << n;
    vector<vector<int>> ans;

    for (int num = 0; num < numSubsets; num++) {
        vector<int> list;
        for (int i = 0; i < n; i++) {
            if (num & (1 << i)) {
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (const auto& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
