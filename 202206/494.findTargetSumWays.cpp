/*
目标和
方法：计算数组总和与目标值的差距，就知道有所多少数字前面为负号，于是题目就变成”新的目标和“的问题
*/
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

        target = tsum - target;
        if (target & 1) {
            return 0;
        }

        target = target >> 1;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) { // 为什么不能从小到大遍历？类似416题的分割等和子集
                // 从小到大遍历会将nums[i]重复选择！！！,非要从小到大，那就要二维数组
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};