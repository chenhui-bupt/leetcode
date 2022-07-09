class Solution {
public:
    int search(vector<int>& nums, int target) {
    	// 思路：二分法，在不同的连续空间中间二分搜索
    	int left = 0;
    	int right = nums.size() - 1;
    	while (left <= right) {
    		int mid = (left + right) >> 1;
    		if (nums[mid] == target) {
    			return mid;
    		}
    		if (nums[left] <= nums[mid]) {
    			if (nums[left] <= target && target < nums[mid]) {  // 边界意识还是不强啊！！！
    				right = mid - 1;
    			} else {
    				left = mid + 1;
    			}
    		} else {
    			if (nums[mid] < target && target <= nums[right]) {
    				left = mid + 1;
    			} else {
    				right = mid - 1;
    			}
    		}
    	}
    	return -1;
    }
};
