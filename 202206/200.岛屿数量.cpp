/*
岛屿数量
用深度优先遍历dfs算法，探寻一个岛屿，为了保证探寻过的岛屿不被继续探寻，可以置标志位
将'1'变成'0'; 结束本次探寻。
继续遍历，搜寻下一个岛屿，记录岛屿数量

你难道只会深度优先吗，宽度优先就不会了？？？？？
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;

                    queue<pair<int, int>> q;
                    q.push(pair<int, int>(i, j));
                    while (!q.empty()) {
                        auto pair = q.front();
                        q.pop();
                        int r = pair.first;
                        int c = pair.second;
                        grid[r][c] = '0';
                        if (r > 0 && grid[r-1][c] == '1') {
                            q.push(pair<int, int>(r-1, c));
                        }
                        if (r < m-1 && grid[r+1][c] == '1') {
                            q.push(pair<int, int>(r+1, c));
                        }
                        if (c > 0 && grid[r][c-1] == '1') {
                            q.push(pair<int, int>(r, c-1));
                        }
                        if (c < n-1 && grid[r][c+1] == '1') {
                            q.push(pair<int, int>(r, c+1));
                        }
                    }
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '0';
        if (i > 0 && grid[i-1][j] == '1') {
            dfs(grid, i - 1, j);
        }
        if (i < m-1 && grid[i+1][j] == '1') {
            dfs(grid, i + 1, j);
        }
        if (j > 0 && grid[i][j-1] == '1') {
            dfs(grid, i, j - 1);
        }
        if (j < n-1 && grid[i][j+1] == '1') {
            dfs(grid, i, j + 1);
        }
    }
};