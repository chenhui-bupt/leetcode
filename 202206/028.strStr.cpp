class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
        for (int i = 1; i <= l1; ++i) {
            dp[i-1][0] = true;
            for (int j = 1; j <= l2; ++j) {
                if (haystack[i - 1] == needle[j - 1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            if (dp[i][l2]) {
                return i - l2;
            }
        }
        return -1;
    }
};