#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows) {
       int ass = 1;
       int flag = 0;
       if(numRows==1)return s;
       int n = s.size();
       vector<string> haha(numRows);
       for(int i=0;i<n;i++){
            haha[ass-1].push_back(s[i]);
            if(flag==0){
                ass++;
                if(ass>numRows){
                    ass-=2;
                    flag=1;
                }
            }
            else{
                ass--;
                if(ass<1){
                    ass+=2;
                    flag=0;
                }
            }
        }
        string ans{};
        for(int i=0;i<numRows;i++){
            ans+=haha[i];
        } 
        return ans;
    }
int main(){
	string s;
	int n;
	cin >> s;
	cin >> n;
	string ans = convert(s,n);
	cout<<ans<<endl;
}
