/**
 * 数据结构：二维数组
 * 算法：自身标记法
 * 思路：利用第0行和第0列标记需要置0的行和列，需要注意不要”污染“到第0行和第0列，
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool first_col = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                first_col = true; // 第0列需要置零
            }
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0; // 标记第i行和第j列需要置零
                }
            }
        }

        for (int i = m - 1; i >= 0; --i) { // 从后往前处理避免污染第0行
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; // 置零操作
                }
            }
            if (first_col) { // 第0列置零
                matrix[i][0] = 0;
            }
        }
    }
};