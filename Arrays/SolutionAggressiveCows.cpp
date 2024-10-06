#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>& stalls) {
        int start = 1, end, mid, ans;
        // Sort the stalls in increasing order
        sort(stalls.begin(), stalls.end());
        end = stalls[n-1] - stalls[0]; // Maximum possible distance between first and last stall

        while (start <= end) {
            mid = start + (end - start) / 2;  // Calculate the mid distance
            int count = 1, pos = stalls[0];  // Place the first cow in the first stall
            for (int i = 1; i < n; i++) {
                if (pos + mid <= stalls[i]) {  // Place next cow if distance is greater than or equal to mid
                    count++;
                    pos = stalls[i];
                }
            }
            if (count < k) {
                // If we cannot place all k cows, decrease the distance
                end = mid - 1;
            } else {
                // If we can place all cows, increase the distance to check for a larger possible answer
                ans = mid;
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    int n, k;
    cout << "Enter the number of stalls: ";
    cin >> n;
    
    cout << "Enter the number of cows: ";
    cin >> k;
    
    vector<int> stalls(n);
    
    cout << "Enter the positions of the stalls: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    // Solve the problem
    int result = solution.solve(n, k, stalls);
    cout << "The largest minimum distance between any two cows is: " << result << endl;

    return 0;
}
