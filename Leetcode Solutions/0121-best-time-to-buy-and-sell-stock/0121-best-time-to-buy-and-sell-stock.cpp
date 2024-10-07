class Solution {
public:
    int maxProfit(vector<int>& prices) {
           int n=prices.size();
            int minval=prices[0];
            int profit=0;

           for(int i=0;i<n;i++){
               profit=max(profit,prices[i]-minval);
                minval=min(minval,prices[i]);
           }

    return profit;

    }
};