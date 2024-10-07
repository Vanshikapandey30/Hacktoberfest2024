// Approach -1 -> BruteForcce, Generating the entire pascal's triangel


// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<vector<int>> ans;

//         for(int i=0;i<=rowIndex;i++){
//             vector<int> temp;
//             for(int j=0;j<=i;j++){
//                 if(j==0 || j==i) temp.push_back(1);
//                 else{
//                     temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
//                 }
//             }
//             ans.push_back(temp);
//         }

//     return ans[rowIndex];
//     }
// };



// Approach -2 -> Using Math


// class Solution {

// private:
//     int nCr(int n, int r){
//         if(r==0 || r==n) return 1;

//         long long res = 1;

//         for(int i=0;i<r;i++){
//             res*=(n-i);
//             res/=(i+1);
//         } 

//         return res;
//     }


// public:
//     vector<int> getRow(int n) {

//         vector<int> ans;

//         for(int r=0;r<=n;r++){
//             ans.push_back(nCr(n,r));
//         }

//         return ans;
//     }
// };



// Approach-3 : Optimal Solution


class Solution {

public:
    vector<int> getRow(int n) {

        vector<int> ans;
        long long ele = 1;

        for(int i=0;i<=n;i++){
            if(i==0 || i==n) ans.push_back(1);
            else{
                ele=(ele*(n-i+1))/i;
                ans.push_back(ele);
            }
        }

        return ans;
    }
};