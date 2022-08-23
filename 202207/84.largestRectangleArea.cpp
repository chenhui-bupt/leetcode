class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		// 单调递增栈 + 数组
		stack<int> st;
		int n = heights.size();
		vector<int> left(n);
		vector<int> right(n, n);

		// 1.左边界
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			left[i] = st.empty() ? -1 : st.top();
			st.push(i);
		}

		// 2.右边界
		st = stack<int>();
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			rights[i] = st.empty() ? n : st.top();
			st.push(i);
		}

		// 3.面积
		int area = 0;
		for (int i = 0; i < n; ++i) {
			area = max(area, (right[i] - left[i] - 1) * heights[i]);
		}
		return area;
	}
};