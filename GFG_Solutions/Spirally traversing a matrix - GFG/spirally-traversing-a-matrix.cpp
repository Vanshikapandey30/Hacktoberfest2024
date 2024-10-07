//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
      vector <int> ans;
      
      int size=r*c;
      int count=0;
      
      
      int sc=0,sr=0;
      int ec=c-1,er=r-1;
      
      
      
      while(count<size){
          
          
        //first row
        
            for(int i=sc;i<=ec;i++){
                if(count<size){
                    ans.push_back(matrix[sr][i]);
                    count++;
                }
            }
            sr++;
            
        
        
        //Last Col
            
            for(int i=sr;i<=er;i++){
                if(count<size){
                    ans.push_back(matrix[i][ec]);
                    count++;
                }
            }
            ec--;
        
        
        //Last row
        
            
            for(int i=ec;i>=sc;i--){
                if(count<size){
                    ans.push_back(matrix[er][i]);
                    count++;
                }
            }
            er--;
            
        
        
        
        //First col
          
          
            for(int i=er;i>=sr;i--){
                if(count<size){
                    ans.push_back(matrix[i][sc]);
                    count++;
                }
            }
            sc++;
            
    
      }
      
      return ans; 
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends