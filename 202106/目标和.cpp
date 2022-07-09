class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    	int tsum = 0;
    	for (int num : nums) {
    		tsum += num;
    	}
    	if (tsum < target) {
    		return 0;
    	}

    	int tneg = tsum - target;
    	if (tneg & 1) {
    		return 0;
    	}
    	tneg >> 1;

    	vector<int> dp(tneg + 1);
    	for (int i = 0; i < nums.size(); ++i) {
    		dp[0] = 1;
    		for (int j = tneg; j >= nums[i]; --j) {
    			dp[j] += dp[j - nums[i]];
    		}
    	}
    	return dp[tneg];
    }
};