#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        if(n==1)
        return nums[0];
        while(st<=end){
            int mid=st+(end-st)/2;
            if(mid==0 && nums[0]!=nums[1])
            return nums[mid];
            if(mid==n-1 && nums[n-1]!=nums[n-2])
            return nums[mid];
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            return nums[mid];
            if(mid%2==0) //even
            {
                if(nums[mid-1]==nums[mid])
                end=mid-1;
                else
                st=mid+1;
            }
            else  //odd
            {
                if(nums[mid-1]==nums[mid])
                st=mid+1;
                else
                end=mid-1;
            }
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    cout << "Single non-duplicate element: " << sol.singleNonDuplicate(nums) << endl;
    return 0;
}
