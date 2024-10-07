//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       
       bool isNegative = false;

        if (s1[0] == '-' && s2[0] != '-') {
            isNegative = true;
            s1 = s1.substr(1);
        } else if (s1[0] != '-' && s2[0] == '-') {
            isNegative = true;
            s2 = s2.substr(1);
        } else if (s1[0] == '-' && s2[0] == '-') {
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }

        if (s1 == "0" || s2 == "0")
            return "0";

        vector<int> res(s1.size() + s2.size(), 0);

        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                res[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        int i = 0;
        string ans = "";
        while (i < res.size() && res[i] == 0)
            i++;
        while (i < res.size())
            ans += to_string(res[i++]);

        return isNegative ? "-" + ans : ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends