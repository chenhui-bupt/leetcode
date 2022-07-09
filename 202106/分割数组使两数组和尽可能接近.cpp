public Solution {
	vector<vector<int>> ans(2);
	int tsum = 0;

	vector<vector<int>> partitionSubsetSum(vector<int> nums) {
		vector<int> comb1;
		vector<int> comb2;
		int target = 0;
		for (int num : nums) {
			target += num;
		}
		target /= 2;

		dfs(nums, comb1, comb2, index, target);
		return ans;
	}

	int calc_sum(vector<int>& nums) {
		int tsum = 0;
		for (int num : nums) {
			tsum += num;
		}
		return tsum;
	}

	void dfs(vector<int> nums, vector<int>& comb1, vector<int>& comb2, int index, int target) {
		if (index == nums.size()) {
			int cur_sum = calc_sum(comb1);
			if (cur_sum - target < abs(tsum - target)) {
				ans[0] = comb1;
				ans[1] = comb2;
				tsum = cur_sum;
			}
			return;
		}

		comb1.push_back(nums[index]);
		dfs(nums, comb1, comb2, index + 1, target);
		comb1.pop_back();
		comb2.push_back(nums[index]);
		dfs(nums, comb1, comb2, index + 1, target);
		comb2.pop_back();
	}
}

