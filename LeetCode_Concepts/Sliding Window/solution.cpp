#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        unordered_map<char, int> dictT;
        for (char c : t) {
            dictT[c]++;
        }

        int required = dictT.size();
        int l = 0, r = 0;
        int formed = 0;

        unordered_map<char, int> windowCounts;
        int ans[] = {-1, 0, 0};  // length of substring, left index, right index

        while (r < s.size()) {
            char c = s[r];
            windowCounts[c]++;

            // Check if the current character is a part of `t` and counts match
            if (dictT.count(c) && windowCounts[c] == dictT[c]) {
                formed++;
            }

            // Contract the window
            while (l <= r && formed == required) {
                c = s[l];

                // Save the smallest window
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                windowCounts[c]--;
                if (dictT.count(c) && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                l++;
            }

            r++;
        }

        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};

int main() {
    Solution solution;
    string s, t;

    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    string result = solution.minWindow(s, t);
    cout << "Minimum window substring: " << (result.empty() ? "No valid window" : result) << endl;

    return 0;
}
