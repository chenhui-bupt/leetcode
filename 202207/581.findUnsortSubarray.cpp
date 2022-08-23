/*
方法：
1、从左往右找出最低的转折点，从右往左找出最高的转折点
2、从左往右找出第一个大于转折点的数，为无序数组的起点；
从右往左找出第一个小于转折点的数，为无序数组的终点。
*/
class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int left = 0;
		int leftVal = INT_MAX;
		int right = nums.size() - 1;
		int rightVal = -INT_MAX;

		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < nums[i-1] && nums[i] < leftVal) {
				left = i;
				leftVal = nums[i];
			}
		}
		for (int i = nums.size() - 2; i >= 0; --i) {
			if (nums[i] > nums[i+1] && nums[i] > rightVal) {
				right = i;
				rightVal = nums[i];
			}
		}

		left = 0;
		while (nums[left] <= leftVal) {
			left++;
		}
		right = nums.size() - 1;
		while (nums[right] >= rightVal) {
			right--;
		}

		return left < right ? right - left + 1 : 0;
	}
};
