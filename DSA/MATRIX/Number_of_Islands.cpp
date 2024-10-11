#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<char>>& M, int r, int c) {
    int ROW = M.size();
    int COL = M[0].size();

    if (r < 0 || c < 0 || r >= ROW || c >= COL || M[r][c] != '1') {
        return;
    }

    M[r][c] = '0';
    vector<int> rNbr = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> cNbr = {0, 0, 1, -1, 1, -1, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int newR = r + rNbr[i];
        int newC = c + cNbr[i];
        DFS(M, newR, newC);
    }
}

int countIslands(vector<vector<char>>& M) {
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            if (M[r][c] == '1') {
                count++;
                DFS(M, r, c);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> M = { { '1', '1', '0', '0', '0' },
                              { '0', '1', '0', '0', '1' },
                              { '1', '0', '0', '1', '1' },
                              { '0', '0', '0', '0', '0' },
                              { '1', '0', '1', '1', '0' } };

    cout << countIslands(M) << endl;
    return 0;
}