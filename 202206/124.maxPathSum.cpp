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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    vector<int> dfs(TreeNode* root, int& res) {
        if (!root) {
            return {0, 0};
        }

        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        int L = max(left[0], left[1]) > 0 ? max(left[0], left[1]) + root->val : root->val;
        int R = max(right[0], right[1]) > 0 ? max(right[0], right[1]) + root->val : root->val;
        res = max(res, L + R - root->val);
        return {L, R};
    }
};