class Solution {
public:
	int maxRectangle(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		vector<int> heights(n);
		int maxArea = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '1') {
					heights[j]++;
				} else {
					heights[j] = 0;
				}
			}

			vector<int> left(n, -1);
			vector<int> right(n, n);
			stack<int> st;
			for (int j = 0; j < n; ++j) {
				while (!st.empty() && heights[st.top()] >= heights[j]) {
					st.pop();
				}
				left[j] = st.empty() ? -1 : st.top();
				st.push(j);
			}
			
			st = stack<int>();
			for (int j = n-1; j >= 0; --j) {
				while (!st.empty() && heights[st.top()] >= heights[j]) {
					st.pop();
				}

				right[j] = st.empty() ? n : st.top();
			}

			for (int j = 0; j < n; ++j) {
				maxArea = max(maxArea, (right[j] - left[j] - 1) * heights[j]);
			}
		}

		return maxArea;
	}
}