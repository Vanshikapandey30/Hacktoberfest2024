//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        if(n == 0 || n == 1)return 1;
        
        int mod = 1e9 + 7;
        
        vector<long long>dp(n+2,0);
        dp[0] = dp[1] = 1;
        
        for(int i = 2 ; i <= n ; i++)
        {
           int lo = 0;
           int hi = i-1;
           
           while(lo < hi)
           {
               dp[i] = (dp[i] + (((2*dp[lo])%mod)*(dp[hi]))%mod)%mod;
               dp[i] %= mod;
               
               lo++;    hi--;
           }
           
           if(lo == hi)
           {
               dp[i] = (dp[i] + ((dp[lo])*(dp[hi]))%mod)%mod;
           }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends