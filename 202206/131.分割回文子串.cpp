class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

    void dfs(string& s, int i, vector<string>& path, vector<vector<string>>& res) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s.substr(i, j - i + 1))) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, path, res);
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