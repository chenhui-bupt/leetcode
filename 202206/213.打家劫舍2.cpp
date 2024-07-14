/* https://leetcode.cn/problems/house-robber-ii/description/
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(rob_helper(nums, 0, n - 2), rob_helper(nums, 1, n-1));
    }

    int rob_helper(vector<int>& nums, int start, int end) {
        int dp1 = nums[start];
        int dp2 = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            int tmp = dp2;
            dp2 = max(dp1 + nums[i], dp2);
            dp1 = tmp;
        }
        return dp2;
    }
};