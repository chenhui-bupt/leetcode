class Solution {
	int longestValidParenthes(string& s) {
		int ans = 0;
		int left = right = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				left++;
			} else if (s[i] == ')') {
				right++;
				if (left == right) {
					ans = max(ans, right + left);
				}
			}
		}

		left = 0;
		right = 0;
		for (int i = s.size() - 1; i >= 0; ++i) {
			if (s[i] == '(') {
				if (left == right) {
					ans = max(ans, right + left);
				}
				left++;
			} else if (s[i] == ')') {
				right++;
			}
		}
	}
}

class Solution {
	int longestValidParenthes(string& s) {
		int ans = 0;
		stack<int> st;
		st.push(-1);
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				st.push(i);
			} else if (s[i] == ')') {
				if ()
				if (left == right) {
					ans = max(ans, right + left);
				}
			}
		}

		left = 0;
		right = 0;
		for (int i = s.size() - 1; i >= 0; ++i) {
			if (s[i] == '(') {
				if (left == right) {
					ans = max(ans, right + left);
				}
				left++;
			} else if (s[i] == ')') {
				right++;
			}
		}
	}
}