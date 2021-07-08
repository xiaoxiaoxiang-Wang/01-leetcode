class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k+1,INT32_MIN);
        vector<int> sell(k+1,0);
        int buyPrev = buy[0];
        for(int i=0;i<prices.size();i++) {
            for(int j=1;j<=k;j++) {
                buyPrev = buy[j];
                buy[j] = max(buy[j],sell[j-1] - prices[i]);
                sell[j] = max(sell[j],buyPrev + prices[i]);
            }
        }
        return *max_element(sell.begin(),sell.end());
    }
};