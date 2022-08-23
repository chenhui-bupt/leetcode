/**
 * 带记忆功能的深度优先遍历dfs
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        vector<vector<int>> lenMat(m, vector<int>(n));
        int maxLen = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curLen = dfs(matrix, visited, i, j, lenMat);
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j,
            vector<vector<int>>& lenMat) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = matrix.size();
        int n = matrix[0].size();
        visited[i][j] = 1;
        int maxLen = 1;
        for (auto dir : dirs) {
            int a = i + dir[0];
            int b = j + dir[1];
            if (a >= 0 && a < m && b >= 0 && b < n && !visited[a][b]
                    && matrix[a][b] > matrix[i][j]) {
                int nextLen = 0;
                if (lenMat[a][b] > 0) {
                    nextLen = lenMat[a][b];
                } else {
                    nextLen = dfs(matrix, visited, a, b, lenMat);
                }
                maxLen = max(maxLen, nextLen + 1);
            }
        }
        visited[i][j] = 0;
        lenMat[i][j] = maxLen;
        return maxLen;
    }
};