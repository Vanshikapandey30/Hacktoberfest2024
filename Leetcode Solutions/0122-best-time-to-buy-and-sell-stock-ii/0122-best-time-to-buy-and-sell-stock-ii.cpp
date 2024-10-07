class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        int buy;
        bool flag=0;


        for(int i=0;i<n-1;i++){
            if(!flag && prices[i]<prices[i+1]){
                buy=prices[i];
                flag=1;
            }

            if(flag && prices[i]>prices[i+1]){
                profit+=prices[i]-buy;
                flag=0;
            }

            if(i==n-2 && flag){
                profit+=prices[i+1]-buy;
            }

        }



        return profit;

    }
};