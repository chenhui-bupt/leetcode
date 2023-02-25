/*
动态规划问题，当然也可以使用“最大矩形面积”题中的单调递增栈来完成，只不过需要加一个限制，即矩形高度和宽度取较小值
起始条件：
if (matrix[i][0] == '1') {
    dp[i][0] = 1;
}
if (matrix[0][j] == '1') {
    dp[0][j] = 1;
}
地推关系式：
if (matrix[i][j] == '1') {
    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
} else {
    dp[i][j] = 0;
}
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                res = 1;
            }
        }

        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                res = 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n ; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                } else {
                    dp[i][j] = 0;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};