// 17. Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> letterCombinations(const string &digits) {
    if (digits.empty()) return {}; // Return early for empty input

    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> res = {""}; // Start with an empty string in the result
    for (char digit : digits) {
        if (mp.find(digit) == mp.end()) continue; // Skip invalid digits like '0' or '1'

        const string &letters = mp[digit]; // Fetch the mapped letters
        vector<string> temp;
        
        // Expand the result list by adding each letter of the current digit to the existing combinations
        for (const string &comb : res) {
            for (char letter : letters) {
                temp.push_back(comb + letter);
            }
        }
        res.swap(temp); // Use swap to avoid unnecessary copying
    }

    return res;
}

int main() {
    string digits;
    cout << "Enter Digit: ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);
    for (const string &comb : combinations) {
        cout << comb << " ";
    }
    cout << endl;

    return 0;
}
