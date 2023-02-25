/*
买入、卖出、冷冻期
动态规划，dp1为买入，dp2为卖出，dp3为冷冻期(什么也不操作)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        int dp1 = -prices[0]; // 持有一只股票
        int dp2 = 0; // 卖出一只股票
        int dp3 = 0; // 不持有股票
        for (int i = 0; i < n; ++i) {
            int t1 = max(dp1, dp3 - prices[i]);
            int t2 = dp1 + prices[i];
            int t3 = max(dp2, dp3);
            dp1 = t1;
            dp2 = t2;
            dp3 = t3;
        }
        return max(dp2, dp3);
    }
};