class Solution {
public:
    void backtrack(int start,int target,int n,vector<int> &combination,vector<vector<int>> &res){
        if(combination.size()==n){
            if(target==0){
                res.push_back(combination);
            }
            return;
        }
        for(int i=start;i<10;i++){
            combination.push_back(i);
            backtrack(i+1,target-i,n,combination,res);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int n, int target) {
        vector<int> combination;
        vector<vector<int>> res;
        backtrack(1,target,n,combination,res);
        return res;
    }
};