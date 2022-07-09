/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vectot<int> res;
    	stack<int> st;
    	TreeNode* node = root;
    	while (!st.empty() || node) {
    		while (node) {
    			st.push(node);
    			node = node->left;
    		}

    		node = st.top();
    		st.pop();
    		res.push_back(node->val);
    		node = node->right;
    	}
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vectot<int> res;
    	TreeNode* p = nullptr;
    	while (root) {
    		if (root->left) {
    			p = root->left;
    			while (p->right && p->right != root) {
    				p = p->right;
    			}

    			if (p->right == nullptr) {
    				p->right = root;
    				root = root->left;
    			} else {
    				res.push_back(root->val);
    				p->right = nullptr;
    				root = root->right;
    			}
    		} else {
    			res.push_back(root->val);
    			root = root->right;
    		}
    	}
    	return res;
    }
};