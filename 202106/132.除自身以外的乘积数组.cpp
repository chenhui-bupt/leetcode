class Solution {
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> output(nums.size(), 1);
		int r = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			output[i] = r;
			r *= nums[i];
		}
		int r = nums[nums.size() -1];
		for (int i = nums.size() - 2; i >= 0; --i) {
			output[i] *= r;
			r *= nums[i];
		}
}