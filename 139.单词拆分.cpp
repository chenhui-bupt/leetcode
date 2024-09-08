// dfs算法，会超时，因为有些重复计算的问题！比如到某个字符的时候已经证明了无法完成单词的拆分，往后再拆也没有意义了
// 
/*
那怎么办啊？看答案使用动态规划
起始条件：dp[0] = true;
递推关系式：
if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
    dp[i] = true;
    break;
}
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 动态规划
        vector<bool> dp(s.size() + 1);
        unordered_set<string> st;
        for (string word : wordDict) {
            st.insert(word);
        }
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
        return dfs(s, 0, wordDict);
    }

    bool dfs(string s, int i, vector<string>& wordDict) {
        if (i == s.size()) {
            return true;
        }
        for (string word : wordDict) {
            if (strcmp(word.c_str(), s.substr(i, word.size()).c_str()) == 0) {
                if (dfs(s, i + word.size(), wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
};