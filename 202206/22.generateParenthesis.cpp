class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	string s = "";
    	dfs(0, 0, n, s, res);
    	return res;
    }

    void dfs(int left, int right, int n, string s, vector<string>& res) {
    	if (left == n && right == n) {
    		res.push_back(s);
    	}

    	if (left < n) {
    		dfs(left + 1, right, n, s + '(', res);
    	}
    	if (left > right) {
    		dfs(left, right + 1, n, s + ')', res);
    	}
    }
};