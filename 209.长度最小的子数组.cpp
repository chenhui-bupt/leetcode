class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 算法一：滑窗
        int n = nums.size();
        int tsum = 0;
        int left = 0;
        int res = n + 1;
        for (int i = 0; i < n; ++i) {
            tsum += nums[i];
            while (tsum >= target) {
                res = min(res, i - left + 1);
                tsum -= nums[left++];
            }
        }
        return res == n + 1 ? 0 : res;

        // 算法二：前缀和 + 二分
        int n = nums.size();
        int res = n + 1;
        vector<int> sums(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            sums[i] = sums[i-1] + nums[i-1];
        }

        for (int i = 0; i < n + 1; ++i) {
            int new_target = sums[i] + target;
            int low = low_bound(sums, new_target);
            res = min(res, low - i);
        }
        return res == n + 1 ? 0 : res;
    }

    int low_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid  - 1;
            }
        }
        return left;
    }
};