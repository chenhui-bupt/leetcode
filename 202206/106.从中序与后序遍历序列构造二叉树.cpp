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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& inorder, int inL, int inR, vector<int>& postorder, int posL, int posR) {
        if (inL > inR) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[posR]);
        int inRoot = inR;
        while (inRoot >= inL && inorder[inRoot] != postorder[posR]) {
            --inRoot;
        }
        root->right = dfs(inorder, inRoot + 1, inR, \
                postorder, posR - (inR - inRoot), posR - 1);
        root->left = dfs(inorder, inL, inRoot - 1, \
                postorder, posL, posL + (inRoot - 1 - inL));
        return root;
    }
};