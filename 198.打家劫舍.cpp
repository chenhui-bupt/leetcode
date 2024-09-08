/*
动态规划
记录当前位置偷或不偷的收益
初始条件：
dp1[0] = nums[0]; // 偷
dp2[0] = 0; // 不偷
递推关系式：
dp1[i] = dp2[i-1] + nums[i]; // 偷
dp2[i] = max(dp1[i-1], dp2[i-1]); // 不偷
*/
class Solution {
public:
    // 动态规划
    int rob(vector<int>& nums) {
        int res = nums[0];
        int dp1 = nums[0];
        int dp2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            int tmp = dp2;
            dp2 = max(dp1 + nums[i], dp2);
            dp1 = tmp;
        }
        return dp2;
    }

    // 动态规划
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size() - 1];
    }
};