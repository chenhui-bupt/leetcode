// 有环链表法
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0;
		int fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}

}


// 修改数组添加标记信息
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			num = nums[i] % nums.size();
			nums[num] += nums.size();
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] >= 2 * nums.size()) {
				return nums[i] % n;
			}
		}
	}

}