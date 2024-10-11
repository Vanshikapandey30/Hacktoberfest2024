#include<bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> left(n, 0);
    vector<int> right(n, n);
    vector<int> height(n, 0);
    int maxArea = 0;

    for (const auto& row : matrix) {
        int curLeft = 0, curRight = n;

        for (int j = 0; j < n; j++) {
            if (row[j] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        for (int j = 0; j < n; j++) {
            if (row[j] == '1') {
                left[j] = max(left[j], curLeft);
            } else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        for (int j = n - 1; j >= 0; j--) {
            if (row[j] == '1') {
                right[j] = min(right[j], curRight);
            } else {
                right[j] = n;
                curRight = j;
            }
        }

        for (int j = 0; j < n; j++) {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix1 = {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'1', '1', '1', '1'},
        {'1', '1', '0', '0'}
    };

    cout << maximalRectangle(matrix1) << endl;

    return 0;
}
