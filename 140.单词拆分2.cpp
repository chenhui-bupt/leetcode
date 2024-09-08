class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 动态规划
        int n = s.size();
        vector<vector<string>> dp(n+1, vector<string>());
        unordered_set<string> st;
        for (string word : wordDict) {
            st.insert(word);
        }
        dp[0] = {""};
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (!dp[j].empty() && st.find(s.substr(j, i - j)) != st.end()) {
                    for (string tmp : dp[j]) {
                        if (!tmp.empty()) {
                            dp[i].push_back(tmp + " " + s.substr(j, i - j));
                        } else {
                            dp[i].push_back(s.substr(j, i - j));
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};