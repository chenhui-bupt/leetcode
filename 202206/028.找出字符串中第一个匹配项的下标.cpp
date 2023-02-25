/**
 * 算法一：暴力解法，O(mn)
 * 算法二：KMP字符串匹配算法
 * 思路二：针对原字符串和模式字符串不匹配，原字符串移动下一位的低效，可以利用模式字符串自身
 * 的特点（前后缀的重复性），来跳过无效的匹配，加速字符串匹配过程。
*/
class Solution {
public:
    // 算法一：暴力解法
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

    // 算法二：KMP
    int kmp(string s, string p) {
        vector<int> next(s.size());
        get_next(p, next);

        int i = 0;
        int j = 0;
        while (i < int(s.size()) && j < int(p.size())) {
            if (j == -1 || s[i] == p[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == p.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

    int get_next(string& p, vetor<int>& next) {
        next[0] = -1;
        int i = 0;
        int j = -1;
        while (i < p.size() - 1) {
            if (j == -1 || p[i] == p[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};