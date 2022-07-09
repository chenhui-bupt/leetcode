// 寻找重复数（只有一个重复数）
class Solution {
	int findDuplicate(vector<int>& nums) {
		vector<int> ans;
		if (nums.size() < 2) {
			return ans;
		}
		int slow = 0;
		int fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} whiel (slow != fast);

		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
}