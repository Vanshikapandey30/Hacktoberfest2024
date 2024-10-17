/*
Problem Statement:
Given n boards of different lengths represented by an array arr of size n, and m painters, you need to determine the minimum amount of time required to paint all the boards. Each painter paints a contiguous segment of boards.

Constraints:

A painter can only paint continuous segments of boards.
Each painter takes the same amount of time to paint a unit length of the board.
You have to minimize the maximum time taken by a painter to paint their assigned boards.

Input:

An integer n representing the number of boards.
An integer m representing the number of painters.
An array arr[] of size n, where each element arr[i] represents the length of the i-th board.
*/

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

bool isPossible(vector<int>&arr, int n, int m, int maxAllowedTime){
  int painter = 1, time = 0;
  for(int i=0; i<n; i++){
    if(time+arr[i]<= maxAllowedTime){
        time += arr[i];
    } else{
        painter++;
        time = arr[i];
        
    }
  }
  return painter<=m;
}
int minTimeToPaint(vector<int> &arr, int n, int m){
    int sum =0, maxVal = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            st = mid+1;
        }

    }
    return ans;
}

int main(){
    vector<int>arr = {40,30,10,20};
    int n = 4, m =2;
    cout<<minTimeToPaint(arr, n, m)<<endl;
    return 0;
}