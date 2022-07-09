// 暴力解法-高度
class Solution {
public:
	int maxArea(vector<int>& heights) {
		int ans = 0;
		for (int i = 0; i < heights.size(); ++i) {
			int left = i - 1;
			int right = i + 1;
			while (left >= 0 && heights[left] >= heights[i]) {
				left--;
			}
			while (right < heights.size() && heights[right] >= heights[i]) {
				right++;
			}
			ans = max(ans, (right - left - 1) * heights[i]);
		}
		return ans;
	}
};

// 单调栈 + 哨兵
class Solution {
public:
	int maxArea(vector<int>& heights) {
		int ans = 0;
		stack<int> st;
		// 左右哨兵
        int n = heights.size();
		vector<int> left(n, 0);
		vector<int> right(n, n);
		for (int i = 0; i < heights.size(); ++i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			left[i] = (st.empty() ? -1 : st.top());
			st.push(i);
		}
		
		st = stack<int>();
		for (int i = heights.size() - 1; i >=0; --i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				st.pop();
			}
			right[i] = (st.empty() ? heights.size() : st.top());
			st.push(i);
		}

		for (int i = 0; i < heights.size(); ++i) {
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};

// 单调栈 + 哨兵（改进）
class Solution {
public:
	int maxArea(vector<int>& heights) {
		int ans = 0;
		stack<int> st;
		// 左右哨兵
        int n = heights.size();
		vector<int> left(n, 0);
		vector<int> right(n, n);
		for (int i = 0; i < heights.size(); ++i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				right[st.top()] = i;
				st.pop();
			}

			left[i] = (st.empty() ? -1 : st.top());
			st.push(i);
		}
	
		for (int i = 0; i < heights.size(); ++i) {
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};