#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(),matrix.end());
    for(int i=0;i<matrix.size();i++){
        for(int j=i+1;j<matrix[0].size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(auto row: matrix) {
        for(int num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}