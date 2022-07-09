/*
移除无效的括号数
第一步：计算需要删除的左右括号数
第二步：删除括号，并且删除时保证括号有效！（剪枝作用）
*/
class Solution {
public:
    unordered_set<string> st;
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int leftRemove = 0;
        int rightRemove = 0;
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            } else if (c == ')'){
                if (leftRemove == 0) {
                    rightRemove++;
                } else {
                    leftRemove--;
                }
            }
        }

        //cout << "left:" << leftRemove << ", right: " << rightRemove << endl;
        string path = "";
        dfs(s, 0, 0, 0, leftRemove, rightRemove, path);
        for (auto s : st) {
            res.push_back(s);
        }
        return res;
    }

    void dfs(string& s, int i, int leftCount, int rightCount, int leftRemove, int rightRemove, string& path) {
        //cout << "i: " << i << ", lc: " << leftCount << ", rc: " << rightCount << ", lr: " << leftRemove << ", rr: " << rightRemove << endl;
        //cout << path << endl;
        if (i == s.size()) {
            if (leftRemove == 0 && rightRemove == 0) {
                st.insert(path);
            }
            return;
        }

        // 删除
        if (s[i] == '(' && leftRemove > 0) {
            dfs(s, i + 1, leftCount, rightCount, leftRemove - 1, rightRemove, path);
        }

        if (s[i] == ')' && rightRemove > 0) {
            dfs(s, i + 1, leftCount, rightCount, leftRemove, rightRemove - 1, path);
        }

        // 保留
        path.push_back(s[i]);
        if (s[i] != '(' && s[i] != ')') {
            dfs(s, i + 1, leftCount, rightCount, leftRemove, rightRemove, path);
        } else if (s[i] == '(') {
            dfs(s, i + 1, leftCount + 1, rightCount, leftRemove, rightRemove, path);
        } else if (s[i] == ')' && leftCount > rightCount) {
            dfs(s, i + 1, leftCount, rightCount + 1, leftRemove, rightRemove, path);
        }
        path.erase(path.size() - 1);
    }
};