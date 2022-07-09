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
/*
二叉树dfs算法，每个节点返回偷与不偷的收益
*/

class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob_val = left[1] + right[1] + root->val;
        int unrob_val = max(left[0], left[1]) + max(right[0], right[1]);
        return {rob_val, unrob_val};
    }
};