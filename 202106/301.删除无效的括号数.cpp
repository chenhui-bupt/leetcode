class Solution {
public:
	vector<string> ans;
	set<string> ans_set;

	vector<string> removeInvalidParentheses(string s) {
		int leftRemove = 0;
		int rightRemove = 0;
		for (char c : s) {
			if (c == '(') {
				leftRemove++;
			} else if (c == ')') {
				if (leftRemove == 0) {
					rightRemove++;
				} else {
					leftRemove--;
				}
			}
		}

		string path;
		dfs(s, 0, 0, 0, leftRemove, rightRemove, path);
	}

	void dfs(string& s, int index, int leftCount, int rightCount, int leftRemove, int rightRemove, string& path) {
		if (index == s.size()) {
			if (leftRemove == 0 && rightRemove == 0) {
				ans_set.insert(path);
			}
			return;
		}

		// 删除策略
		if (leftRemove > 0 && s[index] == '(') {
			dfs(s, index+1, leftCount, rightCount, leftRemove-1, rightRemove, path);
		}
		if (rightRemove > 0 && s[index] == ')') {
			dfs(s, index+1, leftCount, rightCount, leftRemove, rightRemove-1, path);
		}

		// 保留策略
		path.push(s[index]);
		if (s[index] != '(' && s[index] != ')') {
			dfs(s, index + 1, leftCount, rightCount, leftRemove, rightRemove, path);
		} else if (s[index] == '(') {
			dfs(s, index + 1, leftCount+1, rightCount, leftRemove, rightRemove, path);
		} else if (s[index] == ')' && leftCount > rightCount) {
			dfs(s, index + 1, leftCount, rightCount+1, leftRemove, rightRemove, path);
		}
		path.erase(path.size() - 1);

	}
}


