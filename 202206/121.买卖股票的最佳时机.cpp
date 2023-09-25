/* 交易一次
动态规划：最低点买入，最高点卖出
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size() == 0) {
            return 0;
        }
        int cost = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return profit;
    }
};