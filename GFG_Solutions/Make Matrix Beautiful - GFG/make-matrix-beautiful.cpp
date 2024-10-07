//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findMinOpeartion(vector<vector<int>>& matrix, int n) {
        vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }

        int maxSum = max(*max_element(rowSum.begin(), rowSum.end()), *max_element(colSum.begin(), colSum.end()));

        int count = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            int diff = min(maxSum - rowSum[i], maxSum - colSum[j]);
            matrix[i][j] += diff;
            rowSum[i] += diff;
            colSum[j] += diff;

            count += diff;

            if (rowSum[i] == maxSum) {
                ++i;
            }

            if (colSum[j] == maxSum) {
                ++j;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends