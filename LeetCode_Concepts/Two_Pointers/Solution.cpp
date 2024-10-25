#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height){
        int n = height.size();
        if(n == 0){
            return 0;
        }
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int totalWater = 0;
        // Two-pointer approach to calculate trapped water
        while(left<right){
            if(height[left] < height[right]){
                // Calculate water trapped at the left pointer
                if(height[left] >= leftMax){
                    leftMax = height[left];
                } 
                else{
                    totalWater += leftMax - height[left];
                }
                left++;
            } 
            else{
                // Calculate water trapped at the right pointer
                if(height[right] >= rightMax){
                    rightMax = height[right];
                } 
                else{
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};

int main(){
    Solution solution;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<"Total water trapped: "<<solution.trap(height)<<endl;
    return 0;
}
