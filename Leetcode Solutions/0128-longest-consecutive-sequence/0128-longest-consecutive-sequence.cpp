class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i : nums) mp[i] = true;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            int count = 0;
            int ele = nums[i];
            while(mp[ele]){
                mp[ele]=false;
                count++;
                ele--;
            }
            ele = nums[i]+1;
            while(mp[ele]){
                mp[ele]=false;
                count++;
                ele++;
            }
            ans = max(count,ans);
        }

        return ans;
    }
};