/*
dfs递归，求解左右子树的深度
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    vector<int> dfs(TreeNode* root, int& res) {
        if (!root) {
            return {-1, -1};
        }

        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        int l = max(left[0], left[1]) + 1;
        int r = max(right[0], right[1]) + 1;
        res = max(res, l + r);
        return {l, r};
    }
};