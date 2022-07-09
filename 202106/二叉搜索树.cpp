struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
}

class Solution {
public:

	void insert(TreeNode* root, int val) {
		if (!root) {
			return new TreeNode(val);
		}

		if (val < root->val) {
			root->left = insert(root->left, val);
		} else {
			root->right = insert(root->right, val);
		}
		
		return root;
	}

	bool search(TreeNode* root, int val) {
		if (!root) {
			return false;
		}

		if (root->val < val) {
			return search(root->right, val);
		} else if (root->val > val) {
			return search(root->left, val);
		} else {
			return true;
		}
	}

	void delet(TreeNode* root, int val) {
		if (!root) {
			return;
		}

		if (root->val == val) {
			if (!root->left && !root->right) {
				root = nullptr;
			} else if (!root->left) {
				root = root->right;
			} else if (!root->right) {
				root = root->left;
			} else {
				TreeNode* p1 = nullptr;
				TreeNode* p2 = root->left;
				while (p2->right) {
					p1 = p2;
					p2 = p2->right;
				}
				root->val = p2->val;
				if (p1) {
					p1->right = p2->left;
				} else {
					root->left = p2->left;
				}
				
				delete p2;
			}
		} else if (root->val < val) {
			delet(root->right, val);
		} else {
			delet(root->left, val);
		}
	}

private:
	TreeNode* root;
};