/**
 * 方法一：动态规划
 * 定义dp[i][j]为i和j之间能组成的硬币数，可以利用戳气球的等效反向过程，
 * 即在i，j之间放置气球，所以它必然要求迭代也是逆过程，即i，k，j的初始距离为1！
 * 方法二：递归dfs
 * dfs+状态表，但要注意减少重复计算的问题
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> vals(n + 2);
        vals[0] = 1;
        vals[n + 1] = 1;
        for (int i = 0; i < n; ++i) {
            vals[i + 1] = nums[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j < n + 2; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    int tmp = vals[i] * vals[k] * vals[j] + dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], tmp);
                }
            }
        }
        return dp[0][n + 1];
    }
};


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(n+2, vector<int>(n+2, -1));
        vector<int> vals(n+2);

        for (int i = 0; i < nums.size(); ++i) {
            vals[i+1] = nums[i];
        }
        vals[0] = vals[n+1] = 1;
        return dfs(res, vals, 0, n+1);
    }

    int dfs(vector<vector<int>>& res, vector<int>& vals, int i, int j) {
        if (i >= j - 1) {
            return 0;
        }

        if (res[i][j] != -1) {
            return res[i][j];
        }
        for (int k = i + 1; k < j; ++k) {
            int tmp = vals[i] * vals[k] * vals[j] + dfs(res, vals, i, k) + dfs(res, vals, k, j);
            res[i][j] = max(res[i][j], tmp);
        }
        return res[i][j];
    }
};