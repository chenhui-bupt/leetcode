class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (auto dir : dirs) {
                    int a = i + dir[0];
                    int b = j + dir[1];
                    if (a >= 0 && a < m && b >= 0 && b < n) {
                        if(getOriVal(board[a][b]) == 1) {
                            cnt++;
                        }
                    }
                }
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3)) {
                    board[i][j] = -2;
                } else if (board[i][j] == 0 && cnt == 3) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == -2) {
                    board[i][j] = 0;
                }
            }
        }
    }

    int getOriVal(int val) {
        if (val == 2) { // 复活
            return 0;
        } else if (val == -2) { // 死亡
            return 1;
        } else {
            return val;
        }
    }
};