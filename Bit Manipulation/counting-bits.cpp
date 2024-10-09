#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}

int main() {
    int n = 5;
    vector<int> result = countBits(n);
    for (int i = 0; i <= n; i++) {
        cout << "Number of 1 bits in " << i << ": " << result[i] << endl;
    }
    return 0;
}

/*
Output:
Number of 1 bits in 0: 0
Number of 1 bits in 1: 1
Number of 1 bits in 2: 1
Number of 1 bits in 3: 2
Number of 1 bits in 4: 1
Number of 1 bits in 5: 2
*/
