/*
方法一：动态规划，时间复杂度O(n^2)
方法二：单调递增栈，剔除栈元素时使用二分查找,O(nlogn)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (res.empty() || nums[i] > res.back()) {
                res.push_back(nums[i]);
            } else {
                int left = 0;
                int right = res.size() - 1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (res[mid] < nums[i]) {
                        left = mid + 1;
                    } else { // res[mid] >= nums[i]; 最左边那个大于等于nums[i]的元素！
                        right = mid - 1;
                    }
                }
                res[left] = nums[i];
            }
        }
        return res.size();
    }
};