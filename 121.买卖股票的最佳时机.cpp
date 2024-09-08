/* 交易一次
动态规划：最低点买入，最高点卖出
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int cost = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > cost) { // 高点卖出
                res = max(res, prices[i] - cost);
            }
            
            if (prices[i] < cost) { // 低点买入
                cost = prices[i];
            } 
        }
        return res;
    }
};