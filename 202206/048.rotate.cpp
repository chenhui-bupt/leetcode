/*
顺时针旋转90度，本质为先对角翻转，在上下水平翻转 （注意不要重复翻转！！！）
即，mat[i][j] = mat[n - 1 - j][n - 1 - i];
mat[i][j] = mat[n - 1 - i][j];
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};