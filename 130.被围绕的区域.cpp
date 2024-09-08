/*矩形遍历问题，往往是dfs和bfs，或者栈
思路：先用深度优先遍历，把跟边界联通的’O‘标记成’A'，然后，把'O'改为'X'
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0, j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                dfs(board, i, j);
            }
        }
        for (int i = m - 1, j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                dfs(board, i, j);
            }
        }

        for (int i = 0, j = 0; i < m; ++i) {
            if (board[i][j] == 'O') {
                dfs(board, i, j);
            }
        }
        for (int i = 0, j = n - 1; i < m; ++i) {
            if (board[i][j] == 'O') {
                dfs(board, i, j);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        board[i][j] = 'A';
        if (i + 1 < m && board[i+1][j] == 'O') {
            dfs(board, i + 1, j);
        }
        if (i - 1 >= 0 && board[i-1][j] == 'O') {
            dfs(board, i - 1, j);
        }
        if (j + 1 < n && board[i][j+1] == 'O') {
            dfs(board, i, j + 1);
        }
        if (j - 1 >= 0 && board[i][j-1] == 'O') {
            dfs(board, i, j - 1);
        }
    }
};