class Solution {
public:
    // 算法一：双指针
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }
        return i == n1;
    }

    // 算法二：动态规划
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n2 + 1, vector<int>(26));
        dp[n2] = vector<int>(26, n2);
        for (int i = n2 - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (j == t[i] - 'a') {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        int idx = 0;
        for (int i = 0; i < n1; ++i) {
            if (dp[idx][s[i] - 'a'] == n2) {
                return false;
            }
            idx = dp[idx][s[i] - 'a'] + 1;
        }
        return true;
    }
};