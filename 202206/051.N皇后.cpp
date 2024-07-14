class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens(n, -1);
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        dfs(columns, diagonals1, diagonals2, n, 0, queens, res);
        return res;
    }

    void dfs(unordered_set<int>& columns, unordered_set<int>& diagonals1, unordered_set<int>& diagonals2, \
            int n, int i, vector<int>& queens, vector<vector<string>>& res) {
        if (i == n) {
            res.push_back(genRes(queens, n));
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (columns.find(j) != columns.end()) {
                continue;
            }
            
            int diagonal1 = i - j; // 斜线1
            if (diagonals1.find(diagonal1) != diagonals1.end()) {
                continue;
            }

            int diagonal2 = i + j; // 斜线2
            if (diagonals2.find(diagonal2) != diagonals2.end()) {
                continue;
            }

            queens[i] = j;
            columns.insert(j);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            dfs(columns, diagonals1, diagonals2, n, i + 1, queens, res);
            queens[i] = -1;
            columns.erase(j);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }

    vector<string> genRes(vector<int>& queens, int n) {
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            res.push_back(row);
        }
        return res;
    }
};