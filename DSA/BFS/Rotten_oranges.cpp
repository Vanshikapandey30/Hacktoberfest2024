/*
first contribition to the open sourse community so going start with my favorite thing DSA 
Rooten orages code explainations
Using Breadth-First Search (BFS), the program models the rotting process of oranges in a grid. `0} denotes an empty cell, {1} denotes a fresh orange, and {2} denotes a rotting orange. The grid's dimensions and values are first entered by the user. All rotting oranges are first enqueued, and the BFS algorithm is then used to distribute the rot in four directions—up, down, left, and right—to nearby fresh oranges. Until no more fresh oranges can rot, the procedure is repeated minute by minute. After that, the software gives back the amount of time needed to rot every orange, or {-1} if some can't.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, row = grid.size(), col = grid[0].size();
        queue<pair<int,int>> qu;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 2) qu.push({i, j});
            }
        }
        while(!qu.empty()) {
            bool hasRottened = false;
            int k = qu.size();
            for(int i = 0; i < k; i++) {
                pair<int,int> cor = qu.front();
                qu.pop();
                int x = cor.first, y = cor.second;
                vector<vector<int>> params = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for(auto &it : params) {
                    int newX = x + it[0], newY = y + it[1];
                    if(newX >= 0 && newY >= 0 && newX < row && newY < col && grid[newX][newY] == 1) {
                        hasRottened = true;
                        grid[newX][newY] = 2;
                        qu.push({newX, newY});
                    }
                }
            }
            if(hasRottened) ans++;
        }
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }
    Solution solution;
    cout<< solution.orangesRotting(grid);
    return 0;
}
