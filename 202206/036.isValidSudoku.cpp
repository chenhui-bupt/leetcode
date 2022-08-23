class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(); // 9
        vector<vector<int>> row_cnt(n, vector<int>(n));
        vector<vector<int>> col_cnt(n, vector<int>(n));
        vector<vector<vector<int>>> zone_cnt(n/3, vector<vector<int>>(n/3, vector<int>(n)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int idx = board[i][j] - '0' - 1;
                row_cnt[i][idx]++;
                col_cnt[j][idx]++;
                zone_cnt[i / 3][j / 3][idx]++;
                if (row_cnt[i][idx] > 1 || col_cnt[j][idx] > 1 || zone_cnt[i / 3][j / 3][idx] > 1) {
                    return false;
                }
            } 
        }
        return true;
    }
};