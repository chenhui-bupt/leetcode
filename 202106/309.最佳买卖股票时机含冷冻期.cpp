// 动态规划
class Solution {
	int maxProfit(vector<int>& prices) {
		int dp1 = -prices[0]; // 买入股票的收益
		int dp2 = 0; // 卖出股票的收益（处于冷冻期）
		int dp3 = 0; // 不持有股票的收益（不处于冷冻期）
		for (int i = 1; i < prices.size(); ++i) {
			int tmp_dp1 = max(dp1, dp3 - prices[i]);
			int tmp_dp2 = dp1 + prices[i];
			int tmp_dp3 = max(dp2, dp3);
			dp1 = tmp_dp1;
			dp2 = tmp_dp2;
			dp3 = tmp_dp3;
		}
		return max(dp2, dp3);
	}
}