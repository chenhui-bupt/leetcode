class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && dfs(grid, i, j)) {
                    cout << i << j << endl;
                    ++res;
                }
            }
        }
        return res;
    }

    bool dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
            if (grid[i][j] == 1) {
                return true;
            } else {
                return false;
            }
        }
            
        grid[i][j] = 2;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool valid = true;
        for (auto dir : dirs) {
            int a = i + dir[0];
            int b = j + dir[1];
            if (a < 0 || a >= m || b < 0 || b >= n) {
                continue;
            }
            if (grid[a][b] == 0) {
                valid &= dfs(grid, a, b);
            }
        }
        // grid[i][j] = 0;
        return valid;
    }
};