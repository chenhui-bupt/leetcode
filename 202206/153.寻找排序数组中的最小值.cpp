class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) {
                r = mid; // 因为mid可能为最小值，且r = mid，不会陷入死循环
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};