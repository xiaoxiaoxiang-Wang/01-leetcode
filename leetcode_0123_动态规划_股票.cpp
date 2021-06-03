class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyOne = INT32_MIN;
        int buyTwo = INT32_MIN;
        int sellOne = 0;
        int sellTwo = 0;
        // 每天更新一次四个状态的最优解，最优解可以是任意某天发生的
        for(int i=0;i<prices.size();i++) {
            buyOne = max(buyOne, -prices[i]);
            buyTwo = max(buyTwo,sellOne - prices[i]);
            sellOne = max(sellOne,buyOne + prices[i]);
            sellTwo = max(sellTwo,buyTwo + prices[i]);
        }
        return sellTwo;
    }
};