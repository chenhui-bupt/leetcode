/**
 * 算法二：贪心
 * 思路二：跳跃的最小次数，一定是几个大区间的”交叠“，也就是说跳跃次数，跟某个边界有关，
 * 虽然可能下次跳跃不是从这次的边界出发（边界前的某一个位置），但他始终是要经过这个边界，
 * 所以，只要统计最佳边界的个数即可
 */
class Solution {
public:
    // 算法一：动态规划，O(n^2)
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] + j >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n-1];
    }

    // 算法二：贪心，O(n)
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumpMax = 0;
        int margin = 0;
        int res = 0;
        for (int i = 0; i < n - 1; ++i) { // 最后一个位置不必访问
            if (jumpMax >= i) { // 前提是，能跳到i处！！！
                jumpMax = max(jumpMax, nums[i] + i);
                if (i == margin) { // 到达一个最佳边界，记录
                    margin = jumpMax; // 更新下一个边界
                    res++;
                }
            }
        }
        return res;
    }
};