class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	// 核心思想在于mid是偏左还是偏右！！！！
    	int l = -1;
    	int r = -1;
    	// 二分找左侧
    	int left = 0;
    	int right = nums.size() - 1;
    	while (left <= right) {
    		int mid = (left + right) >> 1;
    		if (nums[mid] >= target) {
    			right = mid - 1;
    		} else {
    			left = mid + 1;
    		}
    	}
    	if (left >= 0 && nums[left] == target) {
    		l = left;
    	}
    	// 二分找右侧
    	left = 0;
    	right = nums.size() - 1;
    	while (left <= right) {
    		int mid = (left + right + 1) >> 1; // 核心思想在于mid是偏左还是偏右
    		if (nums[mid] > target) {
    			right = mid - 1;
    		} else {
    			left = mid + 1;
    		}
    	}
    	if (right < nums.size() && nums[right] == target) {
    		r = right;
    	}
    	return {l, r};
    }
};