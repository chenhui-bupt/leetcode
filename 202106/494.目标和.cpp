class Solution {
	int findTargetSumWays(vector<int>& nums, int target) {
		int tsum = 0;
		for (int num : nums) {
			tsum += num;
		}
		
		if (tsum < target) {
			return 0;
		}

		target = tsum - target;
		if (target & 0x01) {
			return 0;
		}
		target = target >> 1;
		vector<vector<int>> dp(nums.size(), vector<int>(target+1, 0));

		for (int i = 0; i < nums.size(); ++i) {
			dp[i][0] = 1;
			for (int j = 1; j <= target; ++j) {
				if (j >= nums[i]) {
					dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
}