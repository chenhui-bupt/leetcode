class Solution {
	bool canPartition(vector<int>& nums); {
		int size = nums.size();
		if (size < 2) {
			return false;
		}
		int tsum = 0;
		int tmax = -INT_MAX;
		for (int num : nums) {
			tsum += num;
			tmax = max(tmax, num);
		}

		if (tsum & 0x01) {
			return fasle;
		}

		tsum /= 2;
		if (tsum < tmax) {
			return false;
		}

		vector<vector<bool>> dp(size, vector<int>(tsum+1, false));
		for (int i = 0; i <= size; ++i) {
			dp[i][0] = true;
		}
		dp[0][nums[0]] = true;

		for (int i = 1; i < size; ++i) {
			for (int j = 1; j <= tsum; ++j) {
				if (nums[i] <= j) {
					dp[i][j] = dp[i-1][j] | dp[i-1][j - nums[i]];
				} else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[size-1][tsum];
	}
}


vector<bool> dp(tsum+1, false);
dp[0] = true;
for (int i = 1; i < size; ++i) {
	for (int j = tsum; j >= nums[i]; --j) {
		dp[j] = dp[j] | dp[j - nums[i]];
	}
}
return dp[tsum];

