class Solution {
public:
    int longestValidParentheses(string s) {
    	int res = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                ++right;
            }
            if (left == right) {
                res = max(res, right + left);
            } else if (left < right) {
                left = 0;
                right = 0;
            }
        }

        left = right = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++right;
            } else {
                ++left;
            }
            if (left == right) {
                res = max(res, right + left);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return res;
    }

    // 动态规划
    // 只有当s[i] == ')'，才是一个配对结束的地方，然后便可看他递推关系，看他前面有多少组成的pair
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = (i - dp[i - 1] - 2 >= 0) ? (dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]) : (dp[i - 1] + 2);
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    // 栈，通过栈来维护左边界
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop(); // 匹配一个
                if (st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());                    
                }
            }
        }
        return res;        
    }
};