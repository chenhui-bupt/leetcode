class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 如果mid较大，那么左侧存在峰值，更新right；
            // 如果mid+1较大，那么右侧存在峰值，更新left.
            if (nums[mid] > nums[mid + 1]) {
                right = mid; // 不能减1，会错过峰值
            } else {
                left = mid + 1; // 不是严格大于右边，可以直接mid + 1
            }
        }
        return left; // 这里left = right
    }
};