// 记忆化搜索
class Solution {
public:

	int maxCoins(vector<int>& nums) {
		vector<vector<int>> rec(nums.size() + 2, vector<int>(nums.size() + 2), -1);
		vector<int> val(nums.size() + 2);

		for (int i = 0; i < nums.size(); ++i) {
			val[i+1] = nums[i];
		}
		val[0] = val[nums.size()+1] = 1;
		return dfs(rec, val, 0, nums.size()+1);
	}

	int dfs(vector<vector<int>>& rec, vector<int>& val, int i, int j) {
		if (i >= j - 1) {
			return 0;
		}

		if (rec[i][j] != -1) {
			return rec[i][j];
		}
		for (int k = i + 1; k < j; ++k) {
			int tmp = val[i] * val[k] * val[j]
			tmp += dfs(rec, val, i, k) + dfs(rec, val, k, j);
			rec[i][j] = max(rec[i][j], tmp);
		}
		return rec[i][j];
	}
}


class Solution {
public:

	int maxCoins(vector<int>& nums) {
		vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2));
		vector<int> val(nums.size() + 2);
		for (int i = 0; i < nums.size(); ++i) {
			val[i+1] = nums[i];
		}
		val[0] = val[nums.size() + 1] = 1;

		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 2; j < n + 2; ++j) {
				for (int k = i + 1; k < j; ++k) {
					int tmp = val[i] * val[k] * val[j];
					tmp += dp[i][k] + dp[k][j];
					dp[i][j] = max(dp[i][j], tmp);
				}
			}
		}
		return dp[0][nums.size() + 1];
	}
}