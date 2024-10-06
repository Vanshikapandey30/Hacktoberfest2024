// User function template for C++

class Solution {
  public:
    void solve(vector<vector<int>>& mat,vector<string>&ans,vector<vector<int>>& vis,int x,int y,string move)
    {
        int n=mat.size();
        int m=mat[0].size();
        if(x==n-1 && y==m-1)
        {
            ans.push_back(move);
            return;
        }
        int dx[4] = {1, 0, 0, -1}; // Down, Left, Right, Up
        int dy[4] = {0, -1, 1, 0};
        string dir="DLRU";
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<n && newy<m && mat[newx][newy]==1 && !vis[newx][newy] )
            {
                vis[newx][newy]=1;
                solve(mat,ans,vis,newx,newy,move+dir[i]);
                vis[newx][newy]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(mat[0][0]==1)
        {
            solve(mat,ans,vis,0,0,"");
        }
        return ans;
    }
};
