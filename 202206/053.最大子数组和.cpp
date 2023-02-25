/*
最大连续子数和，当累计”和“为负数时，就应该重新累计，因为过去的已没有意义！
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -INT_MAX;
        int tsum = 0;
        for (int num : nums) {
            if (tsum < 0) {
                tsum = num;
            } else {
                tsum += num;
            }
            res = max(res, tsum);
        }
        return res;
    }
};