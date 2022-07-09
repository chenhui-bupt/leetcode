class Solution {
	int lengthOfLIS(vector<int> nums) {
		vector<int> ans;
		for (int num : nums) {
			if (ans.empty() || num > ans.back()) {
				ans.push_back();
			} else {
				int left = 0;
				int right = ans.size() - 1;
				while (left <= right) {
					int mid = (left + right) >> 1;
					if (ans[mid] < num) {
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				}
				ans[left] = num;
			}
		}
		return len(ans);
	}
}