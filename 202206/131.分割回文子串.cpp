class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    void dfs(string& s, int index, vector<string>& path, vector<vector<string>>& res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s.substr(index, i - index + 1))) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, path, res);
                path.pop_back();
            }
        }

    }

    bool isPalindrome(string& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};