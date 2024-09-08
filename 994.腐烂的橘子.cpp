class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }
        int res = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                grid[i][j] = 0;
                if (i > 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push(make_pair(i-1, j));
                }
                if (i < m-1 && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push(make_pair(i+1, j));
                }
                if (j > 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push(make_pair(i, j-1));
                }
                if (j < n-1 && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push(make_pair(i, j+1));
                }
            }
            ++res;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return max(0, res);
    }
};