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
// 右根左遍历
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        dfs(root, val);
        return root;
    }

    void dfs(TreeNode* root, int& val) {
        if (!root) {
            return;
        }
        dfs(root->right, val);
        root->val += val;
        val = root->val;
        dfs(root->left, val);
    }
};