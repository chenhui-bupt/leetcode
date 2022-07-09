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
前序遍历：根左右
中序遍历：左根右
所以，不断的切分，找出根节点和左右子树就行了
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR) {
        if (preL > preR) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preL]);
        int inRoot = inL;
        while (inRoot <= inR && preorder[preL] != inorder[inRoot]) {
            inRoot++;
        }
        root->left = dfs(preorder, preL + 1, preL + inRoot - inL, inorder, inL, inRoot - 1);
        root->right = dfs(preorder, preL + inRoot - inL + 1, preR, inorder, inRoot + 1, inR);
        return root;
    }
};