#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lps(string str) {
        int n = str.size();
        vector<int> lps(n, 0);  // LPS array to store the length of the longest prefix suffix
        int pre = 0;  // Prefix pointer
        int suf = 1;  // Suffix pointer

        // Loop to fill the LPS array
        while (suf < n) {
            if (str[pre] == str[suf]) {
                lps[suf] = pre + 1;  // Update LPS value when prefix matches suffix
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;  // No prefix matches, so LPS is 0
                    suf++;
                } else {
                    pre = lps[pre - 1];  // Move back to the previous longest prefix
                }
            }
        }

        // Return the last value of the LPS array, which is the length of the longest prefix that is also a suffix
        return lps[n - 1];
    }
};

int main() {
    Solution solution;
    
    string str;
    cout << "Enter the string: ";
    cin >> str;

    int result = solution.lps(str);
    cout << "The length of the longest prefix which is also a suffix is: " << result << endl;

    return 0;
}
