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
// 方法一：用中序遍历，如果出现逆序则返回false，最后返回true；
// 方法二：递归，左右边界
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int preVal = -INT_MAX;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (!st.empty() || node) {
            while (node) {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            if (node->val < preVal) {
                return false;
            } else {
                preVal = node->val;
            }
            node = node->right;
        }
        return true;
    }

    // 递归
    bool dfs(TreeNode* root, long low, long high) {
        if (!root) {
            return true;
        }
        if (root->val <= low || root->val >= high) {
            return false;
        }
        return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
    }
};