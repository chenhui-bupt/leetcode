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

/**
 * 算法一：中序遍历，输出第k个元素
 * 算法二：通过记录以每个节点为根节点的搜索树左右子树节点的个数，这样可以二分查找第k小的数（类似快排查找第k小的数）
 */

class Solution {
public:
    unordered_map<TreeNode*, int> node_num;

public:
    // 算法一：中序遍历
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            // 处理左子树
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            --k;
            if (k == 0) {
                break;
            }

            // 处理右子树
            root = root->right;
        }
        return root->val;
    }

    // 算法二：二叉树各节点的节点数，快排查找思路
    int kthSmallest(TreeNode* root, int k) {
        // 1.预处理，记录节点数
        dfs(root);

        // 2.查找
        TreeNode* node = root;
        while (node) {
            TreeNode* left = node->left;
            int leftNum = left ? node_num[left] : 0;
            if (leftNum < k - 1) { // 需要右子树
                node = node->right;
                k -= (left + 1);
            } else if (leftNum == k - 1) { // 恰好找到
                break;
            } else { // 需要查找左子树
                node = node->left;
            }
        }
        return node->val;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        node_num[root] = 1 + dfs(root->left) + dfs(root->right);
        return node_num[root];
    }
};
