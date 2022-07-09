/*
递归解不了，动态规划可以
if (matrix[i][j] == 1) {
    dp[i][j][0] = dp[i][j-1][0] + 1;
    dp[i][j][1] = dp[i-1][j][1] + 1;
} else {
    dp[i][j] = {0, 0};
}
int d = min(dp[i-1][j-1][0], dp[i-1][j-1][1]);
d = min(min(dp[i][j][0], dp[i][j][1]), d);
area = max(area, d * d);
好像动态规划也不行啊？
转化成84题中最大矩形面积的题！！
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n);
        for (int i = 0; i < m; ++i) {
            // 以第i行为地平线，计算高度heights
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            vector<int> left(n, 0);
            vector<int> right(n, n);
            stack<int> st;
            for (int j = 0; j < n; ++j) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    right[st.top()] = j;
                    st.pop();
                }
                left[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }

            for (int j = 0; j < n; ++j) {
                res = max(res, (right[j] - left[j] - 1) * heights[j]);
            }
        }
        return res;
    }
};