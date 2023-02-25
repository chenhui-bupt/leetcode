/*
本质上是组合问题，可以使用动态规划或者深度优先遍历或者宽度优先遍历，这题类似单词组合那题，使用动态规划来解
*/
class Solution {
public:
    int numDecodings(string s) {
        vector<string> codes;
        for (int i = 1; i <= 26; ++i) {
            codes.push_back(to_string(i));
        }

        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (string code : codes) {
                int j = i - code.size();
                if (j >= 0 && s.substr(j, code.size()) == code && dp[j] > 0) {
                    dp[i] += dp[j];
                }
            }
        }
        return dp[n];
    }
};