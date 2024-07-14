/*
dfs搜索问题
边界：起始条件：匹配首字母开始，到达矩形边界结束
其他限制条件：因为字母不能重复使用，需要状态表
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, visited, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& visited, string word, int k) {
        if (k == word.size() - 1 && board[i][j] == word[k]) {
            return true;
        }
        if (board[i][j] != word[k]) {
            return false;
        }
        visited[i][j] = 1;
        bool flag = (i > 0 && !visited[i-1][j] && dfs(board, i - 1, j, visited, word, k + 1))
            || (i < board.size() - 1 && !visited[i+1][j] && dfs(board, i + 1, j, visited, word, k + 1))
            || (j > 0 && !visited[i][j-1] && dfs(board, i, j - 1, visited, word, k + 1))
            || (j < board[0].size() - 1 && !visited[i][j+1] && dfs(board, i, j + 1, visited, word, k + 1));
        visited[i][j] = 0;
        return flag;
    }
};