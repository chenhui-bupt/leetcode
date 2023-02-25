/*
乘积最大连续子数组
动态规划维持一个最大值dp1和一个最小值dp2
初始化：
dp1[0] = nums[0]
dp2[0] = nums[0]
递推关系式
dp1[i] = min(nums[i], nums[i] * dp1[i-1], nums[i] * dp2[i-1])
dp2[i] = max(nums[i], nums[i] * dp1[i-1], nums[i] * dp2[i-1])
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0] = nums[0];
        dp2[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp1[i] = min(min(nums[i], nums[i] * dp1[i-1]), nums[i] * dp2[i-1]);
            dp2[i] = max(max(nums[i], nums[i] * dp1[i-1]), nums[i] * dp2[i-1]);
            res = max(res, dp2[i]);
        }
        return res;
    }
};