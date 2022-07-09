class Solution {
	TreeNode* accumulatedTree(TreeNode* root) {

	}

	void dfs(TreeNode* root, int& tsum) {
		if (!root) {
			return;
		}

		// 逆中序遍历
		dfs(root->right, tsum);
		tsum = root->val + tsum;
		root->val = tsum;
		dfs(root->left, tsum);
	}
}