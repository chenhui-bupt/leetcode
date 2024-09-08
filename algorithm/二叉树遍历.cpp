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
    // 前序遍历
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        while (!st.empty() || root) {
            while (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            root = root->right;
        }
        return res;
    }

    // 中序遍历
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }

    // 后序遍历
    vector<int> inorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        while (!st.empty() || root) {
            while (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->right;
            }

            root = st.top();
            st.pop();
            root = root->left;
        }

        reverse(res.begin(), res.end());
        return res;
    }
}