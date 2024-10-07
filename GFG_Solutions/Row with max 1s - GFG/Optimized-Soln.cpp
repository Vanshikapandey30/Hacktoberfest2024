//In it we are using the two pointer approach and the logic is to find the earliest column with 1 present in it  and since the array is sorted the  row tih the earliest column present in it will be the one with the max no of 1's


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int count=0;
	    int row=-1;
        int rind=0;
        int cind=m-1;
        

        while(rind<n && cind>=0){
            
            if(arr[rind][cind]==1){
                row=rind;
                cind--;
                count++;
            }
            else{
                rind++;
            }
            
            
        }
        
        
    return row;    

	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends