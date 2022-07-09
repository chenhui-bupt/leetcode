
while (root) {
	if (root->left) {
		TreeNode* left = root->left;
		TreeNode* pre = root->left;
		while (pre->right) {
			pre = pre->right;
		}

		pre->right = root->right;
		root->left = nullptr;
		root->right = left;
		root = left;
	} else {
		root = root->right;
	}
}