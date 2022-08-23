class Solution {
public:
    bool isValid(string s) {
    	// 对称、匹配等问题，使用栈
    	unordered_map<char, char> pair_mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    	stack<char> st;
    	for (char c: s) {
    		if (c == '(' || c == '[' || c == '{') {
    			st.push(c);
    		} else if (!st.empty() && c == pair_mp[st.top()]) {
    			st.pop();
    		} else {
    			return false;
    		}
    	}
    	return st.empty();
    }
};