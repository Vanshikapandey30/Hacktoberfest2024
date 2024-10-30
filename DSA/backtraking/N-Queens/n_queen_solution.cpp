#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<string>> ans;
    int fd = 0, bd = 0, col = 0;
    
    void f(int i, vector<string>& v) {
        if (i == n) {
            ans.push_back(v);
            return;
        }
        for (int j = 0; j < n; ++j) {
            // Check if there's a conflict in the forward diagonal, backward diagonal, or the column
            if (fd & (1 << (i + j)) || bd & (1 << (i + n - 1 - j)) || col & (1 << j)) 
                continue;
            
            // Place the queen and mark the positions
            fd |= 1 << (i + j);
            bd |= 1 << (i + n - 1 - j);
            col |= 1 << j;
            v[i][j] = 'Q';
            
            // Recur to place the next queen
            f(i + 1, v);
            
            // Backtrack and remove the queen
            v[i][j] = '.';
            fd &= ~(1 << (i + j));
            bd &= ~(1 << (i + n - 1 - j));
            col &= ~(1 << j);
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        if (n <= 3) return {}; // No solutions exist for n <= 3 (except n=1)
        
        this->n = n;
        string s(n, '.');
        vector<string> v(n, s);
        
        f(0, v);
        
        return ans;
    }
};

// Function to print the result
void printResult(const vector<vector<string>>& res) {
    for (const auto& board : res) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    
    // Test case input
    int n;
    cout << "Enter the value of n (size of the board): ";
    cin >> n;

    // Solving the N-Queens problem
    vector<vector<string>> result = sol.solveNQueens(n);
    
    // If no solution exists
    if (result.empty()) {
        cout << "No solution exists for n = " << n << endl;
    } else {
        // Printing the results
        printResult(result);
    }

    return 0;
}
