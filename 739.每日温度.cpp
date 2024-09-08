class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> res(n);
		stack<int> st;

		for (int i = 0; i < n; ++i) {
			if (st.empty() || temperatures[st.top()] > temperatures[i]) {
				st.push(i);
			} else {
				while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
					res[st.top()] = i - st.top();
					st.pop();
				}
				st.push(i);
			}
		}
		return res;
	}
}