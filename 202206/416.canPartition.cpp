/*
分割等和子集，分成两个和相等的子集，是否可以转化成寻找和为sum/2的子集？
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tsum = 0;
        for (int num : nums) {
            tsum += num;
        }
        if (tsum % 2 != 0) {
            return false;
        }

        tsum /= 2;
        vector<bool> dp(tsum + 1);
        dp[0] = true;
        for (int num : nums) { // 一个只能选择一遍，所以在外层遍历
            for (int j = tsum; j >= num; --j) { // 必须要从后往前遍历，否则存在数字被重复选择的问题！！！
                dp[j] |= dp[j-num];
            }

        }
        return dp[tsum];
    }
};