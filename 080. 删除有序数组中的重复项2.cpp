/**
 * 算法：快慢指针
 * 思路：快指针负责遍历，慢指针负责指向重复不超过两次的数字
 */
class Solution {
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return n; // 无需删除
		}
		int slow = 2;
		int fast = 2;
		while (fast < n) {
			if (nums[slow - 2] != nums[fast]) { // 当fast与上上个数字不一致时，移动赋值
				nums[slow++] = nums[fast];
			}
			fast++; // 待处理的数字
		}
		return slow;
	}
}