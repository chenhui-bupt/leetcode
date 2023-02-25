/*
典型的动态规划问题
初始时：
dp[0] = 0;
dp[1] = 1;
地推条件：
for (int square : squares) {
    if (square > i) {
        break;
    }
    if (dp[i] = 0) {
        dp[i] = dp[i-square] + 1;
    } else {
        dp[i] = min(dp[i], dp[i - square] + 1);
    }
    
}

*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i <= int(sqrt(n)); ++i) {
            squares.push_back(i * i);
        }

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int square : squares) {
                if (square > i) {
                    break;
                }
                if (dp[i] == 0) {
                    dp[i] = dp[i-square] + 1;
                } else {
                    dp[i] = min(dp[i], dp[i-square] + 1);
                }
            }
        }
        return dp[n];
    }
};