class Solution {
public:
	int inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode* node = root;
		while (node || !st.empty()) {
			if (node) {
				while (node) {
					st.push(node);
					node = node->left;
				}
			}
			node = st.top();
			res.push_back(node->val);
			st.pop();
			node = node->right;
		}
	}

	inorderTraversal(TreeNode* root) {
		while (root) {
			if (root->left) {
				TreeNode* p = root->left;
				while (p->right && p->right != root) {
					p = p->right;
				}
				if (p->right == nullptr) {
					p->right = root;
					root = root->left;
				} else {
					res.push_back(root->val);
					root = root->right;
				}
			} else {
				res.push_back(root->val);
				root = root->right;
			}
			
		}
	}
}