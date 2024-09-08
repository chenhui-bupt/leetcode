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
二叉树展开为链表，先序遍历
使用二叉树的前一个节点求解
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* p = nullptr;
        while (root) {
            if (root->left) {
                TreeNode* left = root->left;
                p = root->left;
                while (p->right) {
                    p = p->right;
                }

                p->right = root->right;
                root->right = left;
                root->left = nullptr;
                root = left;
            } else {
                root = root->right;
            }
        }
    }
};