/**
 * 暴力解法：时间复杂度O(n^2)类比前缀和，根据前缀和寻找target变量的题目，词表根据前缀表，寻找符合target约束的子串。
 * 递归解法：分治思想，时间复杂度O(n*26)字符串s，约束为k，当字符串某个字符c不满足约束k时，那么就需要用字符c把字符串s拆分，然后再重复上述过程。
 */
class Solution {
public:
    // 算法一：暴力解法，O(n^2)
    int longestSubstring(string s, int k) {
        int res = 0;
        int n = s.size();
        vector<vector<int>> prefix(n + 1, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            prefix[i+1] = prefix[i];
            prefix[i+1][s[i] - 'a']++;
            for (int j = 0; j <= i - k + 1; ++j) {
                if (check(prefix[j], prefix[i+1], k)) {
                    res = max(res, i - j + 1);
                }
            }
        }
        return res;
    }

    bool check(vector<int>& pre, vector<int>& cur, int k) {
        for (int i = 0; i < 26; ++i) {
            if (cur[i] - pre[i] > 0 && cur[i] - pre[i] < k) {
                return false;
            }
        }
        return true;
    }

    // 算法二、递归分治
    int longestSubstring(string s, int k) {
        return dfs(s, 0, s.size() - 1, k);
    }

    int dfs(string& s, int left, int right, int k) {
        vector<int> vec(26);
        for (int i = left; i <= right; ++i) {
            vec[s[i] - 'a']++;
        }

        int split = -1;
        for (int i = 0; i < 26; ++i) {
            if (vec[i] > 0 && vec[i] < k) {
                split = i;
                break;
            }
        }

        // 边界条件，子字符串满足k
        if (split == -1) {
            return r - l + 1;
        }

        int res = 0;
        int i = left;
        // 为什么一定要用split把字符串s全部切分完，才能进行下一层的递归，也就是说这里
        // 应该是二叉（split一次）还是多叉（split多次）
        while (i <= right) { 
            while (i <= right && s[i] - 'a' == split) {
                i++;
            }
            if (i > right) {
                break;
            }

            int l2 = i;
            while (i <= right && s[i] - 'a' != split) {
                i++;
            }
            int r2 = i - 1;
            int len = dfs(s, l2, r2, k);
            res = max(res, len);
        }
        return res;
    }
};