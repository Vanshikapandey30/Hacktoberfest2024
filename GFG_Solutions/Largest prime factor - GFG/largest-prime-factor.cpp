//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public: 
    long long int largestPrimeFactor(int n){
        // code here
        int maxi=INT_MIN;
        for(int i=2;i*i<=n;++i)
        {
            while(n%i==0)
            {
                maxi=max(maxi,i);
                n/=i;
            }
        }
        if(n!=1) maxi=max(maxi,n);
        return maxi;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends