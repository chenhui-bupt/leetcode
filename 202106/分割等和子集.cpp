class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if (nums.size() < 2) {
    		return false;
    	}

    	int tsum = 0;
    	for (int num : nums) {
    		tsum += num;
    	}

    	if (tsum & 1) {
    		return false;
    	}

    	tsum = tsum / 2;
    	vector<bool> dp(tsum + 1);
    	dp[0] = true;
    	for (int i = 0; i < nums.size(); ++i) {
    		for (int j = tsum; j >= nums[i]; --j) {
    			dp[j] = dp[j] | dp[j - nums[i]];
    		}
    	}
    	return dp[tsum];
    }
};