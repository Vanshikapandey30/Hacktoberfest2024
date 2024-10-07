//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    unordered_map<char,int>mp;
    int i=0,j=0,ans=INT_MIN;
    for(int j=0;j<s.size();j++){
        mp[s[j]]++;
        if(mp.size()==k)
            ans=max(ans,j-i+1);
        else if(mp.size()>k){
            while(mp.size()!=k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
        }
    }
    return ans==INT_MIN?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends