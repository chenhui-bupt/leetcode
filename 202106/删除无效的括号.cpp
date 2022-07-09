class Solution {
public:
	vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
    	// 统计需要删除的左右括号个数
    	int leftRemove = 0;
    	int rightRemove = 0;
    	for (int i = 0; i < s.length(); ++i) {
    		if (s[i] == '(') {
    			leftRemove++;
    		} else if (s[i] == ')') {
    			if (leftRemove == 0) {
    				rightRemove++;
    			} else if (leftRemove > 0) {
    				leftRemove--;
    			}
    		}
    	}
    	string path = "";
    	dfs(s, 0, 0, leftRemove, rightRemove, path);
    	return ans;
    }

    void dfs(string& s, int index, int leftCount, int rightCount, int leftRemove, int rightRemove, string& path) {
    	if (index == s.length()) {
    		if (leftRemove == 0 && rightRemove == 0) {
    			ans.push_back(path);
    		}
    		return;
    	}

    	// 删除
    	if (leftRemove > 0 && s[index] == '(') {
    		dfs(s, index + 1, leftCount, rightCount, leftRemove - 1, rightRemove, path);
    	}
    	if (rightRemove > 0 && s[index] == ')') {
    		dfs(s, index + 1, leftCount, rightCount, leftRemove, rightRemove - 1, path);
    	}

    	path.push_back(s[index]);
    	// 保留
    	if (s[index] != '(' && s[index] != ')') {
    		dfs(s, index + 1, leftCount, rightCount, leftRemove, rightRemove, path);
    	} else if (s[index] == '(') {
    		dfs(s, index + 1, leftCount + 1, rightCount, leftRemove, rightRemove, path);
    	} else if (s[index] == ')' && leftCount > rightCount) {
    		dfs(s, index + 1, leftCount, rightCount + 1, leftRemove, rightRemove, path);
    	}
    	path.erase(path.length() - 1);
    }
};