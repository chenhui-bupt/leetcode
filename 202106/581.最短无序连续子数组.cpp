class Solution {
	int findUnsortedSubarray(vector<int>& nums) {
		int tmin = nums[0];
		int tmax = nums[nums.size() - 1];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] <= nums[i-1] && nums[i] < tmin) {
				tmin = nums[i];
			}
		}

		for (int i = nums.size() - 2; i >= 0; --i) {
			if (nums[i] >= nums[i+1] && nums[i] > tmax) {
				tmax = nums[i];
			}
		}

		int left = 0;
		int right = nums.size() - 1;
		while (nums[left] <= tmin) {
			left++;
		}

		while (nums[right] >= tmax) {
			right--;
		}
		if (left < right) {
			return right - left + 1;
		} else {
			return 0;
		}
	}
}