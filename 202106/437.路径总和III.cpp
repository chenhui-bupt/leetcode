class Solution {
	int pathSum(TreeNode* root) {
		map<int, int> prefixSum;
		prefixSum[0] = 1;
		return dfs(root, prefixSum, 0, target);
	}

	int dfs(TreeNode* root, map<int, int>& prefixSum, int curSum, int target) {
		if (!root) {
			return;
		}

		int ans = 0;
		curSum += root->val;
		if (prefixSum.find(curSum - target) != prefixSum.end()) {
			ans = prefixSum[curSum - target];
		}
		prefixSum[curSum]++;

		ans += dfs(root->left, prefixSum, curSum, target);
		ans += dfs(root->right, prefixSum, curSum, target);
		prefixSum[curSum]--;
		return ans;
	}
}