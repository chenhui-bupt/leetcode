/*
动态规划，这像是一个背包问题，我不能通过全枚举来解决，但可以化整为零，解决最后一次选择哪个硬币，能使次数最小，
那问题自然能转化成 amount - coin的问题，这就是其递推关系式！
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin > i) {
                    break;
                }
                if (dp[i - coin] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i - coin] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                    }
                }
                
            }
        }
        return dp[amount];
    }
};