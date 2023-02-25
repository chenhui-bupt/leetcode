class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> matrix) {
		vector<int> res;
		if (matrix.empty()) {
			return res;
		}

		int u = 0;
		int d = matrix.size() - 1;
		int l = 0;
		int r = matrix[0].size() - 1;

		while (true) {
			// 向右
			for (int j = l; j <= r; ++j) {
				res.push_back(matrix[u][j]);
			}
			if (++u > d) {
				break;
			}

			// 向下
			for (int i = u; i <= d; ++i) {
				res.push_back(matrix[i][r]);
			}
			if (--r < l) {
				break;
			}

			// 向左
			for (int j = r; j >= l; --j) {
				res.push_back(matrix[d][j]);
			}
			if (--d < u) {
				break;
			}

			// 向上
			for (int i = d; i >= u; --i) {
				res.push_back(matrix[i][l]);
			}
			if (++l > r) {
				break;
			}
		}
		return res;
	}
}