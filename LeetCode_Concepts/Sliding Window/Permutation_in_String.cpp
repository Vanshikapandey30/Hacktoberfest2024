// ** Permutation in String Leetcoe 567
// Given two strings s1 and s2, return true if s2 contains a 
// permutation
//  of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.
// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        vector<int> freq(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1) {
            freq[c - 'a']++;
        }
        int i = 0;
        int j = 0;
        while (j < s2.length()) {
            freq2[s2[j] - 'a']++;

            if (j - i + 1 == s1.length()) {
                if (freq == freq2) {
                    return true;
                }
            }

            if (j - i + 1 < s1.length()) {
                j++;
            } else {
                freq2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

