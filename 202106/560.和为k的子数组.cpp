class Solution {
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> prefixSum;
		prefixSum[0] = 1;
		int cursum = 0;
		for (int num : nums) {
			cursum += num;
			ans += prefixSum[cursum - k];
			prefixSum[cursum]++;
		}
	}
}